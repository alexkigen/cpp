//create a class called Product, supply inputs using a function (not constructors), create functions to compute marginal and full profits
//and then print results out


#include <iostream>

using namespace std;

class Product {
    private:
    double price_pu, cost_pu, overhead;
    int sales;

    public:
    void set_values (double, double, double, int);
    
    double margProfit () {
        return sales * (price_pu - cost_pu);
    }

    double fullProfit () {
        return sales * (price_pu - cost_pu) - overhead;
    }

};

void Product::set_values (double pricePU, double costPU, double overhead_, int sales_) {
    price_pu = pricePU ;
    cost_pu = costPU ;
    overhead = overhead_ ;
    sales = sales_;
}

int main () {
    Product prodA, prodB;
    prodA.set_values(20, 10, 100, 20);
    prodB.set_values(20, 10, 100, 10);

    cout << "Product A has marginal profit of " << prodA.margProfit() << " and a full profit of " << prodA.fullProfit() << endl;
    cout << "Product B has marginal profit of " << prodB.margProfit() << " and a full profit of " << prodB.fullProfit() << endl;

    return 0;
}