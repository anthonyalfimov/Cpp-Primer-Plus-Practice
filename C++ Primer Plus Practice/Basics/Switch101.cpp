//
//  Switch101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/09/2018.
//

#include <iostream>

// Function prototypes
void showMenu();
void report();
void comfort();

void showSwitch101()
{
    showMenu();
    char choice;
    std::cin >> choice;
    
    while (choice != 'q' && choice != 'Q') {
        switch(choice)
        {
            // case [x] is only a label, it doesn't stop execution
            // we can use this to combine multiple cases
            case 'w' :
            case 'W' :  std::cout << "Alert!\n";
                        break;
            case 'r' :
            case 'R' :  report();
                        break;
            case 'a' :
            case 'A' :  std::cout << "The boss was in all day.\n";
                        break;
            case 'c' :
            case 'C' :  comfort();
                        break;
            default :   std::cout << "That's not a choice!\n";
        }
        showMenu();
        std::cin >> choice;
    }
    std::cout << "Bye!\n";
}

void showMenu()
{
    std::cout << "Please make a selection:\n"
                 "W: warning    R: report\n"
                 "A: alibi      C: comfort\n"
                 "Q: quit\n";
}

void report()
{
    std::cout << "It's been an excellent week for business.\n"
                 "Sales are up 120%. Expenses are down 35 %.\n";
}

void comfort()
{
    std::cout << "Your employees think you are the finest CEO\n"
                 "in the industry. The board of directors think\n"
                 "you are the finest CEO in the industry.\n";
}
