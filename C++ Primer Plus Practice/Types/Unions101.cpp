//
//  Unions101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 24/07/2018.
//

#include <iostream>
#include <random>

// unnecessary uniform random number generation in a range
// a simple
// min + static_cats<int>( (max - min) * rand() / RAND_MAX )
// would suffice!

unsigned int randomCharacterCode()      // unbiased random character code generation
{
    // set limits to only generate visible charachters
    constexpr unsigned int minCode {32};
    constexpr unsigned int maxCode {126};
    
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<unsigned int> uni(minCode,maxCode);   // guaranteed unbiased
    
    return uni(rng);
}

void showUnions101()
{
    union Symbol
    {
        unsigned int code;
        char character;
    };
    
    int repetitions;
    std::cout << "How many characters do you want? ";
    std::cin >> repetitions;
    
    for (int i = 0; i < repetitions; ++i)
    {
        Symbol test {randomCharacterCode()};   // list initialization doesn't require specifying a union field
        std::cout << "Character '" << test.character << "' has a code " << test.code << "\n";
    }
}
