//
//  SmartPtrs101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 18/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>

namespace
{
    class Report
    {
    public:
        explicit Report (const std::string& comment) : mComment (comment) { std::cout << "Object created!\n"; }
        ~Report() { std::cout << "Object destroyed!\n"; }
        
        void comment() const { std::cout << mComment << "\n"; }
        
    private:
        std::string mComment;
    };
}

void showSmartPtrs101()
{
//    Deprecated:
//    {
//        std::auto_ptr<Report> ps (new Report ("using auto_ptr"));
//        ps->comment();
//    }
//
//    std::cout << "\n";
    
    {
        std::unique_ptr<Report> ps (new Report ("using unique_ptr"));
        ps->comment();
    }
    
    std::cout << "\n";
    
    {
        std::shared_ptr<Report> ps (new Report ("using shared_ptr"));
        ps->comment();
    }
    
    std::cout << "\nDone.\n";
}
