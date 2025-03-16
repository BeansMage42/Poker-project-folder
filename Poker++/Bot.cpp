using namespace std;
#include "Player.h"

class Bot : public Player {
public:
	string name;
	float confidence;
	float greed;

	void Input();
	void PickAction();
};