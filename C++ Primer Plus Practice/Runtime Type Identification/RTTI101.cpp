//
//  RTTI101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 09/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace
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
    
    Grand* getRandomObject();
}

void showRTTI101()
{
    std::srand (static_cast<unsigned> (std::time (nullptr)));   // seed the random number generator
    
    Grand* grandPtr;
    Superb* superbPtr;
    
    for (int i = 0; i < 5; ++i)
    {
        grandPtr = getRandomObject();   // create object
        grandPtr->speak();              // common method for all class hierarchy
        
        if ((superbPtr = dynamic_cast<Superb*> (grandPtr)) != nullptr)
            superbPtr->say();           // method unique to Superb and Magnificent classes
        
        std::cout << "\n";
        delete grandPtr;                // destroy object
    }
}

namespace
{
    Grand* getRandomObject()
    {
        // NB! Poor memory management!
        
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

