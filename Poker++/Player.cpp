
#include "GameManager.h"

class Player {
	


public:
	static Card currentHand[2];
	bool isActive;
	bool hasChecked;
	int chips;
	int chipsBet;
	void SetActive(){}

	void SetHand(Card[2]){}

	Card* GetHand(){}

	void addChips(int chipsAdd){}

    int GetChips(){}

protected:
	//declaration
	void Check();
		
	void Raise(int amount);
		
	void Call();
		
	void Fold();
	//implimentation

	void Check(){}

	void Raise(int amount){}

	void Call(){}

	void Fold(){}
	
	
		



};