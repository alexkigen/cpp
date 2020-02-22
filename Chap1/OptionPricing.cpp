//This source code determines the payoff of an option depending on the option type and strike supplied;
//Can handle calls and puts;
//Can be expanded further to determine the payoffs of other options e.g. double digitals and Asian options.

#include <iostream>
#include "boxmuller.hpp"

using namespace std;

class PayOff {

    public:
        enum OptionType {Call, Put}; //specify the options program can handle
        PayOff (double strike_, OptionType option_); //initialize constructor to require option type and strike from object
        //double operator () (double spot); //initialize the operator function
        double getPayOff (double spot);

   private:
        double strike;
        OptionType option;

};

//function to specify strike and which option type you are dealing with

//we can apply arguments to a function in two ways: enclosing in brackets and using direct assignments (i.e. equal sign)
//PayOff::PayOff (double strike_, OptionType option_) {
//    strike = strike_ ;
 //   option = option_ ;

//}

PayOff::PayOff (double strike_, OptionType option_):
    strike (strike_) ,
    option (option_)
{}


//function to determine the payoff depending on strike and option supplied
double PayOff::getPayOff (double spot) {
    
    switch (option) {
        
        case Call :
                return max (spot - strike, 0.0);

        case Put :
                return max (strike - spot, 0.0);
        
        default :
                throw ("Unknown option type entered");
    }
}

//Risk Neutral Projection of spot to Expiry date

double SimpleMonteCarlo (string option_type, double strike, double currentSpot, double T, double vol, double r, long NumberOfPaths) {

    double itoCorrection = -0.5 * vol * vol * sqrt(T) ;
    double spotAdj       = currentSpot * exp(r*T + itoCorrection) ;
    double pay_off = 0.0;
    
    double runningSum    = 0.0 ;

    srand(time(0));

    for (unsigned long i = 0; i < NumberOfPaths; i++) {

        double z = z_score (); //pulls simulated normal random variable from the Box Muller method
        double spot = spotAdj * exp(vol * sqrt(T) * z);
        
            if (option_type == "Call") {
                PayOff callPayOff(strike, PayOff::Call);
                pay_off = callPayOff.getPayOff(spot);

            } else if (option_type == "Put") {
                PayOff putPayOff(strike, PayOff::Put); 
                pay_off = putPayOff.getPayOff(spot);

            } else {
                throw ("Unidentified option type");
            }
        runningSum += pay_off;

        //cout << spot << endl;
        //cout << pay_off << endl;
        //cout << runningSum << endl;
    }
    
    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*T);
    
    return mean;
}

int main () {

   cout << SimpleMonteCarlo ("Put", 50, 50, 2, 0.15, 0.06, 1000) << endl;
   cout << SimpleMonteCarlo ("Put", 50, 40, 2, 0.15, 0.06, 1000) << endl;
}