
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main () {

//    for (int i = 1; i <=10; i++) {
//        cout << i << endl;
//    }

//check implementation of vector. Need to load vector library before declaring vector type
    vector <int> v;// = {10, 11, 12};
    v[0] = 5;
    v[1] = 6;
    v[2] = 7;

    
    cout << v[1] << endl;

//to loop through every element of a vector. WHAT IS SEGMENTATION FAULT?
//    for (int x : v) {
//        cout << x << endl;
 //   }

//we can also specify the vector size - check implementation of this in C++11
   for (int y = 0; y < v.size(); ++y) {
        cout << y << endl;
   }
}
