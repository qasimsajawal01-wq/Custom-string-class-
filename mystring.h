#ifndef MYSTRING_H
#define MYSTRING_H

class String
{

private:
    char *data;
    int size;

public:

    bool isSpace(char c);
    int getStringLength(const char *str);
    void copyString(char *destination, const char *source);
    String(const String &);
    String();
    String(char c);
    String(const char *);
    ~String();
    void input();
    char &at(int index);
    bool isEmpty();
    int getLenght();
    int getSize();
    void display();
    int find(String, int);
    void insert(int index, String subStr);
    void reverse();
    void remove(int index, int count = 1);
    int replace(String old, String newSubStr);
    void trimLeft();
    void trimRight();
    void trim();
    void makeUpper();
    void makeLower();
    void reSize(int);
    void shrink();
    int compare(String s2);
    String left(int count);
    String right(int count);
    long long int convertToInteger();
    String concatenate(String s2);
    void concatEqual(String s2);
    void setNumber(const long long int num);
};
#endif
