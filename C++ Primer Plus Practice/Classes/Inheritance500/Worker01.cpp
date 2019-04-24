//
//  Worker01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 24/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Worker01.hpp"

namespace Inheritance501
{
//  Worker methods
    
    Worker::~Worker() {}                        // must implement virtual destructor, even if pure
    
    void Worker::set()
    {
        std::cout << "Enter worker's name: ";
        std::getline(std::cin, m_fullName);
        
        std::cout << "Enter worker's id: ";
        std::cin >> m_id;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
    void Worker::show() const
    {
        std::cout
            << "Name: " << m_fullName << "\n"
            << "Employee ID: " << m_id << "\n";
    }
    
//  Waiter methods
    
    void Waiter::set()
    {
        Worker::set();
        std::cout << "Enter waiter's panache rating: ";
        std::cin >> m_panache;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
    void Waiter::show() const
    {
        std::cout << "Category: waiter\n";
        Worker::show();
        std::cout << "Panache rating: " << m_panache << "\n";
    }
    
//  Singer methods
    
    const char* Singer::s_voiceLabels[] =
    {
        "other", "alto", "contralto", "soprano",
        "bass", "baritone", "tenor"
    };
    
    void Singer::set()
    {
        Worker::set();
        
        std::cout << "Enter number for singer's vocal range:\n";
        int i;
        
        for (i = 0; i < c_voiceTypes; i++)
        {
            std::cout << i << ": " << s_voiceLabels[i] << " ";
            
            if (i % 4 == 3)
                std::cout << "\n";
        }
        
        if (i % 4 != 0)
            std::cout << "\n";
        
        while (std::cin >> m_voice && (m_voice < 0 || m_voice >= c_voiceTypes))
            std::cout << "Please enter a value between 0 and " << c_voiceTypes - 1 << "\n";
        
        while (std::cin.get() != '\n')
            continue;
    }
    
    void Singer::show() const
    {
        std::cout << "Category: singer\n";
        Worker::show();
        std::cout << "Vocal range: " << s_voiceLabels[m_voice] << "\n";
    }
    
}   // end namespace Inheritance501
