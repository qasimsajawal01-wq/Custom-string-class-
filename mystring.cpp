#include "mystring.h"
#include <iostream>
#include <cstdlib>

using namespace std;
bool String::isSpace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}
int String::getStringLength(const char *str) // from first file
{
    int length = 0;
    int count = 0;
    while (str[count] != '\0')
    {
        length++;
        count++;
    }

    return length;
}
void String::copyString(char *destination, const char *source)
{
    int lensrc = getStringLength(source);
    for (int i = 0; i < lensrc; i++)
    {
        destination[i] = source[i];
    }

    destination[lensrc] = '\0';
}

String::String() // default constructor
{
    data = nullptr;
    size = 0;
    // cout << "cons called ";
}
String::String(char c)
{
    data = new char[2];
    data[0] = c; // initializes data with char c
    data[1] = '\0';
    size = (c == '\0') ? 0 : 1;
}
String::String(const char *str) // paramterized constructor
{
    if (str == nullptr)
    {
        size = 0;
        data = new char[1];
        data[0] = '\0';
        return;
    }
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    size = len;
    data = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        data[i] = str[i];
    }
    data[size] = '\0';
}
String::String(const String &p) // by reference deep copy
{
    if (p.data == nullptr)
    {
        size = 0;
        data = new char[1];
        data[0] = '\0';
        return;
    }
    size = p.size;

    data = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        data[i] = p.data[i];
    }
    data[size] = '\0';
}
String::~String()
{
    delete[] data;
    data = nullptr;
    // cout << "dest cslled";
}
void String::input()
{
    cout << "Enter the string :";
    char ch[10000];

    cin.getline(ch, 10000);
    if (!cin)
    {
        return;
    }
    size = getStringLength(ch);
    if (data != nullptr)
    {
        delete[] data;
    }

    data = new char[size + 1];
    copyString(data, ch);
}
char &String::at(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "invalid index ";
        exit(1);
    }
    return data[index];
}
bool String::isEmpty()
{
    int i = 0;
    if (data == nullptr || data[i] == '\0')
    {
        return true;
    }
    return false;
}
int String::getLenght() // to get length of string
{
    if (data == nullptr)
    {
        return 0;
    }
    int count = 0;
    while (data[count] != '\0')
    {
        count++;
    }
    return count;
}
int String::getSize()
{
    return size;
}
void String::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
    }
}
int String::find(String subStr, int start = 0)
{
    if (size < 0 || start >= size)
    {
        return -1;
    }
    if (subStr.size == 0)
    {
        return start;
    }

    for (int i = start; i < size - subStr.size; i++)
    {
        for (int j = 0; j < subStr.size && data[i + j] == data[j]; i++)
        {
            if (j = subStr.size)
            {
                return i;
            }
        }
        return -1;
    }
}
void String::insert(int index, String subStr)
{
    if (index < 0 || index > size || subStr.size == 0)
    {
        return;
    }

    int newSize = size + subStr.size;
    char *newData = new char[newSize + 1];

    for (int i = 0; i < index; i++)
    {
        newData[i] = data[i];
    }
    for (int i = 0; i < subStr.size; i++)
    {
        newData[index + i] = subStr.data[i];
    }
    for (int i = index; i < size; i++)
    {
        newData[i + subStr.size] = data[i];
    }
    newData[newSize] = '\0';

    delete[] data;
    data = newData;
    size = newSize;
}
void String::concatEqual(String s2)
{
    if (s2.data = nullptr)
    {
    }
    int len1 = getStringLength(data);
    int len2 = getStringLength(s2.data);

    char *ch = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; i++)
    {
        ch[i] = data[i];
    }
    for (int i = 0; i < len1; i++)
    {
        ch[len1 + i] = s2.data[i];
    }
    ch[len1 + len2] = '\0';
    delete[] data;
    data = ch;
    size = len1 + len2 + 1;
}
String String::concatenate(String s2)
{
    String r;
    r.concatEqual(s2);
    return r;
}
void String::reverse()
{
    if (data[0] == '\0' || size == 0 || size <= 1)
    {
        cout << "0";
        return;
    }

    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        char temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        left++;
        right--;
    }
}

int String::compare(String s2)
{
    int i = 0;
    while (data[i] != '\0' && s2.data[i] != '\0')
    {
        if (data[i] != s2.data[i])
        {
            return data[i] - s2.data[i];
        }
        i++;
    }
    return data[i] - s2.data[i];
}

