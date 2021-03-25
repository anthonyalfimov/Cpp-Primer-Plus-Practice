//
//  StdString103.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::string search
//==================================================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

void showStdString103()
{
    const int wordCount = 26;
    const std::string wordList[wordCount]
    {
        "apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage", "health", "insult",
        "jackal", "keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt", "remote",
        "stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy"
    };
    
    std::srand (static_cast<unsigned> (std::time (nullptr)));

    char playChoice;
    
    std::cout << "Will you play a word game? <y/n> ";
    std::cin >> playChoice;
    playChoice = std::tolower (playChoice);
    
    while (playChoice == 'y')
    {
        std::string targetWord = wordList[std::rand() % wordCount];
        unsigned targetLength = static_cast<unsigned> (targetWord.length());
        
        std::string guessedWord (targetLength, '-');
        std::string wrongGuesses;
        
        int guesses = 6;
        
        std::cout
            << "Guess the secret word. It has " << targetLength << " letters, and you "
            << "guess one letter at a time. You get " << guesses << " wrong guesses.\n"
            << "Your word: " << guessedWord << "\n";
        
        while (guesses > 0 && guessedWord != targetWord)
        {
            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            
            if (wrongGuesses.find (letter) != std::string::npos
                || guessedWord.find (letter) != std::string::npos)
            {
                std::cout << "You already guessed that! Try again.\n";
                continue;
            }
            
            auto letterPosition = targetWord.find (letter);
            
            if (letterPosition == std::string::npos)
            {
                std::cout << "Bad guess!\n\n";
                --guesses;
                wrongGuesses += letter;     // add bad guess to the string
            }
            else
            {
                std::cout << "Good guess!\n\n";
                
                do
                {
                    guessedWord[letterPosition] = letter;
                    letterPosition = targetWord.find (letter, letterPosition + 1);
                }
                while (letterPosition != std::string::npos);
            }
            
            std::cout << "Your word: " << guessedWord << "\n";
            
            if (guessedWord != targetWord)
            {
                if (wrongGuesses.length() > 0)
                    std::cout << "Wrong guesses: " << wrongGuesses << "\n";
                
                std::cout << guesses << " wrong guesses left.\n";
            }
        }
        
        if (guesses > 0)
            std::cout << "That's right!\n";
        else
            std::cout << "Sorry, the word is " << targetWord << ".\n";
        
        std::cout << "\nWill you play another? <y/n> ";
        std::cin >> playChoice;
        playChoice = std::tolower(playChoice);
    }
    
    std::cout << "\nDone.\n";
}
