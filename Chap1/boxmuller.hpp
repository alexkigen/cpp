#ifndef _boxmuller_hpp
#define _boxmuller_hpp
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double z_score () {
    double r;
    double z;
    double mu;
    double a; //declare first variable to be generated
    double b; //declare second variable to be generated

    

    do
    {
        a = 2.0*rand() / static_cast<double>(RAND_MAX)-1;
        b = 2.0*rand() / static_cast<double>(RAND_MAX)-1;
        r = a*a + b*b;

    } while (r >= 1.0);
    
        mu = sqrt((-2 * log(r))/r);
        z = mu * a;


    return z;
}


#endif