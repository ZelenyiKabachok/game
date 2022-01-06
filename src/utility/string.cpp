#include "string.h"

unsigned int String::DefineSize(const char* str)
{
    unsigned int i;
    for(i = 0; str[i] != '\0'; i++)
        {}
    return i;
} 

String::String(const char* str)
{
    size = DefineSize(str);         
    string = new char[size+1];
    string[size] = '\0';
    for(unsigned int i = 0; i < size; i++) {
        string[i] = str[i];
    }
}

String::String(char str)
{
    size = 1; 
    string = new char[size];
    string[0] = str;
}

String::String(const String& str)
{
    size = str.size;
    string = new char[size];
    for(unsigned int i = 0; i < size; i++) {
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
    for(unsigned int i = 0; i < str1.size; i++) { 
        if(str1.string[i] != str2.string[i]) { 
           return false; 
        } 
    } 
    return true; 
}

bool operator<(const String& str1, const String& str2)
{
    unsigned int minSize = (str1.size < str2.size) ? str1.size : str2.size;
    for(unsigned int i = 0; i < minSize; i++) {
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

unsigned int String::Size()
{ return size; }

const char* String::GetPointer()
{ return string; }

const String& String::operator=(const String& str)
{
    size = str.size;  
    //delete string;
    string = new char[size];
    for(unsigned int i = 0; i < size; i++) {
        string[i] = str.string[i];
    }
    return *this;
}

String::~String()
{
    delete[] string;
}