void String::remove(int index, int count = 1)
{
    int len = getStringLength(data);
    if (index >= len || index < 0 || count <= 0)
    {
        return;
    }
    if (index + count > len)
    {
        count = len - index;
    }
    for (int i = index; i + count <= len; i++)
    {
        data[i] = data[i + count];
    }
}
int String::replace(String old, String newSubStr) // Dry run from here
{
    int oldLen = old.getStringLength(old.data);
    int newLen = newSubStr.getStringLength(newSubStr.data);
    if (oldLen == 0)
        return 0;

    int counter = 0;
    int pos = 0;
    int idx;

    // pehle letter yani string ko find se find krna h
    while ((idx = find(old, pos)) != -1)
    {
        remove(idx, oldLen);
        insert(idx, newSubStr);

        pos = idx + newLen; // jo new text aya hua h us se agay jana h is liye ye use kiya h
        counter++;
    }
    return counter;
}

void String::trimLeft()
{
    int i = 0;
    while (data[i] != '\0' && isSpace(data[i]))
        i++;
    if (i > 0)
        remove(0, i);
}

void String::trimRight()
{
    int end = getStringLength(data) - 1;
    while (end >= 0 && isSpace(data[end]))
        end--;
    data[end + 1] = '\0'; // cut the string here
}
void String::trim()
{
    trimLeft();
    trimRight();
}
void String::makeUpper()
{
    for (int i = 0; data[i] != '\0'; i++)
        if (data[i] >= 'a' && data[i] <= 'z')
            data[i] = data[i] - ('a' - 'A');
}

void String::makeLower()
{
    for (int i = 0; data[i] != '\0'; i++)
        if (data[i] >= 'A' && data[i] <= 'Z')
            data[i] = data[i] + ('a' - 'A');
}

void String::reSize(int newSize)
{
    if (newSize < 1)
        return;

    char *temp = new char[newSize];
    int i = 0;
    while (data[i] != '\0' && i < newSize - 1) // keep room for '\0'
    {
        temp[i] = data[i];
        i++;
    }
    temp[i] = '\0';

    delete[] data;
    data = temp;
    size = newSize;
}

void String::shrink()
{
    reSize(getStringLength(data) + 1); // exactly length + '\0'
}

int String::compare(String s2)
{
    int i = 0;
    while (data[i] != '\0' && data[i] == s2.data[i])
        i++;
    return data[i] - s2.data[i]; // 0 equal, <0 smaller, >0 greater
}

String String::left(int count)
{
    int len = getStringLength(data);
    if (count < 0)
        count = 0;
    if (count > len)
        count = len;

    char *temp = new char[count + 1];
    for (int i = 0; i < count; i++)
        temp[i] = data[i];
    temp[count] = '\0';

    String result(temp);
    delete[] temp;
    return result;
}

String String::right(int count)
{
    int len = getStringLength(data);
    if (count < 0)
        count = 0;
    if (count > len)
        count = len;

    char *temp = new char[count + 1];
    int start = len - count;
    for (int i = 0; i < count; i++)
        temp[i] = data[start + i];
    temp[count] = '\0';

    String result(temp);
    delete[] temp;
    return result;
}

long long int String::convertToInteger()
{
    int i = 0;
    while (data[i] == ' ') // skip leading spaces
        i++;

    bool negative = false;
    if (data[i] == '-' || data[i] == '+')
    {
        negative = (data[i] == '-');
        i++;
    }

    long long int number = 0;
    while (data[i] >= '0' && data[i] <= '9') // stop at first non-digit
    {
        number = number * 10 + (data[i] - '0');
        i++;
    }
    return negative ? -number : number;
}

String String::concatenate(String s2)
{
    int len1 = getStringLength(data);
    int len2 = s2.getStringLength(s2.data);

    char *temp = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; i++)
        temp[i] = data[i];
    for (int i = 0; i < len2; i++)
        temp[len1 + i] = s2.data[i];
    temp[len1 + len2] = '\0';

    String result(temp);
    delete[] temp;
    return result; // original strings are untouched
}

void String::concatEqual(String s2)
{
    int len1 = getStringLength(data);
    int len2 = s2.getStringLength(s2.data);

    if (size < len1 + len2 + 1) // grow only if needed
        reSize(len1 + len2 + 1);

    for (int i = 0; i < len2; i++)
        data[len1 + i] = s2.data[i];
    data[len1 + len2] = '\0';
}

void String::setNumber(const long long int num)
{
    char buffer[25];
    int pos = 24;
    buffer[pos] = '\0';

    // work with a negative value so the smallest long long doesn't overflow
    long long int n = (num > 0) ? -num : num;

    if (n == 0)
        buffer[--pos] = '0';
    while (n != 0)
    {
        buffer[--pos] = '0' - (n % 10); // n%10 is <= 0, so subtract it
        n = n / 10;
    }
    if (num < 0)
        buffer[--pos] = '-';

    delete[] data;
    size = 24 - pos + 1; // digits (and sign) plus '\0'
    data = new char[size];
    copyString(data, buffer + pos);
}
