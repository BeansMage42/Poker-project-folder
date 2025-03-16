#pragma once
#include <list>
#include "Player.h"
#include "Card.h"
class GameManager
{
public:
	void IncreasePot(int chips);
	void NextTurn();
	void PlayerOut();
};
