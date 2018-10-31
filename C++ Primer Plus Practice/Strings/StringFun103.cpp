//
//  StringFun103.cpp
//  C++ Primer Plus Exercises
//
//  Assigning and concatenating C-style strings
//

#include <iostream>
#include <string>
#include <cstring>

void showStringFun103()
{
    char charr1 [20];
    char charr2 [20] {"jaguar"};
    std::string str1;
    std::string str2 {"panther"};
    
    // assigning for string objects and character arrays
    str1 = str2;
    std::strcpy(charr1, charr2);
    
    // appending for string objects and character arrays
    str1 += " paste";
    std::strcat(charr1, " juice");      // strcat can overrun the available memory in an array!
    
    // finding the length for string objects and character arrays
    int len1 {static_cast<int>( str1.length() )};
    int len2 {static_cast<int>( std::strlen(charr1) )};
    
    std::cout << "The string " << str1 << " contains " << len1 << " characters.\n"
              << "The string " << charr1 << " contains " << len2 << " characters.\n";
}
