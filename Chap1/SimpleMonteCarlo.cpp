#include <iostream>
#include <cmath>
#include "boxmuller.hpp"

using namespace std;

//T - Expiry; r - risk free rate; vol - volatility;
double montecarlo (double T, double strike, double spot, double vol, double r, unsigned long numberOfPaths)
    {
        double var = vol*vol * T;
        double stdDev = sqrt(var);
        double itoCorrection = -0.5*var;

        double S_init = spot * exp(r*T + itoCorrection);
        double S;

        double runningSum = 0;

        for (unsigned long i = 0; i < numberOfPaths; i++)
            {
                double nrand = z_score();
                S = S_init * exp(stdDev * nrand);
                double payoff = S - strike;
                payoff = (payoff > 0)? payoff : 0;

                runningSum += payoff;

            }
        double mean = runningSum / numberOfPaths;
        mean *= exp(-r * T);
        return mean;
    }

int main ()
    {
        cout << montecarlo (2, 100, 100, 0.15, 0.025, 100000);
    }
