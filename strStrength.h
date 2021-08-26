#include <iostream>
#include <chrono>  
#include <math.h>
#include <memory>

#ifndef STRSTRENGTH_H
#define STRSTRENGTH_H

/*
 * Determine min number of tests to measure maxWeight on sn
 * strings by building a table.
 *
 * Returns the min number of tests needed for maxWeight
*/
int buildTable(int maxWeight, int sn);

/*
 * Calls maxTestable weight assuming increasing number of
 * of tests until maxTestableWeight exceeds maxWeight. Given sn 
 * strings.
 *
 * Returns the min number of tests needed to test maxWeight
 * ranges with sn strings
*/
int minTests (int maxWeight, int sn);

/*
 * Recursively find the max weight range you can measure 
 * in the worst cast given sn number string and tn number
 * of measurements
 *
 * Returns the max testable weight range for a given number
 * of string and a given number of tests
*/
int maxTestableWeight (int tn, int sn);
#endif //STRSTREGTH_H

