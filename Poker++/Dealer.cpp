#include "Dealer.h"
#include <list>
using namespace std;
class Dealer {
public:
	void CreateDeck();
	Card DrawCard();

private:
	Card referenceDeck[52];
	list<Card> currentDeck;



};