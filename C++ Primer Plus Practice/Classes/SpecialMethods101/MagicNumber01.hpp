//
//  MagicNumber01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef MagicNumber01_hpp
#define MagicNumber01_hpp

namespace SpecialMethods101
{
    class MagicNumber
    {
    private:
        int num;
        
    public:
        // Use constructor to initialise object to type int
        MagicNumber(int n = 0);
        
        // Use assignment overload to assign object to type int
        MagicNumber& operator=(int n);
        
        // Assignment operator overload (verbose)
        MagicNumber& operator=(const MagicNumber&);
        
        // Copy constructor (verbose)
        MagicNumber(const MagicNumber&);
        
        // Destructor
        ~MagicNumber();
    };
}   // end namespace SpecialMethods101

#endif /* MagicNumber01_hpp */
