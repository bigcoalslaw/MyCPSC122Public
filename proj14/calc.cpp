#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
 int length = strlen(argvIn);
 inFix = new char[length + 1];
 strcpy(inFix, argvIn);
 if (!CheckTokens())
 {
  cout << "Error: Unexpected character found in input" << endl;
  exit(EXIT_FAILURE);
 }
 Parse();
 stk = new Stack;
 if (!CheckParens())
 {
  cout << "Error: Parentheses need to be balanced" << endl;
  exit(EXIT_FAILURE);
 }
 InFixToPostFix();
}

Calc::~Calc()
{
 delete inFix;
 delete valueTbl;
 delete stk;
}

bool Calc::CheckTokens()
{
 int i = 0;
 while (inFix[i] != '\0')
 {
  char ch = inFix[i];
  if ((!isalpha(ch)) && (!isdigit(ch)) && ch != '(' && ch != ')' && ch != '*' && ch != '/' && ch != '+' && ch != '-' && ch)
  {
   return false;
  }
  i++;
 }
 return true;
}

void Calc::MakeValueTbl()
{
 valueIdx = 0;
 valueTbl = new int[26];
 for (int i = 0; i < 26; i++)
 {
  valueTbl[i] = 0;
 }
}

void Calc::Parse()
{
 MakeValueTbl();
 int length = strlen(inFix);
 char* temp = new char[length + 1];

 int i = 0;
 int j = 0;

 while (inFix[i] != '\0')
 {
  if (inFix[i] == '(' || inFix[i] == ')' || inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/' || (isalpha(inFix[i]) && isupper(inFix[i])))
  {
   temp[j] = inFix[i];
  }
  else
  {
   int last = FindLast(i);
   int valLength = last - i + 2;
   char* val = new char[valLength];
   val[valLength - 1] = '\0';

   int k = 0;
   while (k < valLength - 1)
   {
    val[k] = inFix[i + k];
    k++;
   }

   valueTbl[valueIdx] = atoi(val);
   temp[j] = (char)('A' + valueIdx);
   valueIdx++;
   i = last;
   delete val;
  }
  i++;
  j++;
 }
 temp[j] = '\0';
 int tempLength = j + 1;
 delete inFix;
 inFix = new char[tempLength];
 int count = 0;
 while (temp[count] != '\0')
 {
  inFix[count] = temp[count];
  count++;
 }
 inFix[count] = '\0';
 delete temp;
}

int Calc::FindLast(int cur)
{
 int i = cur;
 while (isdigit(inFix[i]))
 {
  i++;
 }
 return i - 1;
}

bool Calc::CheckParens()
{
 int i = 0;
 if (inFix[i] != '(')
 {
  return false;
 }
 while (inFix[i] != '\0')
 {
  if (inFix[i] == '(')
  {
   stk->Push(inFix[i]);
  }
  else if (inFix[i] == ')')
  {
   stk->Pop();
  }
  i++;
 }
 return stk->IsEmpty();
}

void Calc::DisplayInFix()
{
 int i = 0;
 while (inFix[i] != '\0')
 {
  cout << inFix[i];
  i++;
 }
 cout << endl;
}

void Calc::InFixToPostFix()
{
 int length = strlen(inFix);
 postFix = new char[length + 1]; 
 int i = 0;
 int j = 0;
 while (inFix[i] != '\0')
 {
  if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/')
  {
   stk->Push(inFix[i]);
  }
  else if (isalpha(inFix[i]))
  {
   postFix[j] = inFix[i];
   j++;
  }
  else if (inFix[i] == '(')
  {
   stk->Push(inFix[i]);
  }
  else if (inFix[i] == ')')
  {
   while (stk->Peek() != '(')
   {
    postFix[j] = stk->Peek();
    j++;
    stk->Pop();
   }
   stk->Pop();
  }
  i++;
 }
 postFix[j] = '\0';
}

void Calc::DisplayPostFix()
{
 int i = 0;
 while (postFix[i] != '\0')
 {
  cout << postFix[i];
  i++;
 }
 cout << endl;
}

int Calc::Evaluate()
{
 int result = 0;
 int i = 0;
 while (postFix[i] != '\0')
 {
  char ch = postFix[i];
  if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
  {
   int op1;
   int op2;
   if (stk->Peek() != result)
   {
    op2 = valueTbl[(stk->Peek() - 'A')];
   }
   else
   {
    op2 = result;
   }
   stk->Pop();
   if (stk->Peek() != result)
   {
    op1 = valueTbl[(stk->Peek() - 'A')];
   }
   else
   {
    op1 = result;
   }
   if (ch == '+')
   {
    result = op1 + op2;
   }
   else if (ch == '-')
   {
    result = op1 - op2;
   }
   else if (ch == '*')
   {
    result = op1 * op2;
   }
   else if (ch == '/')
   {
    result = op1 / op2;
   }
   stk->Pop();
   stk->Push(result);
  }
  else
  {
   stk->Push(ch);
  }
  i++;
 }
 return result;
}
