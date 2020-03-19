
#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<double> temps;

    for (double temp; cin >> temp; ) {
        temps.push_back(temp);
    }

    cout << temps[2]*temps[1] << endl;
    
    double totalSum = 0;
    double average;

//sum by sequencing along the vector. In this example, x actually assumes the value of each component of temps
//note that x must take the same variable type as temps for consistent results
//if we used int x in the for function below, it would truncate the components of temps

    for (double x : temps) {
        totalSum += x;
        cout << "Rolling sum is " << totalSum << endl;
    }

    average = totalSum/temps.size();

    cout << "Total Sum = " << totalSum << endl;
    cout << "Average = " << average << endl;

    vector<double> temps_sorted = temps;
    sort(temps_sorted.begin(), temps_sorted.end());

    double medianTemp = temps[temps.size()/2];
    double medianTempSort = temps_sorted[temps_sorted.size()/2];

    cout << "Median temperature before sorting is " << medianTemp << endl;
    cout << "Median temparature after sorting is " << medianTempSort << endl;

}

//use any character that is not an integer or double to terminate. Could use / + ENTER for example. Or ESC + ENTER.