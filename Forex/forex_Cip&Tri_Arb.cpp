#include <iostream>
#include <cmath>

using namespace std;

//stores inputs - can also be modified to require user input
double inputFinderBid (string pairChoice) {
        double UsdEurBid = 1.1163;
        double UsdEurAsk = 1.1161;
        double EurJpyBid = 119.79;
        double EurJpyAsk = 119.82;
        double JpyUsdBid = 107.33;
        double JpyUsdAsk = 107.36;
        double bid;
        double ask;

    if (pairChoice == "USD/EUR") {
        bid = UsdEurBid;
        ask = UsdEurAsk;
    } else if (pairChoice == "EUR/JPY") {
        bid = EurJpyBid;
        ask = EurJpyAsk;
    } else if (pairChoice == "JPY/USD") {
        bid = JpyUsdBid;
        ask = JpyUsdAsk;
    } else {
        throw("No such pair");
    }
    return bid;
}

double inputFinderAsk (string pairChoice) {
        double UsdEurBid = 1.1163;
        double UsdEurAsk = 1.1161;
        double EurJpyBid = 119.79;
        double EurJpyAsk = 119.82;
        double JpyUsdBid = 107.33;
        double JpyUsdAsk = 107.36;
        double bid;
        double ask;

    if (pairChoice == "USD/EUR") {
        bid = UsdEurBid;
        ask = UsdEurAsk;
    } else if (pairChoice == "EUR/JPY") {
        bid = EurJpyBid;
        ask = EurJpyAsk;
    } else if (pairChoice == "JPY/USD") {
        bid = JpyUsdBid;
        ask = JpyUsdAsk;
    } else {
        throw ("No such pair");
    }
    return ask;
}

double SpotArbitrage (double bid_, double offer_) {
	
	double spread = bid_ - offer_;
	double payOff;
	
	if (bid_ > offer_) {
		payOff = spread;
	} else {
		payOff = 0;
	}
	
	return payOff;
}

double triangularArbitrage (double bidPairA_, double offerPairA_,
							double bidPairB_, double offerPairB_,
                            double bidPairC_, double offerPairC_)
{
		return bidPairA_* bidPairB_;						
}

double cipArbitrage (double spot_, double marketForwardRate_, double domesticInterestRate, double foreignInterestRate) {
    double impliedForwardRate;
    double cipPayoff;

    impliedForwardRate = spot_ * (1 + foreignInterestRate)/(1 + domesticInterestRate);
    
    //if impliedForwardRate > marketForwardRate, buy foreign, invest at the foreign rate
    //at time T, convert back to domestic currency

    if (impliedForwardRate != marketForwardRate_) {
        cipPayoff = abs(impliedForwardRate - marketForwardRate_);
    } else if (impliedForwardRate < marketForwardRate_) {
        cipPayoff = 0;
    }

    return cipPayoff;

}

double notionalCall () {
	double notional;
	cout << "What notional would you like?" << endl;
	cout << "Notional = ";
	cin >> notional;
	return notional;
}

string currencyPairsCall () {
    string pairA = "USD/EUR";
    string pairB = "EUR/GBP";
    string pairC = "GBP/USD";

    string currencyCalled;

    cout << "Select the pair of currencies for this analysis: format required is USD/EUR" <<endl;
    cout << "Pair A is " << pairA << endl;
    cout << "Pair B is " << pairB << endl;
    cout << "Pair C is " << pairC << endl;

    cin >> currencyCalled;

    return currencyCalled;

}

int main () {

	double payOff;
	double notional;
	double profitArbitrage;

    double bid;
    double offer;
    string pairChoice;

    pairChoice = currencyPairsCall();
    bid = inputFinderBid(pairChoice);
    offer = inputFinderAsk(pairChoice);
	
	payOff = SpotArbitrage(bid, offer);
	cout << "Risk free profit per unit is: " << payOff << endl;
	
	if (payOff > 0) {
		notional = notionalCall();
		profitArbitrage = payOff * notional;
		cout << "Expected Riskless Profit: " << profitArbitrage << endl;
	} else {
		cout << "No arbitrage opportunity on Spot" << endl;
	}

    //perform covered arbitrage check
    cout << "Would you like to perform Covered Interest Parity Arbitrage check? 1 = Yes, 0 = No" << endl;
    bool cip_perform = false;
    cin >> cip_perform;
    string pairOne;
    string pairTwo;
    
    while (cip_perform == true) {
        pairOne = currencyPairsCall();
        pairTwo = currencyPairsCall();

        cout << "Pair one is " << pairOne << endl;
        cout << "Pair two is " << pairTwo << endl;

        cip_perform = false;
    }

    //cipPayOff = cipArbitrage ()
	
}
