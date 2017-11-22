PokemonBattle: main.o Colosseum.o Pokemon.o dice.o
	g++ -std=c++11 -g -Wall main.o Colosseum.o Pokemon.o dice.o -o PokemonBattle

main.o: main.cpp Colosseum.h
	g++ -std=c++11 -g -Wall -c main.cpp

Colosseum.o: Colosseum.h Colosseum.cpp Pokemon.h dice.h
	g++ -std=c++11 -g -Wall -c Colosseum.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp
dice.o: dice.h dice.cpp
	g++ -std=c++11 -g -Wall -c dice.cpp
clean:
	rm *.o PokemonBattle
