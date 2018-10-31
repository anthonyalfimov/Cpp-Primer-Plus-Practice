//
//  Struct102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 20/07/2018.
//

#include <iostream>
#include <string>

void showStruct102()
{
    struct Inflatable
    {
        char name[20];
        float volume;
        double price;
    };
    
    Inflatable bouquet {"sunflowers", 0.20, 12.49};
    Inflatable choice;
    std::cout << "bouquet: " << bouquet.name << " for $" << bouquet.price << "\n";
    choice = bouquet;       // using copy constructor to assign one structure to another
                            // MEMBERWISE ASSIGNMENT:
                            // assigning structs causes every member of one struct to be
                            // set to the value of a corresponging member of another struct,
                            // EVEN IF THE MEMBER IS AN ARRAY!
                            //
                            // - this behaviour is likely governed by the default copy constructor
    
    std::cout << "choice: " << choice.name << " for $" << choice.price << "\n";
    
    // Structure objects can be created and initialized withtin the stucture declaration:
    struct Cube {int size; std::string colour;} redBox {5, "red"};
    std::cout << "Preferred package: " << redBox.size << " cm " << redBox.colour << " box\n";
    
    // It is possible to create anonymous structures
    struct
    {
        int code;
        std::string name;
    } agent;
    agent.code = 007;
    agent.name = "Bond";
    std::cout << "Call 00" << agent.code << ", we need a " << agent.name + "ulance!\n";
    
}
