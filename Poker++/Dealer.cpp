#include "Dealer.h"
#include <list>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<Card> currentDeck;
void Dealer::CreateDeck()
{
	deckSize = 0;

	for (int s = 0; s < 4; s++)
	{
		for (int v = 0; v < 13; v++)
		{
			currentDeck.push_back(Card(s, v));
			deckSize++;
		}
	}

}

Card Dealer::DrawCard()
{
	if (deckSize < 0) CreateDeck();
	int index = rand() % deckSize;
	Card temp = currentDeck.at(index);
	currentDeck.erase(currentDeck.begin() + index);
	deckSize--;

	return temp;
}




