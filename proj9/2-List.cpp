#include <iostream>
using namespace std;

#include "2-List.h"


//Class-related functions
//Constructor
List::List()
{       
    length = 0;
    head = NULL;
}

//Destructor
List::~List()
{
    while (length > 0)
    {
        DeleteItemH();
    }
}

//Head-related functions
void List::PutItemH(itemType item)
{
    node* temp = new node;
    temp->item = item;
    temp->next = head;
    head = temp;
    temp = NULL;
    length++;
}

itemType List::GetItemH() const
{
    return head->item;
}

void List::DeleteItemH()
{
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    length--;
}


//General operations on the class

void List::Print() const
{
    node* cur = head;
    while (cur != NULL)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}

bool List::IsEmpty() const
{
    return length == 0;
}

int List::GetLength() const
{
    return length;
}

int List::Find(const itemType target) const
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

int List::DeleteItem(const itemType target)
{
    int i = 0;
    int pos = 0;
    node* cur = head;
    while (cur != NULL)
    {
        if (cur->item == target)
        {
            i++;
            if (pos == 0) //two cases
            {
                DeleteItemH();
                cur = head;
            }
            else
            {
                DeleteItemHelper(pos);
                cur = ptrTo(pos);
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

void List::DeleteItemHelper(int pos) //this works even at end of list
{
    node* prev = ptrTo(pos - 1);
    node* cur = prev->next;
    node* post = cur->next;
    prev->next = post;
    delete cur;
    cur = NULL;
    prev = NULL;
    post = NULL;
    length--;
}

node* List::ptrTo(int pos)
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
