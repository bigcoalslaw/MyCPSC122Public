/*
Name: Cole Merrill
Class: CPSC 122-02
Date: January 28, 2022
Assignment Name: Project 3
Description: 
Takes two digit strings and an output file names as command line arguments
Converts the digit strings to variables of type int using atoiMy
Multiplies the newly created int variables and writes their product to the output file name 
*/

#include <iostream>
#include <fstream>
using namespace std;

int atoiMy(char*);

int main(int argc, char* argv[])
{
	ofstream fout;
	
	fout.open(argv[3]);
	
	int num1 = atoiMy(argv[1]);
	int num2 = atoiMy(argv[2]);
	
	fout << num1 * num2;
	
	return 0;
}

/*
Description: Transforms a digit string stored as a c-string to an int.
Input: c-string containing digits
Returns: integer value of the digit string 
*/
int atoiMy(char str[])
{
	int i = 0;
	int num = 0;
	
	while (str[i] != '\0') //increments i through string until 
                               //null terminator is reached
	{
		num = num * 10 + str[i++] - '0';
	}
	return num;
}
