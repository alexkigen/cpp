//demonstrate maps basics

#include <iostream>
#include <cmath>
#include <map>


using namespace std;

int main () {
    
    //example 1
    map <string, int> words;
    
    for (string s; cin >> s; ) {
        ++ words[s];
    }

    for (const auto &p : words) {
        cout << p.first <<": " << p.second << "/n";
    }

    //example 2
    map <string, double> matrixA;

    matrixA.insert(make_pair("Blessed", 42));

    for (auto look : matrixA) {
        cout << look.first << " : " << look.second << endl;
        
        double value = sqrt(look.second);
        cout << value << endl;
    }
}

/*Mapping
- define using map<type, type> objectName
- add entries using objectName.insert(make_pair(dim1, dim2))
- call entries of map by looping through every key-value pair of objectName
- first can be used to call key and second can be used to call value
- can use auto to automatically get the type of the key/values stored in the map
*/