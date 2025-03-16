#pragma once
class Card {
public:
	int value;
	int suit;
	image cardTexture;

	Card(int v, int s) {
		value = v;
		suit = s;
	}
	Card();


};