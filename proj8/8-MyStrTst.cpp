/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);


 /*
 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay
 */
 /*
 //Test of myStrCopy:
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrCopy*******" << endl;
 cout << "static test" << endl;
 cout << "output should be the word 'newString'" << endl;
 str1.myStrcpy("newString");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 myStrCopy*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the word 'newString'" << endl;
 str2->myStrcpy("newString");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy
 */
 /*
 //Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrLen*******" << endl;
 cout << "static test" << endl;
 cout << "output should be the length of the word: " << endl;
 str1.myDisplay();
 cout << endl;
 cout << str1.myStrlen();
 cout << endl;
 cout << "*****Test 2 myStrLen*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the length of the word: " << endl;
 str2->myDisplay();
 cout << endl;
 cout << str2->myStrlen();
 cout << endl;
 cout << "***************************************" << endl;
//End Test of myStrlen
*/
/*
//Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 1 isEqual*******" << endl;
 cout << "static test" << endl;
 cout << "output should be whether the string ";
 str1.myDisplay();
 cout << " equals 'word'" << endl;
 cout << str1.isEqual("word");
 cout << endl;
 cout << "*****Test 2 isEqual*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be whether the string ";
 str2->myDisplay();
 cout << " equals 'word'" << endl;
 cout << str2->isEqual("word");
 cout << endl;
 cout << "***************************************" << endl;
 cout << "***************************************" << endl;
 cout << "*****Test 3 isEqual*******" << endl;
 cout << "static test" << endl;
 cout << "output should be whether the string ";
 str1.myDisplay();
 cout << " equals 'newString'" << endl;
 cout << str1.isEqual("newString");
 cout << endl;
 cout << "*****Test 4 isEqual*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be whether the string ";
 str2->myDisplay();
 cout << " equals 'newString'" << endl;
 cout << str2->isEqual("newString");
 cout << endl;
 cout << "***************************************" << endl;
//End Test of isEqual
*/
/*
//Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 1 find*******" << endl;
 cout << "static test" << endl;
 cout << "output should be index of ";
 cout << "the beginning of 'Str' in the string, -1 ";
 cout << "if it is not in the string" << endl;
 cout << str1.find("Str");
 cout << endl;
 cout << "*****Test 2 find*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be index of ";
 cout << "the beginning of 'Str' in the string, -1 ";
 cout << "if it is not in the string" << endl;
 cout << str2->find("Str");
 cout << endl;
 cout << "***************************************" << endl;
 cout << "***************************************" << endl;
 cout << "*****Test 3 find*******" << endl;
 cout << "static test" << endl;
 cout << "output should be index of ";
 cout << "the beginning of 'zag' in the string, -1 ";
 cout << "if it is not in the string" << endl;
 cout << str1.find("zag");
 cout << endl;
 cout << "*****Test 4 find*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be index of ";
 cout << "the beginning of 'zag' in the string, -1 ";
 cout << "if it is not in the string" << endl;
 cout << str2->find("zag");
 cout << endl;
 cout << "***************************************" << endl;
//End Test of find
*/
/*
//Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 1 concat*******" << endl;
 cout << "static test" << endl;
 cout << "output should be the string with the ";
 cout << "command line argument attached" << endl;
 str1.concat(argv[1]);
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 concat*******" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the string with the ";
 cout << "command line argument attached" << endl;
 str2->concat(argv[1]);
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
//End Test of concat
*/
 delete str2;
 return 0;  
}
   
  
