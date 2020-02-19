#include <iostream>
#include <cmath>
#include "boxmuller.hpp"

using namespace std;

//T - Expiry; r - risk free rate; vol - volatility; UB/LB - upper/lower bounds for double digital option
double montecarlo (double T, double strike, double spot, double vol, double r, unsigned long numberOfPaths,
                   double LB, double UB, double units)
    {
        double var = vol*vol * T;
        double stdDev = sqrt(var);
        double itoCorrection = -0.5*var;

        double S_init = spot * exp(r*T + itoCorrection);
        double S;

        double runningSum = 0;

        double payoff;

        for (unsigned long i = 0; i < numberOfPaths; i++)
            {
                double nrand = z_score();
                S = S_init * exp(stdDev * nrand); //103
                //call option payoff
                //payoff = S - strike;
                //put option payoff
                //payoff = strike - S;
                //double digital payoff
                payoff = (S > LB && S < UB)? (1 * units) : 0;
                payoff = (payoff > 0)? payoff : 0;

                
                //payoff = (payoff > 0)? payoff : 0;
                

                runningSum += payoff;

            }
        double mean = runningSum / numberOfPaths;
        mean *= exp(-r * T);
        return mean;
    }

int main ()
    {
        cout << montecarlo (0.5, 100, 100, 0.15, 0.04, 1000, 90, 110, 100);
    }
