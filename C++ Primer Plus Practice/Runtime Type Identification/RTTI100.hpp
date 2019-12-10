//
//  RTTI100.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef RTTI100_h
#define RTTI100_h

#include <iostream>

namespace RTTI100
{
    class Grand
    {
    public:
        explicit Grand (int value = 0) : mValue (value) {}
        
        virtual void speak() const { std::cout << "I am a grand class!\n"; }
        virtual int getValue() const { return mValue; }
        
    private:
        int mValue;
    };
    
    class Superb : public Grand
    {
    public:
        explicit Superb (int value = 0) : Grand (value) {}
        
        void speak() const override { std::cout << "I am a superb class!\n"; }
        virtual void say() const { std::cout << "I hold the superb value of " << getValue() << "!\n"; }
    };
    
    class Magnificent : public Superb
    {
    public:
        Magnificent(int value = 0, char character = 'A') : Superb (value), mCharacter (character) {}
        
        void speak() const override { std::cout << "I am a magnificent class!\n"; }
        void say() const override
        {
            std::cout << "I hold the magnificent character " << mCharacter
            << " and the value of " << getValue() << "!\n";
        }
        
    private:
        char mCharacter;
    };
    
    inline Grand* getRandomObject()     // inline to define in header and keep things compact
    {
        // NB! Poor memory management - allocated memory has to be manually freed!
        
        Grand* ptr;
        
        switch (std::rand() % 3)
        {
            case 0  : ptr = new Grand (std::rand() % 100);
                break;
            case 1  : ptr = new Superb (std::rand() % 100);
                break;
            default : ptr = new Magnificent (std::rand() % 100, 'A' + (std::rand() % 26));
        }
        
        return ptr;
    }
}

#endif /* RTTI100_h */
