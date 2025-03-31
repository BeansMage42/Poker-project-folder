#include "Dealer.h"
#include <list>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <random>
using namespace std;
vector<Card> currentDeck;
void Dealer::CreateDeck()
{
	deckSize = 0;
	deckDepth = 0;
	for (int s = 0; s < 4; s++)
	{
		for (int v = 0; v < 13; v++)
		{
			currentDeck.push_back(Card(v, s));
			//cout << currentDeck[deckSize].value << "<- value and -> suit" << currentDeck[deckSize].suit << endl;
			deckSize++;
		}
	}

}

Card Dealer::DrawCard()
{
	if (deckSize < 0) CreateDeck();
	std::random_device rd;  // Seed from hardware
	std::mt19937 gen(rd());
	int index = rand() % deckSize;
	Card temp = currentDeck.at(index);
	//cout << "Drawing card at index: " << index << endl;
	currentDeck.erase(currentDeck.begin() + index-1);
	deckSize--;

	return temp;
}




