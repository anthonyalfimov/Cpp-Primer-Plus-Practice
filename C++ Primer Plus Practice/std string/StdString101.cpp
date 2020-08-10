//
//  StdString101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include <string>

void showStdString101()
{
    std::string alpha ("Lottery Winner!");      // ctor: string (const char* s)
    std::cout << alpha << "\n";
    
    std::string beta (20, '$');                 // ctor: string (size_type count, char c)
    std::cout << beta << "\n";
    
    std::string gamma (alpha);                  // ctor: string (const string& str)
    std::cout << gamma << "\n";
    
    alpha += " Oops!";                          // overloaded +=
    std::cout << alpha << "\n";
    
    beta = "Sorry! That was ";                  // overloaded =
    gamma[0] = 'P';                             // overloaded []
    
    std::string delta;                          // ctor: string()
    delta = beta + gamma;                       // overloaded +, =
    std::cout << delta << "\n";
    
    char cstr[] {"All's well that ends well"};
    
    std::string epsilon (cstr, 20);             // ctor: string (const char* s, size_type count)
    std::cout << epsilon << "!\n";
    
    std::string zeta (cstr + 6, cstr + 10);     // ctor: template<class Iter>
                                                //          string (Iter first, Iter last)
                                                // NB! array name decays to a pointer here
    std::cout << zeta << ", ";
    
    std::string eta (&epsilon[6], &epsilon[10]);    // same ctor as above
    std::cout << eta << "...\n";
    
    std::string theta (delta, 7, 16);           // ctor: string (const string& str, size_type pos,
                                                //               size_type count = npos)
    std::cout << theta << " in motion!\n";
    
    std::cout << "\nDone.\n";
}

