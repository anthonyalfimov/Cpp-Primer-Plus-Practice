//
//  PrivateInheritance101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Student02.hpp"

const int pupils = 3;
const int quizzes = 5;

namespace
{
    void set(Inheritance400::Student& s, int scoresCount);
}

void showPrivateInheritance101()
{
    using Inheritance400::Student;
    
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
    void set(Inheritance400::Student& s, int scoresCount)
    {
        std::cout << "Please enter the student's name: ";
        getline(std::cin, s);
        std::cout << "Please enter " << scoresCount << " quiz scores:\n";
        
        for (int i = 0; i < scoresCount; i++)
            std::cin >> s[i];
        
        while(std::cin.get() != '\n')
            continue;
    }
}
