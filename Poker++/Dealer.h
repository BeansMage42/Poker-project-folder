#pragma once
#include "Card.h"

using namespace Game;

class Dealer {
public:
	int deckSize;
	int deckDepth;
	void CreateDeck();
	Card DrawCard();
};