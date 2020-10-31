#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std ;

// Returns a Random int between 0 and n-1
unsigned int 
Random(unsigned int n)
{
    srand(time(0));
    unsigned int Random = rand() % n;

    return Random; 
}