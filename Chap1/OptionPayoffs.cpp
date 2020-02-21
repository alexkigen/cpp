//This source code determines the payoff of an option depending on the option type and strike supplied;
//Can handle calls and puts;
//Can be expanded further to determine the payoffs of other options e.g. double digitals and Asian options.

#include <iostream>

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
PayOff::PayOff (double strike_, OptionType option_) {
    strike = strike_ ;
    option = option_ ;
}

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

//implement

int main () {
    cout << "Ran to end successfully" << endl;

    PayOff callPayOff(50, PayOff::Call);
    PayOff putPayOff (50, PayOff::Put);

    cout << callPayOff.getPayOff (60) << endl;
    cout << putPayOff.getPayOff (20);
    //cout << callpayoff << endl;
}

