using namespace std;
using namespace Game;
#include "Player.h"

class Bot: public Player {
	public:
		string name;
		float confidence;
		float greed;
	
		
		void PickAction()
		{
			/*
			if (confidence too low and greed too low)
				{
					Fold()
				}
			if (confidence high and greed high)
				{
					Raise()
				}
			if ((condience high and greed low) or (if confidence low and greed high))
				{
					Call()
				}
			*/
		}


		// Inspired by Jonah Gibson's code and adapted by Eugenio Morales
		Bot(Card card1, Card card2) : Player(card1, card2)
		{
			cout << name << "Bot Initialized \n";
		}
};