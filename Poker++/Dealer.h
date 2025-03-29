#pragma once
#include "Card.h"

using namespace Game;

class Dealer {
public:
	void CreateDeck();
	Card DrawCard();
};