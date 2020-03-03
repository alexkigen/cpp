#include <iostream>

using namespace std;

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

double triangularArbitrage (double bidPairA, double offerPairA,
							double bidPairB, double offerPairB_)
{
								
}

double notionalCall () {
	double notional;
	cout << "What notional would you like?" << endl;
	cout << "Notional = ";
	cin >> notional;
	return notional;
}

int main () {
	double bid;
	double offer;
	double payOff;
	double notional;
	double profitArbitrage;
	
	cout << "What are the bid and offer prices?" << endl;
	cout << "Bid: ";
	cin >> bid;
	cout << "Offer: ";
	cin >> offer;
	
	payOff = SpotArbitrage(bid, offer);
	cout << "Risk free profit per unit is: " << payOff << endl;
	
	if (payOff > 0) {
		notional = notionalCall();
		profitArbitrage = payOff * notional;
		cout << "Expected Riskless Profit: " << profitArbitrage << endl;
	} else {
		cout << "No arbitrage opportunity";
	}
	
}
