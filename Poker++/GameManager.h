#pragma once
using namespace Game;
#include <list>
#include "Player.h"
#include "Card.h"
class GameManager
{
public:
	void IncreasePot(int chips);
	void PlayerOut();
	float Score(Card* hand);
	bool CheckForFlush();
	bool CheckForStraight();
	bool CheckForRoyalFlush();
	bool CheckForFullHouse();
	bool CheckForPair();
	bool CheckForHighCard();
	void CheckForWinner();
};
