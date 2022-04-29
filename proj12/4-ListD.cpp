#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
 InitializeVars();
}

template <typename T>
ListD<T>::ListD(ListD<T>* lst)
{
 InitializeVars();
 //returns pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
void ListD<T>::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = 0;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = 0;
 tail->next = NULL;
}

//how would you do this?
template <typename T>
ListD<T>::~ListD()
{
 while (length > 0)
 {
  Delete(1);
 }
 delete head;
 delete tail;
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
template <typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::Delete(int pos)
{
 //Pointers to node being deleted, as well as surrounding nodes found
 doubleNode<T>* deletePt = FindPosition(pos + 1);
 doubleNode<T>* prevNode = deletePt->prev;
 doubleNode<T>* nextNode = deletePt->next;

 nextNode->prev = prevNode;
 prevNode->next = nextNode;

 delete deletePt;
 length--;

 deletePt = NULL;
 nextNode = NULL;
 prevNode = NULL;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
 int numDeleted = 0;
 int pos = 1;

 while (pos <= length)
 {
  doubleNode<T>* cur = FindPosition(pos + 1);
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

template <typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>* cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}
 
template <typename T>
void ListD<T>::PrintBackward()
{
 doubleNode<T>* cur = tail->prev;

 int i = length;
 while (i > 0)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i--;
 }
}

template <typename T>
void ListD<T>::Sort()
{
 int start = 1;
 doubleNode<T>* startNode = head->next;

 while (start < length)
 {
  doubleNode<T>* smallest = FindSmall(start, startNode);
  Swap(startNode, smallest);
  start++;
  startNode = startNode->next;
 }
}

template <typename T>
doubleNode<T>* ListD<T>::FindSmall(int start, doubleNode<T>* startNode)
{
 doubleNode<T>* smallest = startNode;
 doubleNode<T>* cur = startNode->next;

 int i = start;
 while (i < length) //does not include dummy nodes
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

template <typename T>
void ListD<T>::Swap(doubleNode<T>* startNode, doubleNode<T>* smallest)
{
 int temp = startNode->item;
 startNode->item = smallest->item;
 smallest->item = temp;
}