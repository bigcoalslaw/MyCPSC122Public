#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
 length = 0;
 head = NULL;
 tail = NULL;
}

ListT::~ListT()
{
 while (length > 0)
 {
  DeleteItemH();
 }
}

bool ListT::IsEmpty() const
{
 return length == 0;
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(const itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = head;

 head = tmp; 
 if (length == 0)
  tail = tmp;  
 length++;
 tmp = NULL;
}

itemType ListT::GetItemH() const
{
 return head->item;
}

void ListT::DeleteItemH()
{
 node* temp = head;
 head = head->next;
 delete temp;
 temp = NULL;
 length--;
 if (length == 0)
 {
  tail = NULL;
 }
}

void ListT::PutItemT(const itemType itemIn)
{
 node* temp = new node;
 temp->item = itemIn;
 temp->next = NULL;
 tail = temp;
 if (length == 0)
 {
  head = temp;
 }
 else if (length == 1)
 {
  head->next = temp;
 }
 else
 {
  node* temp2 = PtrToAny(length - 1);
  temp2->next = tail;
  temp2 = NULL;
 }
 temp = NULL;
 length++;
}

itemType ListT::GetItemT() const
{
 return tail->item;
}

void ListT::DeleteItemT()
{
 node* temp = tail;
 if (length == 1)
 {
  delete temp;
  length--;
  tail = NULL;
  head = NULL;
  temp = NULL;
 }
 else
 {
  node* prev = PtrTo();
  prev->next = temp->next;
  tail = prev;
  delete temp;
  temp = NULL;
  prev = NULL;
  length--;
 }
}

void ListT::Print() const
{
 node* cur = head;
 while(cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

int ListT::FindItem(const itemType target) const
{
 int i = 0;
 node* cur = head;
 while (cur != NULL)
 {
  if (cur->item == target)
  {
   i++;
  }
  cur = cur->next;
 }
 return i;
}

int ListT::DeleteItem(const itemType target)
{
 int i = 0;
 int pos = 0;
 node* cur = head;
 while (cur != NULL)
 {
  if (cur->item == target)
  {
   i++;
   if (pos == 0) //three cases
   {
    DeleteItemH();
    cur = head;
   }
   else if (pos == length - 1) //at tail
   {
    DeleteItemT();
    cur = tail;
   }
   else //somewhere in between
   {
    DeleteItemHelper(pos);
    cur = PtrToAny(pos);
   }
  }
  else //only do this when a node is not deleted
  {
   cur = cur->next;
   pos++; 
  }
 }
 return i;
}

void ListT::DeleteItemHelper(int pos) //does not work at head or tail
{
 node* prev = PtrToAny(pos - 1);
 node* cur = prev->next;
 node* post = cur->next;
 prev->next = post;
 delete cur;
 cur = NULL;
 prev = NULL;
 post = NULL;
 length--;
}

node* ListT::PtrTo()
{
 node* cur = head;
 int nodeNum = 0;
 while (nodeNum < length - 2)
 {
  cur = cur->next;
  nodeNum++;
 }
 return cur;
}

node* ListT::PtrToAny(int pos)
{
 node* cur = head;
 int i = 0;
 while (i < pos)
 {
  cur = cur->next;
  i++;
 }
 return cur;
}