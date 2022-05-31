#include "RandomInitializer.h"
#include "Constants.h"

unsigned RandomInitializer::numOfPrey(unsigned _size)
{
    return rand() % max_rand + 1;
}

unsigned RandomInitializer::numOfPred(unsigned _size)
{
    return rand() % max_rand + 1;
}

unsigned RandomInitializer::numOfObs(unsigned _size)
{
    return  rand() % max_rand + 1;
}
