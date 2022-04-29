#include <iostream>
using namespace std;

#include "4-ListDSave.h"

void TestInsert();
void TestCopyConstructor();
void TestPrintBackward();
void TestDelete();
void TestDeleteAll();
void TestSort();

int main()
{
 //TestInsert();
 //TestCopyConstructor();
 //TestPrintBackward();
 //TestDelete();
 //TestDeleteAll();
 TestSort();
}

void TestInsert()
{

 ListD* lst = new ListD;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);
 lst->PrintForward();

 cout << "What's wrong with this test suite?" << endl;
 //answer: we've not tested the tail pointer
 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 delete lst;
}

void TestCopyConstructor()
{
 ListD* lst1 = new ListD;
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD* lst2(lst1);
 
 cout << "Traverse lst1" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse lst2" << endl;
 lst2->PrintForward();


 delete lst1;
 delete lst2;
}

void TestPrintBackward()
{
 ListD* lst1 = new ListD;
 for (int i = 0; i < 5; i++)
  lst1->Insert(i, i + 1);

 cout << "Traverse lst1 backwards" << endl;
 lst1->PrintBackward();

 delete lst1;
}

void TestDelete()
{
 ListD* lst1 = new ListD;
 for (int i = 0; i < 5; i++)
  lst1->Insert(i, i + 1);

 lst1->PrintForward();

 //test delete at head
 lst1->Delete(1);
 cout << "Passed if 0 is no longer in list" << endl;
 lst1->PrintForward();

 //test delete at tail
 lst1->Delete(4);
 cout << "Passed if 4 no longer in list" << endl;
 lst1->PrintForward();

 //test delete in middle
 lst1->Delete(2);
 cout << "Passed if 2 no longer in list" << endl;
 lst1->PrintForward();

 delete lst1;
}

void TestDeleteAll()
{
 ListD* lst1 = new ListD;
 for (int i = 0; i < 10; i++)
  lst1->Insert(i, i + 1);

 lst1->PrintForward();

 //test delete for item in middle
 cout << "Num deleted: " << lst1->DeleteAll(5) << endl;
 cout << "Passed if 5 no longer in list" << endl;
 lst1->PrintForward();

 //test delete for item at head
 cout << "Num deleted: " << lst1->DeleteAll(0) << endl;
 cout << "Passed if 0 no longer in list" << endl;
 lst1->PrintForward();

 //test delete for item at tail
 cout << "Num deleted: " << lst1->DeleteAll(9) << endl;
 cout << "Passed if 9 no longer in list" << endl;
 lst1->PrintForward();

 //test delete for item not in list
 cout << "Num deleted: " << lst1->DeleteAll(10) << endl;
 cout << "Passed if list is the same" << endl;
 lst1->PrintForward();
 cout << endl;

 ListD* lst2 = new ListD;
 for (int i = 0; i < 10; i++)
  lst2->Insert(3, i + 1);
 lst2->Insert(4, 1);
 lst2->PrintForward();

 //test delete for list with multiple of the same item
 cout << "Num deleted: " << lst2->DeleteAll(3) << endl;
 cout << "Passed if list has one item" << endl;
 lst2->PrintForward();

 delete lst1;
 delete lst2;
}

void TestSort()
{
 ListD* lst1 = new ListD;
 for (int i = 0; i < 10; i++)
  lst1->Insert(i, 1);
 lst1->PrintForward();

 //test sort
 lst1->Sort();
 cout << "Passed if list is in ascending order" << endl;
 lst1->PrintForward();

 delete lst1;
}