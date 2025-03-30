#pragma once
#include "Card.h"

using namespace Game;

class Dealer {
public:
	int deckSize;
	void CreateDeck();
	Card DrawCard();
};