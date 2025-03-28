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
	int Score(Card* hand);
};
