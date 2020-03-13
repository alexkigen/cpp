#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "rps.hpp"

using namespace std;

int main () {
	string player_name;
	string user_play;
	string comp_play;
	string plays [3] = {"rock", "paper", "scissors"};
	int comp_index;
	bool restart = false;
	
	cout << "Hello, enter your name: " <<endl;
	cin  >> player_name;
	
	START:
		
	cout << "rock, paper or scissors? mind the case" << endl;
	cin  >> user_play;

	srand (time(0));
	comp_index = rand () % 3;
	comp_play = plays[comp_index];
	cout << "The computer chose " << comp_play << endl;
	
	//cout << player_name << declare_winner(player_name, comp_play, user_play) << endl;
	if (declare_winner(player_name, comp_play, user_play, restart) == true) {
		cout << player_name << declare_winner(player_name, comp_play, user_play) << endl;
		goto START;
	} else {
		cout << player_name << declare_winner(player_name, comp_play, user_play) << endl;
	}
	
	
}
