#include "Dealer.h"
#include <list>
#include <vector>
#include <stdlib.h>
using namespace std;
class Dealer {
public:
	
	void CreateDeck()
	{
		int i = 0;

		for (int s = 0; s < 4; s++)
		{
			for (int v = 0; v < 13; v++)
			{
				currentDeck.push_back(Card(s, v));
			}
		}
		
	}

	Card DrawCard()
	{
		int index = rand() % currentDeck.size();
		Card temp = currentDeck.at(index);
		currentDeck.erase(currentDeck.begin()+ index);
		
		return temp;
	}

private:
	vector<Card> currentDeck;

};