#include <memory>
#include <random>
#include "GameManager.h"
#include "Player.h"
#include <iostream>
#include <Card.h>

#include "string"
using namespace std;
using namespace Game;

//Bot.cpp was primarily developped by Adriel-Anthony Anderson

int handScore;

class Bot : public Player {
public:
	string name;

	int Bot::Fold() override
	{
		cout << name << " has folded! \n";
		hasFolded = true;
		return 0;
	}

	// Inspired by Jonah Gibson's code and adapted by Eugenio Morales
	Bot(Card card1, Card card2) : Player(card1, card2)
	{
		cout << name << "Bot Initialized \n";
		handScore = rand() % 12 + 1;
		hasFolded = false;
		srand(time(0));
	}
};
