//
//  CombinationOfTypes.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 14/08/2018.
//

#include <iostream>

void showCombinationOfTypes()
{
    struct antarctica_years_end
    {
        int year;
        // some interesting data, etc.
    };
    
    antarctica_years_end s01, s02, s03;     // create structure objects
    s01.year = 1998;                        // use membership operator
    
    antarctica_years_end * pa {&s02};       // create pointer to struct
    pa->year = 1999;                        // use indirect membership operator
    
    antarctica_years_end trio[3];           // array of 3 structs
    trio[0].year = 2003;
    std::cout << trio->year << "\n";        // use array name as a pointer to 1st element
    
    const antarctica_years_end * arp[3] {&s01, &s02, &s03};     // array of const pointers to struct
    std::cout << arp[1]->year << "\n";
    
    const antarctica_years_end ** ppa {arp};    // pointer to const pointer to struct
                                                // note that array name has this type
                                                // and points to the first element in the array
    auto ppb {arp};                             // automatic type deduction
    std::cout << (*ppa)->year << "\n";          // parenthesis needed due to precedence and associativity rules
    std::cout << (*(ppb + 1))->year << "\n";
}
