/* demonstrate switch statement. First some notes:
1. can only use them with integers, characters and enumerations
2. cannot use strings
3. good practice to specify default treatment
4. must end each case section with break - compiler does not warn if you don't

To select using strings, must use if statements or maps
*/

#include <iostream>

using namespace std;

void countryCode (){
    int countryCode;
    cout << "Please enter the country code: " << endl;
    cin >> countryCode;

    while (countryCode < 300) {
        switch (countryCode) {
            case 254:
                cout << "I was born in Kenya. Lived here most of my younger life!!" << endl;
                break;
            case 1:
                cout << "I went to college in the United States and worked here for a good 4 years!!" << endl;
                break;
            case 267:
                cout << "I love Rwanda!" << endl;
                break;
            case 2: case 3: case 4: case 5: case 6:
                cout << "I have visited that country!!" << endl;
                break;
            default:
                cout << "I have not visited that country!!" << endl;
                break;
        }
    countryCode = 500; //to break while statement
    }
}

int main () {
    countryCode();
}
