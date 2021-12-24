#ifndef STRING_H
#define STRIGN_H

#include <cstdlib>
#include <cstdio>

class String {

    char* string = NULL;
    int size = 0;

    int DefineSize(const char* str);

public:

    String() {}

    String(const char* str);

    String(const String& str);

    void Print() const;

    const String& operator=(const String& str);

    friend bool operator==(const String& str1, const String& str2);

    friend bool operator<(const String& str1, const String& str2); 

    friend bool operator>(const String& str1, const String& str2);

    char operator[](int index);

    ~String();

};

#endif
