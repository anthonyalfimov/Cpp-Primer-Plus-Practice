//
//  TextInput104.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/09/2018.
//

#include <iostream>

void showTextInput104()
{
    int ch;                 // type int to facilitate EOF constant that is -1
    int count {};
    
    std::cout << "104 | Input characters. Use Ctrl + D on a new line on Mac for simulated EOF.\n";
    while ((ch = std::cin.get()) != EOF)    // test for end-of-file
    {
        std::cout.put(ch);
        ++count;
    }
    std::cout << "\n" << count << " characters read.\n";
}
