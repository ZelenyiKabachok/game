#ifndef STRING_H
#define STRIGN_H

class String {

    char* string;
    int size;

    int DefineSize(const char* str);

public:

    String() {}

    String(const char* str);

    String(const String& str);

    const String& operator=(const String& str);

    friend bool operator==(const String& str1, const String& str2);

    friend bool operator<(const String& str1, const String& str2); 

    friend bool operator>(const String& str1, const String& str2);

    char operator[](int index);

    ~String();

};

#endif
