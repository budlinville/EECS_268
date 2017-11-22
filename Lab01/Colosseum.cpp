#include "Colosseum.h"

Colosseum::Colosseum(){
	d20 = Dice(20);
	d6 = Dice(6);
}

void Colosseum::userBuild(Pokemon* p){
	std::string name = "";
	int hp = 0;
	int attackLevel = 0;
	int defenseLevel = 0;
	bool validInput = false;

	std::cout << "Please name your Pokemon: ";
	while (validInput == false){
		std::cin >> name;
		if (name.length() < 1){
			std::cout << "Your name must be at least 1 character long." << std::endl;
			validInput = false;
		} else{
			validInput = true;
		}
	}
	validInput = false;	//reset
	p->setName(name);

	std::cout << "How many hit points will it have? (1-50): ";
	while(validInput == false){
		std::cin >> hp;
		if (hp > 50 || hp < 1){
			std::cout << "Please enter valid input: ";
			validInput = false;
		} else {
			validInput = true;
		}
	}
	validInput = false;	//reset
	p->setHP(hp);

	std::cout << "Split 50 points between attack and defense." << std::endl;

	std::cout << "Enter your attack level (1-49): ";
	while(validInput == false){
		std::cin >> attackLevel;
		if (attackLevel > 49 || attackLevel < 1){
			std::cout << "Please enter valid input: ";
			validInput = false;
		} else {
			validInput = true;
		}
	}
	validInput = false;	//reset
	p->setAttackLevel(attackLevel);

	std::cout << "Enter your defense level (1-" << (50 - attackLevel) << "): ";
	while(validInput == false){
		std::cin >> defenseLevel;
		if (defenseLevel < 1 || defenseLevel > (50 - attackLevel)){
			std::cout << "Sorry. The defense level must be between 1 and " << (50 - attackLevel) << ".";
			validInput = false;
		} else {
			validInput = true;
		}
	}
	validInput = false;	//reset
	p->setDefenseLevel(defenseLevel);
}

bool Colosseum::attack(const Pokemon* attacker, Pokemon* defender){
	int attackBonus = d20.roll();
	int defenseBonus = d20.roll();
	int attackLevel = attacker->getAttackLevel();
	int defenseLevel = defender->getDefenseLevel();
	int damage = 0;
	bool pokemonDied = false;
	int roll1, roll2, roll3;

	std::cout << attacker->getName() << " is attacking " << defender->getName() << std::endl;
	std::cout << attacker->getName() << " rolls an attack bonus of " << attackBonus << std::endl;
	std::cout << defender->getName() << " rolls a defense bonus of " << defenseBonus << std::endl;

	if ((attackLevel + attackBonus) > (defenseLevel + defenseBonus)){
		std::cout << "The attack hits dealing 3-DG damage!" << std::endl;

			roll1 = d6.roll();
			roll2 = d6.roll();
			roll3 = d6.roll();
			damage = roll1 + roll2 + roll3;

		std::cout << "The rolls are " << roll1 << ", " << roll2 << ", and " << roll3 << " totaling: " << damage << " damage!" << std::endl;

		defender->reduceHP(damage);
	} else {
		std::cout << "The attack missed!" << std::endl;

	}

	if (defender->getHP() < 1){
		pokemonDied = true;
	} else {
		pokemonDied = false;
	}
	return pokemonDied;
}

//start here
void Colosseum::play(Pokemon* p1, Pokemon* p2){
	Dice d2 = Dice(2);
	int coinFlip = d2.roll();
	bool p1Dead = false;
	bool p2Dead = false;
	bool gameOver = false;
	int roundNumber = 1;

	std::cout << "Choosing which player to go first:" << std::endl;

	if (coinFlip == 1){
		std::cout << "Player 1 will go first." << std::endl;
		while(gameOver == false){

			std::cout << std::endl << "Round " << roundNumber << "!" << std::endl << std::endl;

			p1Dead = attack(p1, p2);
			if (p2Dead == true){
				std::cout << p2->getName() << " has been defeated!" << std::endl;
				gameOver = true;
			} else {
				std::cout << p2->getName() << " has " << p2->getHP() << " hitpoints left." << std::endl;
				p1Dead = attack(p2, p1);
				if (p1Dead == true){
					std::cout << p1->getName() << " has been defeated!" << std::endl;
					gameOver = true;
				} else{
					std::cout << p1->getName() << " has " << p1->getHP() << " hitpoints left." << std::endl;
				}

			}

			roundNumber++;
		}
	} else if (coinFlip == 2){
		std::cout << "Player 2 will go first." << std::endl;
		while(gameOver == false){

			std::cout << std::endl << "Round " << roundNumber << "!" << std::endl << std::endl;
			p1Dead = attack(p2, p1);
			if (p1Dead == true){
				std::cout << p1->getName() << " has been defeated!" << std::endl;
				gameOver = true;
			} else {
				std::cout << p1->getName() << " has " << p1->getHP() << " hitpoints left." << std::endl;
				p2Dead = attack(p1, p2);
				if (p2Dead == true){
					std::cout << p2->getName() << " has been defeated!" << std::endl;
					gameOver= true;
				} else{
					std::cout << p2->getName() << " has " << p2->getHP() << " hitpoints left." << std::endl;
				}

			}

		if (roundNumber >= 10){
			gameOver = true;
			std::cout << "Round 10 has been reached with no clear winner. It's a draw." << std::endl;
		}

		roundNumber++;
		}
	}


}
