//
//  CommaOperator101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 20/08/2018.
//

#include <iostream>
#include <string>

void showCommaOperator101()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;
    
    // modify the string object itself
    // note: string class provides a more concise method to reverse a string
    
    {   // create a block to limit the scope of temp
        // without allocating it in each iteration of the loop
        
        char temp;
        for (int j = 0, i = static_cast<int>(word.length()) - 1;
                                // declaration with initialization
             j < i;
             --i, ++j)          // use of comma operator
        {
            temp = word[i];
            word[i] = word[j];
            word[j] = temp;
        }
    }
    std::cout << word << "\nDone!\n";
}
