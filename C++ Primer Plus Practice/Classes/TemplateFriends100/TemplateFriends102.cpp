//
//  TemplateFriends102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 22/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Template class with bound template friends
//

#include <iostream>

namespace
{
    // 1. Declare template functions before the class template
    template <typename U> void count();
    template <typename V> void report (V&);
    
    // 2. Declare appropriate template function specialisations as template class friends
    template <typename Type>
    class HasFriend
    {
    public:
        HasFriend (const Type& item) : m_item (item) { ++s_count; }
        ~HasFriend() { --s_count; }
        
        friend void count<Type>();                  // explicitely specify template argument U
        friend void report<> (HasFriend<Type>&);    // template argument V deduced from function argument
        
    private:
        Type m_item;
        static int s_count;
    };
    
    // Each specialisation has its own static member - initialise them all
    template <typename Type>
    int HasFriend<Type>::s_count = 0;
    
    // 3. Provide definitions for the template functions
    //     Each class specialisation get matching specialisations of friend function templates
    template <typename U>
    void count()
    {
        std::cout << "template size: " << sizeof (HasFriend<U>) << "\n";
        std::cout << "template count: " << HasFriend<U>::s_count << "\n";
    }
    
    template <typename V>
    void report (V& obj)
    {
        std::cout << obj.m_item << "\n";
    }
}

void showTemplateFriends102()
{
    count<int>();               // template argument U can't be deduced and has to be explicitely specified
    std::cout << "\n";
    
    HasFriend<int> hfi1 (10);
    HasFriend<int> hfi2 (20);
    HasFriend<double> hfd1 (10.5);
    
    report (hfi1);              // template argument V deduced from function argument to be HasFriend<int>
    report (hfi2);              // template argument V deduced from function argument to be HasFriend<int>
    report (hfd1);              // template argument V deduced from function argument to be HasFriend<double>
    
    std::cout << "\ncounts<int> output:\n";
    count<int>();
    
    std::cout << "\ncounts<double> output:\n";
    count<double>();
    
    std::cout << "\nDone.\n";
}
