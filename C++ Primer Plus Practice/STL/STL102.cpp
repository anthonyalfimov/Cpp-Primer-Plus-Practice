//
//  STL102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/10/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// Using the STL (Variation where the original input is preserved)
//==================================================================================================

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

void showSTL102()
{
    std::cout << "Enter words (enter <quit> to quit):\n";
    std::vector<std::string> inputWordList;
    std::string inputWord;
    
    while (std::cin >> inputWord && inputWord != "quit")
        inputWordList.push_back (inputWord);
    
    std::cout << "\nYou entered the following words:\n";
    auto printString = [] (const std::string& s) { std::cout << s << " "; };
    std::for_each (inputWordList.cbegin(), inputWordList.cend(), printString);
    
    // Convert words to lowercase, sort alphabetically and remove duplicates by storing in a set
    auto stringToLowerCase = [] (std::string s) -> std::string
    {
        // For referece: https://en.cppreference.com/w/cpp/string/byte/tolower
        std::transform (s.begin(), s.end(), s.begin(), [] (unsigned char c) { return std::tolower(c); });
        return s;
    };
    
    std::set<std::string> uniqueAlphabeticWordList;
    using setInsertIterator = std::insert_iterator<std::set<std::string>>;
    std::transform (inputWordList.cbegin(), inputWordList.cend(),
                    setInsertIterator (uniqueAlphabeticWordList, uniqueAlphabeticWordList.begin()),
                    stringToLowerCase);
    
    std::cout << "\n\nAlphabetic list of words:\n";
    std::for_each (uniqueAlphabeticWordList.cbegin(), uniqueAlphabeticWordList.cend(), printString);
    
    // Calculate word frequency and store it in a map
    std::map<std::string, long> wordFrequencyMap;
    
    for (const std::string& word : uniqueAlphabeticWordList)
    /* std::map operator[] returns a reference to the value that is mapped to a key,
        performing an insertion if such key does not already exist.
    */
        wordFrequencyMap[word] = std::count_if(inputWordList.cbegin(), inputWordList.cend(),
                                               [word, stringToLowerCase] (const std::string& item)
                                               { return stringToLowerCase (item) == word; });
    
    std::cout << "\n\nWord frequency:\n";
    
    for (const std::string& word : uniqueAlphabeticWordList)
        std::cout << word << ": " << wordFrequencyMap[word] << "\n";
    
    std::cout << "\nConfirm that input was not modified:\n";
    std::for_each (inputWordList.cbegin(), inputWordList.cend(), printString);
    
    std::cout << "\n\nDone.\n";
}
