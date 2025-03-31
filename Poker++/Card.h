#ifndef CARD_H
#define CARD_H

namespace Game {
	class Card {
	public:
		int value;
		int suit;

		Card(int v, int s);
		Card();
	};
}
#endif