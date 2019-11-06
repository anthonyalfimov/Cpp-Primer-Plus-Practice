//
//  QueueTest02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include "Queue02.hpp"

void showQueue201()
{
    using Queue201::Queue;
    
    Queue<std::string> clientQueue(5);
    std::string clientName;
    
    while (! clientQueue.isFull())
    {
        std::cout << "Please enter your name. You will be served in the order of arrival.\n"
                     "Name: ";
        std::getline(std::cin, clientName);
        
        clientQueue.enqueue(clientName);
    }
    
    std::cout << "\nThe queue is full. Processing begins!\n\n";
    
    while (! clientQueue.isEmpty())
    {
        clientQueue.dequeue(clientName);
        std::cout << "Now processing " << clientName << "...\n";
    }
    
    std::cout << "\nDone.\n";
}
