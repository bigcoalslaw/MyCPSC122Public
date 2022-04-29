#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
 //Static list 
 ListT lst;
 for (int i = 0; i < 5; i++) //fill list at head
   lst.PutItemH(i);
 cout << "list 1: " << endl;
 lst.Print(); //display test
 cout << "length: " << lst.GetLength() << endl;
 cout << "is empty: " << lst.IsEmpty() << endl;
 cout << "item at head of list: " << lst.GetItemH() << endl;
 cout << "item at tail of list: " << lst.GetItemT() << endl;
 cout << endl;

 lst.DeleteItemH();
 lst.DeleteItemT();

 cout << "list 1: " << endl;
 lst.Print(); //display test
 cout << "length: " << lst.GetLength() << endl;
 cout << "is empty: " << lst.IsEmpty() << endl;
 cout << "item at head of list: " << lst.GetItemH() << endl;
 cout << "item at tail of list: " << lst.GetItemT() << endl;
 cout << endl;

 lst.DeleteItemT();
 lst.DeleteItemT();

 cout << "list 1: " << endl;
 lst.Print(); //display test
 cout << "length: " << lst.GetLength() << endl;
 cout << "is empty: " << lst.IsEmpty() << endl;
 cout << "item at head of list: " << lst.GetItemH() << endl;
 cout << "item at tail of list: " << lst.GetItemT() << endl;
 cout << endl;

 lst.DeleteItemT();

 cout << "list 1: " << endl;
 lst.Print(); //display test
 cout << "length: " << lst.GetLength() << endl;
 cout << "is empty: " << lst.IsEmpty() << endl;
 cout << endl;

 ListT lst3;
 for (int i = 0; i < 5; i++) //fill list at tail
   lst3.PutItemT(i);
 cout << "list 2: " << endl;
 lst3.Print(); //display test
 cout << "length: " << lst3.GetLength() << endl;
 cout << "is empty: " << lst3.IsEmpty() << endl;
 cout << "item at head of list: " << lst3.GetItemH() << endl;
 cout << "item at tail of list: " << lst3.GetItemT() << endl;
 cout << "num items equal to 2: " << lst3.FindItem(2) << endl;
 cout << endl;

 cout << "attempting to delete all 2's, num deleted: " << lst3.DeleteItem(2) << endl;
 cout << endl;

 cout << "list 2: " << endl;
 lst3.Print(); //display test
 cout << "length: " << lst3.GetLength() << endl;
 cout << "is empty: " << lst3.IsEmpty() << endl;
 cout << "item at head of list: " << lst3.GetItemH() << endl;
 cout << "item at tail of list: " << lst3.GetItemT() << endl;
 cout << "num items equal to 2: " << lst3.FindItem(2) << endl;
 cout << endl;

 cout << "attempting to delete all 4's, num deleted: " << lst3.DeleteItem(4) << endl;
 cout << endl;

 cout << "list 2: " << endl;
 lst3.Print(); //display test
 cout << "length: " << lst3.GetLength() << endl;
 cout << "is empty: " << lst3.IsEmpty() << endl;
 cout << "item at head of list: " << lst3.GetItemH() << endl;
 cout << "item at tail of list: " << lst3.GetItemT() << endl;
 cout << "num items equal to 2: " << lst3.FindItem(2) << endl;
 cout << endl;

 cout << "attempting to delete all 0's, num deleted: " << lst3.DeleteItem(0) << endl;
 cout << endl;

 cout << "list 2: " << endl;
 lst3.Print(); //display test
 cout << "length: " << lst3.GetLength() << endl;
 cout << "is empty: " << lst3.IsEmpty() << endl;
 cout << "item at head of list: " << lst3.GetItemH() << endl;
 cout << "item at tail of list: " << lst3.GetItemT() << endl;
 cout << "num items equal to 2: " << lst3.FindItem(2) << endl;
 cout << endl;

 //Dynamic list
 ListT* lst2 = new ListT;
 for (int i = 0; i < 5; i++) //fill list at head
   lst2->PutItemH(i*10);
 cout << "list 3: " << endl;
 lst2->Print(); //display test
 cout << "length: " << lst2->GetLength() << endl;
 cout << "is empty: " << lst2->IsEmpty() << endl;
 cout << "item at head of list: " << lst2->GetItemH() << endl;
 cout << "item at tail of list: " << lst2->GetItemT() << endl;
 cout << endl;

 lst2->DeleteItemH();
 lst2->DeleteItemT();

 cout << "list 3: " << endl;
 lst2->Print(); //display test
 cout << "length: " << lst2->GetLength() << endl;
 cout << "is empty: " << lst2->IsEmpty() << endl;
 cout << "item at head of list: " << lst2->GetItemH() << endl;
 cout << "item at tail of list: " << lst2->GetItemT() << endl;
 cout << endl;

 lst2->DeleteItemT();
 lst2->DeleteItemT();

 cout << "list 3: " << endl;
 lst2->Print(); //display test
 cout << "length: " << lst2->GetLength() << endl;
 cout << "is empty: " << lst2->IsEmpty() << endl;
 cout << "item at head of list: " << lst2->GetItemH() << endl;
 cout << "item at tail of list: " << lst2->GetItemT() << endl;
 cout << endl;

 cout << "attempting to delete all 30's, num deleted: " << lst2->DeleteItem(30) << endl;
 cout << endl;

 cout << "list 3: " << endl;
 lst2->Print(); //display test
 cout << "length: " << lst2->GetLength() << endl;
 cout << "is empty: " << lst2->IsEmpty() << endl;
 cout << endl;

 ListT* lst4 = new ListT;
 for (int i = 0; i < 5; i++) //fill list at tail
   lst4->PutItemT(i*10);
 cout << "list 4: " << endl;
 lst4->Print(); //display test
 cout << "length: " << lst4->GetLength() << endl;
 cout << "is empty: " << lst4->IsEmpty() << endl;
 cout << "item at head of list: " << lst4->GetItemH() << endl;
 cout << "item at tail of list: " << lst4->GetItemT() << endl;
 cout << "num items equal to 2: " << lst4->FindItem(2) << endl;
 cout << endl;

 cout << "attempting to delete all 2's, num deleted: " << lst4->DeleteItem(2) << endl;
 cout << endl;

 cout << "list 4: " << endl;
 lst4->Print(); //display test
 cout << "length: " << lst4->GetLength() << endl;
 cout << "is empty: " << lst4->IsEmpty() << endl;
 cout << "item at head of list: " << lst4->GetItemH() << endl;
 cout << "item at tail of list: " << lst4->GetItemT() << endl;
 cout << "num items equal to 2: " << lst4->FindItem(2) << endl;
 cout << endl;

 delete lst2;
 delete lst4;
 return 0;
}
