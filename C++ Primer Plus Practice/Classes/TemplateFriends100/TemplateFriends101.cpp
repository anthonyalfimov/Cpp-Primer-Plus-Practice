//
//  TemplateFriends101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Template class with non-template friends

#include <iostream>

namespace
{
    template <typename Type>
    class HasFriend
    {
    public:
        HasFriend(const Type& item) : m_item(item) { ++s_count; }
        ~HasFriend() { --s_count; }
        
        friend void counts();                       // non-template friend with no template parameters
        friend void reports(HasFriend<Type>&);      // non-template friend with template parameter
        
    private:
        Type m_item;
        static int s_count;
    };
    
    // Each specialisation has its own static member - initialise them all
    template <typename Type>
    int HasFriend<Type>::s_count = 0;
    
    // Non-template friend function to all HasFriend<Type> classes
    void counts()
    {
        // Explicitely specify template specialisations to use
        std::cout << "<int> count: " << HasFriend<int>::s_count << "\n";
        std::cout << "<double> count: " << HasFriend<double>::s_count << "\n";
    }
    
    // Non-template friend function to HasFriend<int> class
    void reports(HasFriend<int>& hf)
    {
        std::cout << "HasFriend<int>: " << hf.m_item << "\n";
    }
    
    // Non-template friend function to HasFriend<double> class
    void reports(HasFriend<double>& hf)
    {
        std::cout << "HasFriend<double>: " << hf.m_item << "\n";
    }
}

void showTemplateFriends101()
{
    std::cout << "No objects declared:\n";
    counts();
    std::cout << "\n";
    
    HasFriend<int> hfi1(10);
    std::cout << "After hfi1 declared:\n";
    counts();
    std::cout << "\n";
    
    HasFriend<int> hfi2(20);
    std::cout << "After hfi2 declared:\n";
    counts();
    std::cout << "\n";
    
    HasFriend<double> hfd1(10.5);
    std::cout << "After hfd1 declared:\n";
    counts();
    std::cout << "\n";
    
    reports(hfi1);
    reports(hfi2);
    reports(hfd1);
}
