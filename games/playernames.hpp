#ifndef playernames_hpp
#define playernames_hpp
#include <string>


std::string findplayername (std::string names[], bool player_turn) {
	if (player_turn == true) {
		return names[0];
	} else {
		return names[1];
	}
}

#endif
