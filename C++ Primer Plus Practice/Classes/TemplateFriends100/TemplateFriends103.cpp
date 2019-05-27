//
//  TemplateFriends103.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 27/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Template class with unbound template friends
//

#include <iostream>

namespace
{
    template <typename Type>
    class HasFriends
    {
    public:
        HasFriends(const Type& item) : m_item(item) { ++s_count; }
        ~HasFriends() { --s_count; }
        
        // 1. Declare template function inside the class definition
        template <typename U, typename V>
        friend void showPair(U&, V&);
        
    private:
        Type m_item;
        static int s_count;
    };
    
    // Each specialisation has its own static member - initialise them all
    template <typename Type>
    int HasFriends<Type>::s_count = 0;
    
    // 2. Provide definition for the template function
    template <typename U, typename V>
    void showPair(U& u, V& v)
    {
        std::cout << u.m_item << ", " << v.m_item << "\n";
        
        // Each function specialisation is a friend of all class specialisations
        std::cout << "<int> count: " << HasFriends<int>::s_count
                  << ", <double> count: " << HasFriends<double>::s_count << "\n";
    }
}

void showTemplateFriends103()
{
    HasFriends<int> hfi1(10);
    HasFriends<int> hfi2(20);
    
    std::cout << "hfi1, hfi2: ";
    showPair(hfi1, hfi2);
    
    HasFriends<double> hfd1(10.5);
    std::cout << "\nhfd1, hfi2: ";
    showPair(hfd1, hfi2);
    
    std::cout << "\nDone.\n";
}
