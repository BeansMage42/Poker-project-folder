using namespace std;
#include "Player.h"

class Bot : public Player {
	public:
		string name;
		float confidence;
		float greed;
	
		void Input();
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
};