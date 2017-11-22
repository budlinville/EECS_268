#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"

int main(){
	bool stopPlaying = false;
	std::string yesOrNo = "";

	while(stopPlaying == false){
		Pokemon* pk1 = new Pokemon();
		Pokemon* pk2 = new Pokemon();

		Colosseum battleGround;

		std::cout << "Player 1, build your Pokemon!" << std::endl << "====================" << std::endl;
		battleGround.userBuild(pk1);

		std::cout << "Player 2, build your Pokemon!" << std::endl << "====================" << std::endl;
		battleGround.userBuild(pk2);

		battleGround.play(pk1, pk2);

		std::cout << "Do you want to play again? (y/n): " << std::endl;
		std::cin >> yesOrNo;

		if (yesOrNo == "y"){
			stopPlaying = false;
		} else {
			stopPlaying = true;
		}
	}

	std::cout << "Thanks for playing!" << std::endl;

	return 0;
}
