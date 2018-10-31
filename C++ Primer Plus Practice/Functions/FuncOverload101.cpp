//
//  FuncOverload101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/10/2018.
//

#include <iostream>

namespace FuncOverload101
{
    /**
     Function returns the first ct digits of the number num

     @param num number
     @param ct amount of first digits to return
     @return first ct digits of num
     */
    unsigned long left(unsigned long num, unsigned ct);
    /**
     Function returns a pointer to a new string
     consisting of the first n characters in the str string
     
     @return pointer to a new string
     consisting of the first n characters in the str string
     */
    char * left(const char * str, int n = 1);
}

using namespace FuncOverload101;

void showFuncOverload101()
{
    const char * trip {"Hawaii!!"};
    unsigned long n {12345678L};
    
    char * tmp;             // temporary string storage needed to deallocate it
    
    for (int i = 1; i < 10; i++)    // going up to 9 to test input protection
    {
        std::cout << left(n, i) << "\n";
        tmp = left(trip, i);
        std::cout << tmp << "\n";
        delete [] tmp;      // deallocate created string
        
    }
}

unsigned long FuncOverload101::left(unsigned long num, unsigned ct)
{
    unsigned digits {1};
    unsigned long n {num};
    
    if (ct == 0 || num == 0)
        return 0;           // return 0 if no digits
    
    while (n /= 10)         // while n can still be divided by 10
        digits++;           // increment number of digits
    
    if (digits > ct)
    {
        ct = digits - ct;   // number of digits to remove from the back
        while (ct--)
            num /= 10;
        return num;
    }
    
    return num;             // if ct >= number of digits return num itself
}

char * FuncOverload101::left(const char * str, int n)
{
    if (n < 0) n = 0;
    
        //  Determine the least out of `string length` and `n`
        //  so that we are allocating the minimum required memory
        //  in case `n` is larger than the string length
    
    int len = static_cast<int>(std::strlen(str)) ;
    n = (n < len) ? n : len;        // the lesser out of n and len
    
    char* p = new char[n + 1];
    p[n] = '\0';                    // add null termination
    
    for (int i = 0; i < n; i++)
        p[i] = str[i];
    
    return p;
}
