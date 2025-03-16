
using namespace std;
#include "GameManager.h"

class GameManager 
{
public:
	void IncreasePot(int chips){}
	void NextTurn(){}
	void PlayerOut(){}
	

private:

	list<Player> playersInMatch;
	list<Player> playersInRound;
	Card communityCards[5];
	int playersChecked;
	int cardsDisplayed;
	int pot;
	int highestBet;
	int activePlayer;
	int numOfPlayers;
	//declarations
	void StartGame();
	void DealNextCard();
	void CheckWinner();
	void NextMatch();
	//implimentations
	void StartGame(){}
	void DealNextCard(){}
	void CheckWinner(){}
	void NextMatch(){}
};