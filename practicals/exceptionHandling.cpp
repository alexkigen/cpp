//example to demonstrate error handling; the error here is if a <> b
#include <iostream>

using namespace std;

double do_task (double a, double b) {
	double result;
	result = a * b;
	string msg = "Error";
	if (a == b) {
		return result;
	} else {
		throw msg;
	}
}

int main () {
	double a;
	double b;
	cout << "Enter a and b: " << endl;
	cin >> a >> b;
	double resultMain;
	
	try {
		resultMain = do_task(a, b);
		cout << resultMain;
	}
	catch (string msg) {
		cerr << msg;
	}
}
