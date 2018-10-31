//
//  FuncString102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/10/2018.
//

#include <iostream>

//  Function prototypes
char* buildString(char symbol, int number);

void showFuncString102()
{
    int times;
    char ch;
    
    std::cout << "Enter a character: ";
    std::cin >> ch;
    
    std::cout << "Enter an integer: ";
    std::cin >> times;
    
    char* p_string {buildString(ch, times)};
    std::cout << p_string << "\n";
    
    delete [] p_string;     // free the memory allocated in buildString call
    
    p_string = buildString('+', 20);    // reuse the pointer
    std::cout << p_string << "-DONE-" << p_string << "\n";
    
    delete [] p_string;     // free memory allocated by the second call
}

char* buildString(char c, int n)
{
    char* p_output = new char[n + 1];   // space for passed number and '\0'
    p_output[n] = '\0';                 // terminate the string
    while (n-- > 0)
        p_output[n] = c;
    return p_output;
}
