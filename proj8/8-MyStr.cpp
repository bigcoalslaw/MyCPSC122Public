#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
    length = strlen(strIn);
    str = new char[length + 1];
    myStrcpy(strIn);

}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
    delete []str; 
    cout << "string deleted" << endl;
}

void MyString::myStrcpy(char const* strIn) 
{
    int i = 0;
    while (strIn[i] != '\0')
    {
        str[i] = strIn[i];
        i++;
    }
    str[i] = '\0';
    length = i;
}

int MyString::myStrlen() 
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void MyString::myDisplay()
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
}

bool MyString::isEqual(char const* strIn)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != strIn[i])
        {
            return false;
        }
        i++;
    }
    if (strIn[i] != '\0')
    {
        return false;
    }
    return true;
}

int MyString::find(char const* strIn)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == strIn[0])
        {
            if (isSub(strIn, i))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

bool MyString::isSub(char const* strIn, int idx)
{
    int i = 0;
    while (strIn[i] != '\0')
    {
        if (strIn[i] != str[idx])
        {
            return false;
        }
        i++;
        idx++;
    }
    return true;
}

void MyString::concat(char const* strIn)
{
    int lengthTemp = length;
    length = length + strlen(strIn);
    int i = lengthTemp;
    int j = 0;
    while (i < length)
    {
        str[i] = strIn[j];
        i++;
        j++;
    }
}
