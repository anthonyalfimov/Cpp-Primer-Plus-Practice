//
//  Exceptions401.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <exception>        // for set_termintate()

namespace
{
    void CustomAbort();
    
    class Wobbly
    {
    public:
        int mWobblyItem;
    };
}

void showExceptions401()
{
    std::cout << "Setting custom termination routine... ";
    std::set_terminate(CustomAbort);
    std::cout << "Done!\n";
    
    std::cout << "Hope there aren't any uncaught exceptions this time..\n";
    
    throw Wobbly();
    
    // std::cout << "Successfully reached the end of the program!\n"; // Code will never be executed
}

namespace
{
    void CustomAbort()
    {
        std::cout << "> Terminating due to an uncaught exception\n";
        std::exit(5);
    }
}
