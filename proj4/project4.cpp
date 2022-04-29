/*
Name: Cole Merrill
Class: CPSC 122 02
Date Submitted: February 4, 2022
Assignment: project4 
Description: Uses the substitution cipher to encrypt/decrypt a file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int keyGen();
char encrypt(char, int);
char decrypt(char, int);
void fileOpen(fstream&, string, char);
void toCipher(fstream&, fstream&, int);
void toPlain(fstream&, fstream&, int);

int main(int argc, char* argv[]) 
{
	fstream fin;
	fstream fout;
	
	int mode = atoi(argv[1]);
	
	if (mode == 0)
	{
		fileOpen(fout, argv[2], 'w');
		fout << keyGen();
		fout.close();
	}
	else
	{
		fileOpen(fin, argv[2], 'r');
		
		int key;
		fin >> key;
		
		fin.close();
		
		fileOpen(fin, argv[3], 'r');
		fileOpen(fout, argv[4], 'w');
		
		if (mode == 1)
		{
			toCipher(fin, fout, key);
		}
		else
		{
			toPlain(fin, fout, key);
		}
		fin.close();
		fout.close();
	}
	return 0;
}

/*
Description: Randomly returns an integer in the range: [1, 25]
Input: none
Output: returns a randomly generated integer in the range [1, 25]
*/
int keyGen()
{
	unsigned seed = time(NULL);
	srand(seed);
	
	int key = rand() % 25 + 1;
	
	return key;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar Cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch 
*/
char encrypt(char ch, int key)
{
	int index = ch - 'A'; //turns character into index in alphabet
	index = (index + key) % 26; //adds key
	char cipher = index + 'A'; //turns back into character
	return cipher;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar Cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
	int index = ch - 'A';
	index = (index - key + 26) % 26; //same as before, only the key
	char plain = index + 'A';        //gets subtracted this time
	return plain;
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name because 'file' is a reference variable 
*/ 
void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Description: Reads through a file, encrypting each of the characters until it reaches the end, outputting the encrypted characters to a new file
Input: File to be read, with characters to be encrypted
Output: No return, designated output file will have newly written encrypted characters
*/
void toCipher(fstream& fileInput, fstream& fileOutput, int key)
{
	while (fileInput.peek() != EOF)
	{
		char ch = fileInput.get();
		if (isalpha(ch)) //goes through each character and encrypts it
		{		 //if alphabetical
			ch = toupper(ch);
			ch = encrypt(ch, key);
		}
		fileOutput << ch;
	}
}

/*
Description: Reads through a file, decrypting each of the characters until it reaches the end, outputting the encrypted characters to a new file
Input: File to be read, with encrypted characters
Output: No return, designated output file will have decrypted characters
*/
void toPlain(fstream& fileInput, fstream& fileOutput, int key)
{
	while (fileInput.peek() != EOF)
	{
		char ch = fileInput.get();
		if (isalpha(ch))
		{
			ch = decrypt(ch, key);
		}
		fileOutput << ch;
	}
}
