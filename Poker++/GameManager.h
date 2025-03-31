#pragma once

#include <list>
#include "Player.h"
#include "Card.h"
#include <string>
using namespace Game;
class GameManager
{
public:
	GameManager();
	float Score(Card* hand);
	bool CheckForFlush(Card* hand);
	bool CheckForStraights(Card* hand);
	bool CheckRoyaleFlush(Card* hand);
	int CheckForPairs(Card* hand);
	float HighCard(Card* hand);
	void CheckWinner();
	void StartGame();
	void DealNextCard();
	std::string EvaluateCard(Card card);
	std::string EvaluateHandType(float hand);
	void NextMatch();
	void NextTurn();
	
};
