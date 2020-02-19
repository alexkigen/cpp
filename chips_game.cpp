#include <iostream>
#include <cmath>
#include <iomanip>  //used by setprecision to set decimal places e.g. setprecision(2) should give 2.98
#include <cstdlib>
#include <ctime>
#include "playernames.hpp"


using namespace std;

//string findplayername (string names[], bool player_turn) {
//	if (player_turn == true) {
//		return names[0];
//	} else {
//		return names[1];
//	}
//}

const int MAX_CHIPS = 100;
const float MAX_TURN  = 0.5;

int main () {
	bool player1Turn = true;
	bool gameOver 	 = false;
	bool play_again  = false;
	
	int chipsinpile = 0;
	int chipstaken = 0;
	
	string playerNames[2];
	
	//seed the randon number generator
	srand (time(0));
	
	//ask players for their names, then store in an array
	cout << "Player 1, please enter your name: ";
	cin  >> playerNames[0];
	cout << "Player 2, please enter your name: ";
	cin  >> playerNames[1];
	cout << "Thank you and Good Luck to you both!" << endl;
	
	//start the game with a random number of chips in the pile
	START:
	chipsinpile = rand() % MAX_CHIPS + 1;
	cout << "This round will start with " << chipsinpile << " chips in the pile" << endl;
	
	while (gameOver == false || play_again == true) {
		
		do {
			cout << findplayername (playerNames, player1Turn) << " , how many chips would you like?" << endl;
			
			cout << "You can take up to ";
			if (static_cast<int>(MAX_TURN * chipsinpile) == 0) {
				cout << "1"<< endl;
			} else {
				cout << static_cast<int>(MAX_TURN * chipsinpile) << endl;
			}
			cin >> chipstaken;
		}
		while ((chipstaken > static_cast<int>(MAX_TURN * chipsinpile)) && (chipsinpile > 1));
		
	chipsinpile = chipsinpile - chipstaken;
	cout << "There are " << chipsinpile << " chips left in the pile" << endl;
	
	if (chipsinpile == 0) {
		gameOver = true;
		cout << findplayername (playerNames, player1Turn) << ", Congratulations!! You've won!" << endl;
		cout << "Do you wish to play again? 1 for Yes or 0 for No: " << endl;
		cin  >> play_again;
		
		if (play_again == true) {
			goto START;
		} else {
		cout << "Goodbye!!";
		}
		
	} else {
		player1Turn =! player1Turn;
	}
 }
 
 return 0;
 		
}


