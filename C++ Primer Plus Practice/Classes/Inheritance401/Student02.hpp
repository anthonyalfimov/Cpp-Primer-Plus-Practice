//
//  Student02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Student02_hpp
#define Student02_hpp

#include <iostream>
#include <string>
#include <valarray>



namespace Inheritance400
{
//  Demonstrate private inheritance
    class Student : private std::string, private std::valarray<double>
    {
    private:
        typedef std::valarray<double> ArrayDouble;
        
    public:
        Student() : std::string("Null Student"), ArrayDouble() {}   // use base-class ctors
        explicit Student(const std::string& name)
            : std::string(name), ArrayDouble() {}
        explicit Student(int scoresCount)
            : std::string("Nully"), ArrayDouble(scoresCount) {}
        Student(const std::string& name, int scoresCount)
            : std::string(name), ArrayDouble(scoresCount) {}
        Student(const std::string& name, const ArrayDouble& scores)
            : std::string(name), ArrayDouble(scores) {}
        Student(const char* name, const double* scoresData, int scoresCount)
            : std::string(name), ArrayDouble(scoresData, scoresCount) {}
        
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
        // No need for private data members - they are inherited
        std::ostream& outputScores(std::ostream& os) const;     // private method for scores output
    };
}   // end namespace Inheritance400

#endif /* Student02_hpp */
