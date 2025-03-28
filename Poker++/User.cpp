using namespace std;
using namespace Game;
#include "Player.h"
#include <iostream>
#include <string>

class User: public Player  {
public:
	void Input()
	{
		//if player presses enter
			//StartGame()
		//if player presses 1
			//If player's bet matches previous
				//Check()
			//If player's bet does not match previous
				//Call()
		//if player presses 2
			//Fold()
		//if player presses 3
			//Input amount
			//Raise(amount)
		//if player presses esc
			//Quit application
	}

	// Inspired by Jonah Gibson's code and adapted by Eugenio Morales
	User(Card card1, Card card2) : Player(card1, card2) 
	{
		name = "Player 1";
		cout << "User Initialized \n";
	}



};