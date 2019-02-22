//
//  ATMsim01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 22/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>              // for rand() and srand()
#include <ctime>                //  for time()

#include "Queue01.hpp"

namespace
{
    const int MinPerHour = 60;
    
    /**
     Determines whether a new customer shows up on this cycle of the simulation

     @param averageTime average time between customers in minutes
     @return true if customer shows up this cycle, false otherwise
     */
    bool isNewCustomer(double averageTime);     // is there a new customer?
}

void showQueue101()
{
    using Queue101::Queue;
    using Queue101::Item;
    
    std::srand(static_cast<int>(std::time(nullptr)));       // seed the random number generator
    
    std::cout << "===| ATM Simulation |===\n";
    
    std::cout << "Enter the maximum size of the queue: ";
    int queueSize;
    std::cin >> queueSize;
    Queue line(queueSize);                  // create a Queue object with max of queueSize items
    
    std::cout << "Enter the number of simulated hours: ";
    int hours;
    std::cin >> hours;
    
    // Simulation runs at 1 cycle per minute
    long cycleCount = MinPerHour * hours;
    
    std::cout << "Enter the average number of customers per hour: ";
    double customersPerHour;
    std::cin >> customersPerHour;
    
    double cyclesPerCustomer = MinPerHour / customersPerHour;   // average time between arrivals
    
    // Initialise values
    Item tmp;                   // temp storage for enqueuing and dequeueing customers
    int waitTime   = 0;         // temp storage for time until ATM is free
    
    long turnaways = 0;         // turned away by full queue
    long customers = 0;         // joined the queue
    long served    = 0;         // served duting the simulation
    
    long lineCount = 0;         // cumulative line length
    long lineWait  = 0;         // cumulative time in line
    
    // Running the simulation
    for (int cycle = 0; cycle < cycleCount; cycle++)
    {
        // Handle new customers
        if (isNewCustomer(cyclesPerCustomer))
        {
            if (line.isFull())
                turnaways++;
            else
            {
                customers++;
                tmp.set(cycle);                         // cycle = time of arrival
                line.enqueue(tmp);                      // add new customer to the line
            }
        }
        // Handle processing the clinets
        if (waitTime <= 0 && !line.isEmpty())
        {
            line.dequeue(tmp);                          // attend next customer from the queue
            waitTime = tmp.getProcessTime();            // get processing time for the customer
            lineWait += cycle - tmp.getArrivalTime();   // accumulate time waiting in line
            served++;                                   // count customer as served
        }
        // Handle waiting for processing
        if (waitTime > 0)
            waitTime--;
        // Update average line length calculation
        lineCount += line.count();
    }
    
    // Reporing the results
    if (customers > 0)
    {
        std::cout
            << "\n"
            << "Customers accepted: " << customers << "\n"
            << "  Customers served: " << served << "\n"
            << "         Turnaways: " << turnaways << "\n"
            << "Average queue size: ";
        
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        
        std::cout
            << double(lineCount) / cycleCount << "\n"
            << " Average wait time: " << double(lineWait) / served << " minutes\n";
    }
    else
        std::cout << "\nNo customers!\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool isNewCustomer(double averageTime)
    {
        return (std::rand() * averageTime / RAND_MAX < 1);      // true one time in averageTime
    }
}
