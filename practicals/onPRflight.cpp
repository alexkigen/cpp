#include <iostream>

using namespace std;

double area (double r_) {
    const double pi = 3.14;
    double area;

    area = pi*r_*r_;
    
    return area;
}

int main () {
    cout << area(2) << endl;
    double a = 9;
    double b = 5;

    cout << 9/5 << endl;
    cout << 9.0/5 << endl;
    cout << a/b << endl;

//user input and treatment of white space/no space and two different data types e.g. double and char
    double length = 1;
    char unit = 'l'; //this is how we specify characters: using char and in single quotes.
    double cm_per_inch = 2.54;

    cout << "Enter the length and unit";
    cin >> length >> unit;
    cout << length << " and " << unit << endl;

    if (unit == 'i') {
        cout << length << " inches == " << cm_per_inch *length << " centimeters" << endl;
    } else if (unit == 'c') {
        cout << length << " centimeters == " << (1/cm_per_inch)*length << " inches" << endl;
    } else {throw "Sorry - input not defined";}
}

/*methods of incrementing
a++
a += 1
a = a + 1
*/
