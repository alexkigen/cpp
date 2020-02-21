//create a class called Product, supply inputs using a Constructor, create functions to compute marginal and full profits
//and then print results out

#include <iostream>
 

 class Product {
     private:
     double price, cost, overhead;
     int sales;

     public:
     Product(double, double, double, int);

     double margProfit () {
        return sales * (price- cost);
    }

    double fullProfit () {
        return sales * (price - cost) - overhead;
    }

};

Product::Product(double price_, double cost_, double overhead_, int sales_) {
    price = price_;
    cost = cost_;
    overhead = overhead_;
    sales = sales_;

}

using namespace std;

int main () {
    Product prodX (20, 10, 100, 20); //one way of calling a constructor
    //Product prodX {50, 10, 100, 20}; //another way of calling a constructor;
    //Product prodZ = {20, 10, 100, 20}; //another way of calling a constructor;

    cout << "The marginal profit of prodX is " << prodX.margProfit() << endl;
    //cout << "The marginal profit of prodY is " << prodY.margProfit() << endl;
    //cout << "The marginal profit of prodZ is " << prodZ.margProfit() << endl;
}