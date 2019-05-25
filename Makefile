all: Game

Game: Player.o Game.cpp
	g++ Player.o Game.cpp -o Game

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

clean:
	rm Player.o
	rm Game

run:
	./Game
