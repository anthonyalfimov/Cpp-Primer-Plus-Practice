//
//  FuncStruct102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/10/2018.
//

#include <iostream>
#include <cmath>

struct PolarPosition
{
    double radius;
    double angle;
};

struct RectPosition
{
    double x;
    double y;
};

//  Function prototypes
void rectToPolar(const RectPosition* input, PolarPosition* output);
void showPolarPosition(const PolarPosition* positionRA);

void showFuncStruct102()
{
    RectPosition rplace;
    PolarPosition pplace;
    
    std::cout << "Enter the x and y values: ";
    while (std::cin >> rplace.x >> rplace.y)    // input both values
    {
        rectToPolar(&rplace, &pplace);
        showPolarPosition(&pplace);
        std::cout << "Next two numbers <q to quit>: ";
    }
    std::cout << "Done.\n";
}

void rectToPolar(const RectPosition* p_in, PolarPosition* p_out)
{
    p_out->radius = std::sqrt(p_in->x * p_in->x + p_in->y * p_in->y);
    p_out->angle = std::atan2(p_in->y, p_in->x);
}

void showPolarPosition(const PolarPosition* p_pol)
{
    const double RadToDeg {57.29577951};
    
    std::cout
        << "radius = " << p_pol->radius
        << ", angle = " << p_pol->angle * RadToDeg << " degrees\n";
}
