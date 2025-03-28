#pragma once
#include <list>
using namespace Game;
#include "Player.h"
#include "Card.h"
class GameManager
{
public:
	void IncreasePot(int chips);
	void PlayerOut();
};
