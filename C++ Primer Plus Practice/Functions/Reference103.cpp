//
//  Reference103.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 17/10/2018.
//

#include <iostream>
#include <string>

namespace Reference103
{
//    second parameter is always a const reference to take advantage of
//    temporary variables
    std::string version1(const std::string& s1, const std::string& s2);
    const std::string& version2(std::string& s1, const std::string& s2);    // has side-effects
    const std::string& version3(std::string& s1, const std::string& s2);    // bad design
}

using namespace Reference103;

void showReference103()
{
    std::string input;
    std::string copy;
    std::string result;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    copy = input;
    
    std::cout << "\nYour string as entered: " << input << "\n";
    result = version1(input, "***");
    std::cout << "Your string enhanced: " << result << "\n";
    std::cout << "Your original string: " << input << "\n";
    
    result = version2(input, "###");
    std::cout << "\nYour string enhanced: " << result << "\n";
    std::cout << "Your original string: " << input << "\n";
    
//    std::cout << "\nResetting original string...\n";
//    input = copy;
//    result = version3(input, "@@@");
//    std::cout << "Your string enhanced: " << result << "\n";
//    std::cout << "Your original string: " << input << "\n";
    
    std::cout << "\nDone.\n";
}

std::string Reference103::version1(const std::string& s1, const std::string& s2)
{
    std::string tmp {s2 + s1 + s2};     // parallel with version3
    return tmp;
}

//  Has side effects:
const std::string& Reference103::version2(std::string& s1, const std::string& s2)
{
    s1 = s2 + s1 + s2;
    return s1;      // safe to return reference that was passed to function
}

/*
    Bad design:

const std::string& Reference103::version3(std::string& s1, const std::string& s2)
{
    std::string tmp {s2 + s1 + s2};
 
//  return reference to a local variable:
    return tmp;
}
*/
