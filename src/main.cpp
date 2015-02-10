#include <iostream>

#include "interval.h"

int main( int argc, char** argv ) {
    Interval measurement(0, 1);
    Interval tolerance(0.001, 0.1);
    
    std::cout << "measurement = " << measurement << std::endl;
    std::cout << "tolerance =   " << tolerance   << std::endl;
    std::cout << "sum =         " << measurement + tolerance << std::endl;
    
    return 0;
}