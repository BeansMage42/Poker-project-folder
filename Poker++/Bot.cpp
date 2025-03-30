using namespace std;
using namespace Game;
#include "Player.h"

//Bot.cpp was primarily developped by Adriel-Anthony Anderson

class Bot : public Player {
public:
	string name;
	hasFolded = false;
	srand(time(0));
	handScore = rand() % 12 + 1;

	int Bot::Fold()
	{
		cout << name << " has folded! \n";
		hasFolded = true;
		return 0;
	}

	if (handScore < 6)
	{
		Fold();
	}
	
	


	// Inspired by Jonah Gibson's code and adapted by Eugenio Morales
	Bot(Card card1, Card card2) : Player(card1, card2)
	{
		cout << name << "Bot Initialized \n";
	}
};