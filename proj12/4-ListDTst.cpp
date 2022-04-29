#include <iostream>
using namespace std;

#include "4-ListD.cpp"

void TestInsert();
void TestCopyConstructor();
void TestPrintBackward();
void TestDelete();
void TestDeleteAll();
void TestSort();

int main() //lists with both ints and chars tested
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

 ListD<int>* lst = new ListD<int>;
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

 ListD<char>* lst2 = new ListD<char>;
 for (int i = 1; i <= 5; i++)
  lst2->Insert('A' + i,i);
 lst2->PrintForward();

 cout << "What's wrong with this test suite?" << endl;
 //answer: we've not tested the tail pointer
 //test general case insert
 cout << "Passed Insert Test 1 if B through F appear on subsequent lines" << endl;
 lst2->PrintForward();
 cout << endl;

 //test insert at the head
 lst2->Insert('A',1);
 cout << "Passed Insert Test 2 if A appears in position 1" << endl; 
 lst2->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst2->Insert('G',7);
 cout << "Passed Insert Test 3 if G appears in final position" << endl; 
 lst2->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst2->Insert('H',5);
 cout << "Passed Insert Test 4 if H appears in middle position" << endl; 
 lst2->PrintForward();
 cout << endl;
 delete lst2;
}

void TestCopyConstructor()
{
 ListD<int>* lst1 = new ListD<int>;
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD<int>* lst2(lst1);
 
 cout << "Traverse lst1" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse lst2" << endl;
 lst2->PrintForward();


 delete lst1;
 delete lst2;

 ListD<char>* lst3 = new ListD<char>;
 for (int i = 1; i <= 3; i++)
  lst3->Insert(i + 'A',i);

 ListD<char>* lst4(lst3);
 
 cout << "Traverse lst3" << endl;
 lst3->PrintForward();
 cout << endl;
 cout << "Traverse lst4" << endl;
 lst4->PrintForward();


 delete lst3;
 delete lst4;
}

void TestPrintBackward()
{
 ListD<int>* lst1 = new ListD<int>;
 for (int i = 0; i < 5; i++)
  lst1->Insert(i, i + 1);

 cout << "Traverse lst1 backwards" << endl;
 lst1->PrintBackward();

 delete lst1;

 ListD<char>* lst2 = new ListD<char>;
 for (int i = 0; i < 5; i++)
  lst2->Insert('A' + i, i + 1);

 cout << "Traverse lst2 backwards" << endl;
 lst2->PrintBackward();

 delete lst2;
}

void TestDelete()
{
 ListD<int>* lst1 = new ListD<int>;
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

 ListD<char>* lst2 = new ListD<char>;
 for (int i = 0; i < 5; i++)
  lst2->Insert('A' + i, i + 1);

 lst2->PrintForward();

 //test delete at head
 lst2->Delete(1);
 cout << "Passed if A is no longer in list" << endl;
 lst2->PrintForward();

 //test delete at tail
 lst2->Delete(4);
 cout << "Passed if E no longer in list" << endl;
 lst2->PrintForward();

 //test delete in middle
 lst2->Delete(2);
 cout << "Passed if C no longer in list" << endl;
 lst2->PrintForward();

 delete lst2;
}

void TestDeleteAll()
{
 ListD<int>* lst1 = new ListD<int>;
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

 ListD<int>* lst2 = new ListD<int>;
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

 cout << endl;

 ListD<char>* lst3 = new ListD<char>;
 for (int i = 0; i < 10; i++)
  lst3->Insert(i + 'A', i + 1);

 lst3->PrintForward();

 //test delete for item in middle
 cout << "Num deleted: " << lst3->DeleteAll('F') << endl;
 cout << "Passed if F no longer in list" << endl;
 lst3->PrintForward();

 //test delete for item at head
 cout << "Num deleted: " << lst3->DeleteAll('A') << endl;
 cout << "Passed if A no longer in list" << endl;
 lst3->PrintForward();

 //test delete for item at tail
 cout << "Num deleted: " << lst3->DeleteAll('J') << endl;
 cout << "Passed if J no longer in list" << endl;
 lst3->PrintForward();

 //test delete for item not in list
 cout << "Num deleted: " << lst3->DeleteAll('K') << endl;
 cout << "Passed if list is the same" << endl;
 lst3->PrintForward();
 cout << endl;

 ListD<char>* lst4 = new ListD<char>;
 for (int i = 0; i < 10; i++)
  lst4->Insert('D', i + 1);
 lst4->Insert('E', 1);
 lst4->PrintForward();

 //test delete for list with multiple of the same item
 cout << "Num deleted: " << lst4->DeleteAll('D') << endl;
 cout << "Passed if list has one item" << endl;
 lst4->PrintForward();

 delete lst3;
 delete lst4;
}

void TestSort()
{
 ListD<int>* lst1 = new ListD<int>;
 for (int i = 0; i < 10; i++)
  lst1->Insert(i, 1);
 lst1->PrintForward();

 //test sort
 lst1->Sort();
 cout << "Passed if list is in ascending order" << endl;
 lst1->PrintForward();

 delete lst1;

 cout << endl;

 ListD<char>* lst2 = new ListD<char>;
 for (int i = 0; i < 10; i++)
  lst2->Insert(i + 'A', 1);
 lst2->PrintForward();

 //test sort
 lst2->Sort();
 cout << "Passed if list is in ascending order" << endl;
 lst2->PrintForward();

 delete lst2;
}