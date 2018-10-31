//
//  Reference201.cpp
//  C++ Primer Plus Exercises
//
//  This program demonstrates that a base class reference (ostream&)
//  can reference a derived class object (cout, fout)
//  without a type cast.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

namespace Reference201
{
    void fileIt(std::ostream& os, double fo, const double fe[], int n);
    constexpr int Limit {5};
}

using namespace Reference201;

void showReference201()
{
    std::ofstream fout;                         // file output stream
    const char* fileName {"ep-data.txt"};
    fout.open(fileName);
    
    if (!fout.is_open())                        // if failed to open file
    {
        std::cout << "Can't open " << fileName << ". Bye.\n";
        std::exit(EXIT_FAILURE);
    }
    
    double objective;
    std::cout << "Enter the focal lenght of your "
                 "telescope objective in mm: ";
    std::cin >> objective;
    
    double eps[Limit];
    std::cout << "Enter the focal lenghts, in mm, of " << Limit
              << " eyepieces:\n";
    for (int i = 0; i < Limit; i++)
    {
        std::cout << "Eyepiece #" << i + 1 << ": ";
        std::cin >> eps[i];
    }
    
    fileIt(fout, objective, eps, Limit);
    fileIt(std::cout, objective, eps, Limit);
    
    std::cout << "\nDone.\n";
}

void Reference201::fileIt(std::ostream& os, double fo, const double fe[], int n)
{
    std::ios_base::fmtflags initial;            // formatting state
                                                // fmtflags - type for storing
                                                // formatting state (flags)
    
    initial = os.setf(std::ios_base::fixed);    // save initial formatting state:
                                                // mode: fixed-point decimal notation
                                                // setf() returns a copy of
                                                // all current formatting settings
    
    os.precision(0);                // set display decimal precision to 0
    os << "Focal length of objective: " << fo << " mm\n";
    
    os.setf(std::ios::showpoint);   // mode: always show (trailing) decimal point
    os.precision(1);                // display decimal precision: show 1 digit
    
    os.width(12);                   // set output field width for the next output action
                                    // after displating one value, it resets to 0 (fit value)
    os << "f.l. eyepiece";
    
    os.width(15);
    os << "magnification" << "\n";  // separate '\n' from the output to be fit into 15-field
    
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        
        os.width(15);
        os << int(fo / fe[i] + 0.5) << "\n";
    }
    
    os.setf(initial);               // restore initial formatting state
}
