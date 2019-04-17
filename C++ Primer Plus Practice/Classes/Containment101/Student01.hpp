//
//  Student01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Student01_hpp
#define Student01_hpp

#include <iostream>
#include <string>
#include <valarray>

namespace Containment100
{
    class Student
    {
    private:
        typedef std::valarray<double> ArrayDouble;
        
    public:
        Student() : m_name("Null Student"), m_scores() {}       // use member object ctors
        explicit Student(const std::string& name)
            : m_name(name), m_scores() {}
        explicit Student(int scoresCount)
            : m_name("Nully"), m_scores(scoresCount) {}
        Student(const std::string& name, int scoresCount)
            : m_name(name), m_scores(scoresCount) {}
        Student(const std::string& name, const ArrayDouble& scores)
            : m_name(name), m_scores(scores) {}
        Student(const char* name, const double* scoresData, int scoresCount)
            : m_name(name), m_scores(scoresData, scoresCount) {}
        
        ~Student() {}                                           // not virtual - don't inherit from!
        
        const std::string& name() const;
        double average() const;
        double& operator[](int i);                              // read/write version
        double  operator[](int i) const;                        // read-only version
        
//      Friend functions
        // Input
        friend std::istream& operator>>(std::istream& is, Student& s);  // 1 word
        friend std::istream& getline(std::istream& is, Student& s);     // 1 line
        
        // Output
        friend std::ostream& operator<<(std::ostream& os, const Student& s);
        
    private:
        std::string m_name;             // contained object
        ArrayDouble m_scores;           // contained object
        
        std::ostream& outputScores(std::ostream& os) const;     // private method for scores output
    };
}   // end namespace Containment100

#endif /* Student01_hpp */
