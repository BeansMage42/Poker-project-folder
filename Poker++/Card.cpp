
#include "Card.h"

namespace Game {
	Card::Card(int v, int s) {
		value = v;
		suit = s;
	}
	Card::Card() 
	{
		value = 0;
		suit = 0;
	}
}