#include <iostream>
#include <climits>
using namespace std;

#include "4-ListDSave.h"

ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
 while (length > 0)
 {
  Delete(1);
 }
 delete head;
 delete tail;
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos); 
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::Delete(int pos)
{
 //Pointers to node being deleted, as well as surrounding nodes found
 doubleNode* deletePt = FindPosition(pos + 1);
 doubleNode* prevNode = deletePt->prev;
 doubleNode* nextNode = deletePt->next;

 nextNode->prev = prevNode;
 prevNode->next = nextNode;

 delete deletePt;
 length--;

 deletePt = NULL;
 nextNode = NULL;
 prevNode = NULL;
}

int ListD::DeleteAll(itemType item)
{
 int numDeleted = 0;
 int pos = 1;

 while (pos <= length)
 {
  doubleNode* cur = FindPosition(pos + 1);
  if (cur->item == item)
  {
   Delete(pos);
   numDeleted++;
  }
  else
  {
   pos++;
  }
 }
 return numDeleted;
}

void ListD::PrintForward()
{
 doubleNode* cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::PrintBackward()
{
 doubleNode* cur = tail->prev;

 int i = length;
 while (i > 0)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i--;
 }
}
 
void ListD::Sort()
{
 int start = 1;
 doubleNode* startNode = head->next;

 while (start < length)
 {
  doubleNode* smallest = FindSmall(start, startNode);
  Swap(startNode, smallest);
  start++;
  startNode = startNode->next;
 }
}

doubleNode* ListD::FindSmall(int start, doubleNode* startNode)
{
 doubleNode* smallest = startNode;
 doubleNode* cur = startNode->next;

 int i = start;
 while (i <= length)
 {
  if (cur->item < startNode->item)
  {
   smallest = cur;
  }
  i++;
  cur = cur->next;
 }
 return smallest;
}

void ListD::Swap(doubleNode* startNode, doubleNode* smallest)
{
 int temp = startNode->item;
 startNode->item = smallest->item;
 smallest->item = temp;
}