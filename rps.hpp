#ifndef _rps_hpp
#define _rps_hpp
#include <string>

//using namespace std;

std::string declare_winner (std::string player_name, std::string comp_play, std::string user_play) {
	bool restart = false;
	
	if(comp_play == "rock") {
			if (user_play == "paper") {
				return (", you win!!");
			} else if (user_play == "scissors") {
				return (", you lost. Sucker!");
			} else {
				//restart = true;
				return (", computer chose same as you. Go again");
			}
		}
		
	else if (comp_play == "paper") {
			if (user_play == "scissors") {
				return (", you win!!");
			} else if (user_play == "rock") {
				return (", you lost. Sucker!");
			} else {
				//restart = true;
				return ", computer chose same as you. Go again";
			}
		}
		
	else if (comp_play == "scissors") {
			if (user_play == "rock") {
				return (", you win!!");
			} else if (user_play == "paper") {
				return (", computer wins. Sucker!");
			} else {
				//restart = true;
				return (", computer chose same as you. Go again");
			}
	}
	
	else {
		return ("Check your entry for spelling and case!");
		restart = true;
	}
	
	return 0;
}

bool declare_winner (std::string player_name, std::string comp_play, std::string user_play, bool restart) {
	restart = false;
	
	if(comp_play == "rock") {
			if (user_play == "paper") {
				return restart;
			} else if (user_play == "scissors") {
				return restart;
			} else {
				restart = true;
				return restart;
			}
		}
		
	else if (comp_play == "paper") {
			if (user_play == "scissors") {
				return restart;
			} else if (user_play == "rock") {
				return restart;
			} else {
				restart = true;
				return restart;
			}
		}
		
	else if (comp_play == "scissors") {
			if (user_play == "rock") {
				return restart;
			} else if (user_play == "paper") {
				return restart;
			} else {
				restart = true;
				return restart;
			}
	}
	
	else {
		restart = true;
		return restart;
	}
	
	return 0;
}

#endif
