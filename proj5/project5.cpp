/*
Name: Cole Merrill
Class: CPSC 122 02
Date Submitted: February 11, 2022
Assignment: project5 
Description: Uses the affine cipher to encrypt/decrypt a file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int INVERSES[] = {0, 0, 0, 9, 0, 21, 0, 15, 0, 3, 0, 19, 0, 0, 0, 7, 0, 23, 0, 11, 0, 5, 0, 17, 0, 25};
int P = 26; //this is the maximum number that needs to be multiplied by 26, 
            //in order for it to be added to decrypt so it does not 
            //return a negative number

void fileControl(string, string, string, int);
void keyGen(string);
char encrypt(char, int, int);
char decrypt(char, int, int);
void fileOpen(fstream&, string, char);
void toCipher(fstream&, fstream&, int, int);
void toPlain(fstream&, fstream&, int, int);

int main(int argc, char* argv[]) 
{
	int mode = atoi(argv[1]);
	
	if (mode == 0)
	{
		keyGen(argv[2]);
	}
	else
	{
		fileControl(argv[2], argv[3], argv[4], mode);
	}
	return 0;
}

/*
Description: invokes fileOpen on all files. Closes all files. Reads key file. Reads the input file and either invokes toCipher or toPlain. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl(string keyFile, string fileIn, string fileOut, int mode)
{
	fstream fin;
	fstream fout;
	
	fileOpen(fin, keyFile, 'r');
		
	int a, b;
	fin >> a;
	fin >> b;
	
	fin.close();
	
	fileOpen(fin, fileIn, 'r');
	fileOpen(fout, fileOut, 'w');
	
	if (mode == 1)
	{
		toCipher(fin, fout, a, b);
	}
	else
	{
		toPlain(fin, fout, a, b);
	}
	fin.close();
	fout.close();
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set: 
{1,3,5,7,9,11,15,17,19,21, 23,25}
The beta value is randomly drawn from the range: [1..25]  
Input: name of file that stores the keys
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen(string keyFile)
{
	fstream fout;
	fileOpen(fout, keyFile, 'w');
	
	unsigned seed = time(NULL);
	srand(seed);
		
	int aValues[] = {3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
	int aIndex = rand() % 11;
	
	seed = time(NULL);
	srand(seed);
	
	int a = aValues[aIndex];
	int b = rand() % 25 + 1;
	
	fout << a << endl;
	fout << b << endl;
	fout.close();
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/
char encrypt(char ch, int alpha, int beta)
{
	int index = ch - 'A'; //turns character into index in alphabet
	index = (alpha * index + beta) % 26; //applies key function
	char cipher = index + 'A'; //turns back into character
	return cipher;
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input character
*/
char decrypt(char ch, int alpha, int beta)
{
	int index = ch - 'A';
	index = (INVERSES[alpha] * index - INVERSES[alpha] * beta + P * 26) % 26;
	char plain = index + 'A';        
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
void toCipher(fstream& fileInput, fstream& fileOutput, int alpha, int beta)
{
	while (fileInput.peek() != EOF)
	{
		char ch = fileInput.get();
		if (isalpha(ch)) //goes through each character and encrypts it
		{		         //if alphabetical
			ch = toupper(ch);
			ch = encrypt(ch, alpha, beta);
		}
		fileOutput << ch;
	}
}

/*
Description: Reads through a file, decrypting each of the characters until it reaches the end, outputting the encrypted characters to a new file
Input: File to be read, with encrypted characters
Output: No return, designated output file will have decrypted characters
*/
void toPlain(fstream& fileInput, fstream& fileOutput, int alpha, int beta)
{
	while (fileInput.peek() != EOF)
	{
		char ch = fileInput.get();
		if (isalpha(ch))
		{
			ch = decrypt(ch, alpha, beta);
		}
		fileOutput << ch;
	}
}
