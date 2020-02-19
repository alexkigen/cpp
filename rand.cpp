#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
	
	int dice = 0;
	int count [6] = {0,0,0,0,0,0};
	
	srand (time(0)); //seed the random number
 
 for (int i = 1; i <= 10; i++) {
	
	dice = rand()%6 + 1;
	//cout << "You rolled a " << dice << endl;
	switch (dice) {
		case 1:
			count[0] = count[0] + 1;
			cout << dice;
			cout << count [0];
			break;
		case 2:
			count[1] = count[1] + 1;
			cout << dice;
			cout << count [1];
			break;
		case 3:
			count[2] = count[2] + 1;
			cout << dice;
			cout << count [2];
			break;
		case 4:
			count[3] = count[3] + 1;
			cout << dice;
			cout << count [3];
			break;
		case 5:
			count[4] = count[4] + 1;
			cout << dice;
			cout << count [4];
			break;
		case 6:
			count[5] = count[5] + 1;
			cout << dice;
			cout << count [5];
			break;	
	}
}
	//return count;
//}
	cout << count [0] << count [1] << count[2] << count [3] << count [4] << count [5];
	//return 0;		
}
