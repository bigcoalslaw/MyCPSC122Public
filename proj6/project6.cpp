/*
Name: Cole Merrill
Class: CPSC 122 Section 02
Date Submitted: February 18, 2022
Assignment: project6
Description: Uses the transposition cipher to encrypt/decrypt a file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ALPHABET_SIZE = 26;

void keyGen(string);
void fileControl(string, string, string, int);
void fileTransform(fstream&, fstream&, int[]);
char transform(char, int[]);
void fileOpen(fstream&, string, char);
void mysSort(int[][2], int);
bool sink(int[][2], int);
void swap(int[][2], int, int);
void initializeBoolArray(bool[], int);
void initializeAscending(int[][2], int);
void copyArray(int[][2], int[], int, int);
void disp2DArray(int[][2], int);
void dispArray(int[], int);

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
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen(string keyFile)
{
    fstream fout;
    fileOpen(fout, keyFile, 'w');

    unsigned seed = time(NULL);
    srand(seed);
    int len = ALPHABET_SIZE;
    bool used[len];
    initializeBoolArray(used, len);

    int pos = 0;
    while (pos < len)
    {
        int num = rand() % len;
        if (!used[num])
        {
            fout << num << endl;
            used[num] = true;
            pos++;
        }
    }
    fout.close();
}

/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs  arrays for encryption and decryption.  The decryption array is sorted as explained above.  Use the function, MysterySort, described below to do the sorting.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl(string keyFile, string fileIn, string fileOut, int mode)
{
    fstream fin;
    fstream fout;

    int len = ALPHABET_SIZE;

    fileOpen(fin, keyFile, 'r');

    int plainAndKey[len][2];
    initializeAscending(plainAndKey, len); //initializes the first column with
                                           //ascending numbers
    for (int i = 0; i < len; i++) //initializes the ssecond column with
    {                             //encryption key
        int num;
        fin >> num;
        plainAndKey[i][1] = num;
    }

    int encKey[len];
    int decKey[len];

    copyArray(plainAndKey, encKey, len, 1); //copies elements of second column
                                            //to encKey
    mysSort(plainAndKey, len);

    copyArray(plainAndKey, decKey, len, 0); //copies elements of first column
                                            //to decKey
    fin.close();

    fileOpen(fin, fileIn, 'r');
    fileOpen(fout, fileOut, 'w');

    if (mode == 1)
    {
        fileTransform(fin, fout, encKey);
    }
    else
    {
        fileTransform(fin, fout, decKey);
    }
}

/*
Description: Reads through input file and encrypts character if it is alphabetical using either the encrypt array or the decrypt array.
Input: file stream to be read, file stream to be written to, encrypt or decrypt array.
Output: No return, writes to file.
*/
void fileTransform(fstream& fin, fstream& fout, int encDec[])
{
    while (fin.peek() != EOF)
    {
        char ch = fin.get();
        if (isalpha(ch))
        {
            ch = toupper(ch);
            ch = transform(ch, encDec);
        }
        fout << ch;
    }
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
    int index = ch - 'A';
    int newIndex = encDec[index];
    ch = newIndex + 'A';
    return ch;
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
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
Description: Algorithm to sort the key array. Invoked within fileControl
Input: 26 position 2-D array, K, of integers with columns 0 and 1
Output: an array k’, where col 0 is the sorted version of col 1.   The original column 1 is taken along for the ride.  See the sorting instructions above. 
*/
void mysSort(int array[][2], int len)
{
    bool shift = true;
    int bottom = len - 1;
    while (shift)
    {
        shift = sink(array, bottom);
        bottom--;
    }
}

/*
Description: Increments through an array, swaping values if the one is greater than one below it. This causes the largest value to get moved to the defined bottom.
Input: Array to be sorted, defined bottom.
Output: No return, shifts elements in an array.
*/
bool sink(int array[][2], int bottom)
{
    bool shift = false;
    int cur = 0;
    while (cur < bottom)
    {
        if (array[cur][1] > array[cur + 1][1])
        {
            shift = true;
            swap(array, cur, 0);
            swap(array, cur, 1);
		cur++;
        }
        else 
	  {
            cur++;
        }
    }
    return shift;
}

/*
Description: Given an element in an array, the function swaps the element with the next element.
Input: 2D Array to be altered, current index (cur), particular column of the array to alter.
Output: No returnn, alters array.
*/
void swap(int array[][2], int cur, int col)
{
    int temp = array[cur][col];
    array[cur][col] = array[cur + 1][col];
    array[cur + 1][col] = temp;
}

/*
Description: Sets all of the elements of the boolean array to false.
Input: Boolean array, length
Output: No return, alters elements of array
*/
void initializeBoolArray(bool array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = false;
    }
}
/*
Description: Increments through each element of an array, chaning all of the elements into ascending order starting from zero and ending at the length of the array.
Input: 2D Array to be altered (has 2 columns)
Output: No return, alters elements of array
*/
void initializeAscending(int array[][2], int len)
{
    for (int i = 0; i < len; i++) 
    {
        array[i][0] = i;
    }
}

/*
Description: Copies all of the elements of a particular column in a 2D array over to a 1D array.
Input: 2D array with two columns, 1D array, length, column
Returns: No return, alters elements of the 1D array
*/
void copyArray(int array2d[][2], int array1d[], int len, int col)
{
    for (int i = 0; i < len; i++)
    {
        array1d[i] = array2d[i][col];
    }
}

/*
Description: Displays the elements of a 2D array.
Input: 2D array with 2 columns, length (number of rows)
Output: Elements of array are outputted to terminal
*/
void disp2DArray(int array[][2], int len)
{
    cout << "Column 1:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << array[i][0] << endl;
    }
    cout << "Column 2:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << array[i][1] << endl;
    }

}

/*
Description: Displays the elements of a 1D array.
Input: 1D array, length
Output: Elements of array are outputted to terminal
*/
void dispArray(int array[], int len)
{
    cout << "Array: " << endl;
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << endl;
    }
}