//
//  Worker02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 02/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Worker02.hpp"

namespace Inheritance502
{
//  Worker methods
    
    Worker::~Worker() {}                        // must implement virtual destructor, even if pure
    
    // Protected methods
    void Worker::data() const
    {
        std::cout
            << "Name: " << m_fullName << "\n"
            << "Employee ID: " << m_id << "\n";
    }
    
    void Worker::get()
    {
        std::getline(std::cin, m_fullName);
        
        std::cout << "Enter worker's ID: ";
        std::cin >> m_id;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
//  Waiter methods
    
    void Waiter::set()
    {
        std::cout << "Enter waiter's name: ";
        Worker::get();
        get();
    }
    
    void Waiter::show() const
    {
        std::cout << "Category: waiter\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void Waiter::data() const
    {
        std::cout << "Panache rating: " << m_panache << "\n";
    }
    
    void Waiter::get()
    {
        std::cout << "Enter waiter's panache rating: ";
        std::cin >> m_panache;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
//  Singer methods
    
    const char* Singer::s_voiceLabels[] =
    {
        "other", "alto", "contralto", "soprano",
        "bass", "baritone", "tenor"
    };
    
    void Singer::set()
    {
        std::cout << "Enter singer's name: ";
        Worker::get();
        get();
    }
    
    void Singer::show() const
    {
        std::cout << "Category: singer\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void Singer::data() const
    {
        std::cout << "Vocal range: " << s_voiceLabels[m_voice] << "\n";
    }
    
    void Singer::get()
    {
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
    
//  SingingWaiter methods
    
    void SingingWaiter::set()
    {
        std::cout << "Enter singing waiter's name: ";
        Worker::get();
        get();
    }
    
    void SingingWaiter::show() const
    {
        std::cout << "Category: singing waiter\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void SingingWaiter::data() const
    {
        Singer::data();
        Waiter::data();
    }
    
    void SingingWaiter::get()
    {
        Singer::get();
        Waiter::get();
    }
    
}   // end namespace Inheritance502
