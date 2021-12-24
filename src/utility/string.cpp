#include "string.h"

int String::DefineSize(const char* str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        {}
    return i;
} 

String::String(const char* str)
{
    size = DefineSize(str);         
    string = new char[size];
    for(int i = 0; i < size; i++) {
        string[i] = str[i];
    }
}

String::String(const String& str)
{
    size = str.size;
    string = new char[size];
    for(int i = 0; i < size; i++) {
        string[i] = str.string[i];
    }
}

void String::Print() const
{
    printf("%s\n", string);
}

bool operator==(const String& str1, const String& str2)
{
    if(str1.size != str2.size) { 
        return false; 
    } 
    for(int i = 0; i < str1.size; i++) { 
        if(str1.string[i] != str2.string[i]) { 
           return false; 
        } 
    } 
    return true; 
}

bool operator<(const String& str1, const String& str2)
{
    int minSize = (str1.size < str2.size) ? str1.size : str2.size;
    for(int i = 0; i < minSize; i++) {
        if(str1.string[i] < str2.string[i])
        { return true; }
        else if(str1.string[i] > str2.string[i])
        { return false; }
    }
    return false;
}

bool operator>(const String& str1, const String& str2)
{
    if(str1 < str2)
    { return false; }
    return true;
}

char String::operator[](int index)
{
    return string[index];
}

const String& String::operator=(const String& str)
{
    size = str.size;  
    //delete string;
    string = new char[size];
    for(int i = 0; i < size; i++) {
        string[i] = str.string[i];
    }
    return *this;
}

String::~String()
{
    delete[] string;
}
