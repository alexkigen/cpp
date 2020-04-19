//illustrate CAPM in C++

#include <iostream>

double capm (double riskFreeRet, double marketRet, double beta) {

    double stockRet = riskFreeRet + beta * (marketRet - riskFreeRet);

    return stockRet;
}

double beta (double cor, double marketVol, double stockVol) {

    double cov = cor * marketVol * stockVol;
    double betaStock = cov/(marketVol*marketVol);

    return betaStock;
}

using namespace std;

int main () {

    cout << capm(0.02,0.08, 1.0) << endl;
    cout << capm(0.02,0.08, beta(0.5, 0.15, 0.75)) << endl;
}
