/* learn:
- assert function
- puts function
- abort function

*/

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

void fnExit1 (void)
{
  puts ("Exit function 1.");
}

void exitValue () {
	puts ("b is greater than a"); //writes the string and appends end of line character;
}

int main () {
	int a, b;
	a = 4;
	b = 3;
		
	assert (a > b); //if a < b the program will stop running
		
	atexit(exitValue);
	
	cout << a << endl;
	
	//abort(); //will stop the program from continuing
	cout << b << endl;
	
	atexit(fnExit1);
	
	cout << "wow" << endl;
	
	puts ("This actually works!");
}
