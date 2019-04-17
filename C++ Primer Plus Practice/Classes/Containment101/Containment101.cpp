//
//  Containment101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Student01.hpp"

const int pupils = 3;
const int quizzes = 5;

namespace
{
    void set(Containment100::Student& s, int scoresCount);
}

void showContainment101()
{
    using Containment100::Student;
    
    Student ada[pupils]
    {
        Student(quizzes), Student(quizzes), Student(quizzes)
    };
    
    int i;
    
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);
    
    std::cout << "\nStudent List:\n";
    
    for (i = 0; i < pupils; i++)
        std::cout << ada[i].name() << "\n";
    
    std::cout << "\nResults:";
    
    for (i = 0; i < pupils; i++)
    {
        std::cout << "\n" << ada[i];
        std::cout << "average: " << ada[i].average() << "\n";
    }
    
    std::cout << "Done.\n";
}

namespace
{
    void set(Containment100::Student& s, int scoresCount)
    {
        std::cout << "Please enter the student's name: ";
        getline(std::cin, s);           // declaration inside the namespace body is required to
                                        //     enable name lookup, i.e. Containment100::getline()
                                        // friend function is visible via argument-dependent lookup
                                        //     as it is included in the class declaration
        
                                        /*  7.3.1.2/3 (of ISO/IEC 14882:2011):
                                           "If a friend function is called, its name may be found
                                            by the name lookup that considers functions from
                                            namespaces and classes associated with the types of the
                                            function arguments"
                                         */
        std::cout << "Please enter " << scoresCount << " quiz scores:\n";
        
        for (int i = 0; i < scoresCount; i++)
            std::cin >> s[i];
        
        while(std::cin.get() != '\n')
            continue;
    }
}

