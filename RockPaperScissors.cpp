#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
//#include "rps.hpp"

using namespace std;

int main () {
	string player_name;
	string user_play;
	string comp_play;
	string plays [3] = {"rock", "paper", "scissors"};
	int comp_index;
	
	cout << "Hello, enter your name: " <<endl;
	cin  >> player_name;
	
	START:
		
	cout << "rock, paper or scissors? mind the case" << endl;
	cin  >> user_play;

	srand (time(0));
	comp_index = rand () % 3;
	comp_play = plays[comp_index];
	cout << "The computer chose " << comp_play << endl;
	
	//cout << declare_winner(player_name, comp_play, user_play);
	
	if(comp_play == "rock") {
			if (user_play == "paper") {
				cout << player_name << " , you win!!";
			} else if (user_play == "scissors") {
				cout << "Computer wins. Sucker!";
			} else {
				cout << "Computer chose same as you. Go again" << endl;
				goto START;
			}
		}
		
	else if (comp_play == "paper") {
			if (user_play == "scissors") {
				cout << player_name << " , you win!!";
			} else if (user_play == "rock") {
				cout << "Computer wins. Sucker!";
			} else {
				cout << "Computer chose same as you. Go again" << endl;
				goto START;
			}
		}
		
	else if (comp_play == "scissors") {
			if (user_play == "rock") {
				cout << player_name << " , you win!!";
			} else if (user_play == "paper") {
				cout << "Computer wins. Sucker!";
			} else {
				cout << "Computer chose same as you. Go again" << endl;
				goto START;
			}
	}
	
	else {
		cout << "Check your entry for spelling and case!" << endl;
		goto START;
	}

}
