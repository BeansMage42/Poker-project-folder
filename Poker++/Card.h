#pragma once
namespace Game {
	class Card {
	public:
		int value;
		int suit;

		Card(int v, int s);
		Card();
	};
}