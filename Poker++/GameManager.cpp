
using namespace std;


#include <algorithm>    // std::random_shuffle
#include <memory>
#include <random>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "GameManager.h"
#include "Dealer.h"
#include "Card.h"

class GameManager 
{
public:
	
	void IncreasePot(int chips) //Jonah Gibson
	{
		//Pot += chips
		// if( chips > highestBet) highestBet = chips;
		//NextTurn();

	}
	
	void PlayerOut() //Jonah Gibson
	{
		//remove ActivePlayer from PlayersInMatch
		//NextTurn();

	}
	

private:

	std::unique_ptr<Card> communityCards[5];//stores info of cards in the center
	//Card communityCards[5];//stores info of cards in the center
	Dealer* dealer;
	int playersChecked;//how many players have called check
	int cardsDisplayed;// how many cards are being displayed in the center
	int pot;//total cumulative amount of chips bet this match
	int highestBet;//highest bet this match for players trying to call
	int activePlayer;//index of the currently active player for turn order
	int numOfPlayers;//number of players in the game
	//declarations
	void StartGame();
	void DealNextCard();
	void CheckWinner();
	void NextMatch();
	//sections of this code is taken from jonah gibsons midterm

	int main() {
		StartGame();
		Card* ptr;
		for (activePlayer; activePlayer < 4; activePlayer++)
		{
			ptr = players[activePlayer]->GetHand();
			std::cout << "\n it is " << players[activePlayer]->name << "'s turn";
			std::cout << "\n Current pot = " << pot;
			std::cout << "\n Revealed cards are: ";
			for (Card card : communityCards)
			{
				//std::cout << EvaluateCard(card) << " , ";
			}
			std::cout << "\n Your hand is: " << EvaluateCard(ptr[0]) << " and " << EvaluateCard(ptr[1]);
			std::cout << "\n the highest bet this round is " << highestBet << "\n";

			int bet = players[activePlayer]->PlayerTurn(highestBet);
			if (bet > highestBet) highestBet = bet;
			//recalculates the total chips bet this round
			//done this way so the player class wont need a reference to the main class
			//and so that the highest bet can be recorded easier
			int temp = 0;
			for (int a = 0; a < 4; a++)
			{

				temp += players[a]->chipsBet;
			}
			pot = temp;

		}
		std::cout << "the ending pot is " << pot << endl;
		return 0;
	}
	//implimentations
	void StartGame()//Ryan Dean
	{
		pot = 0;
		highestBet = 0;
		activePlayer = 0;
		for (auto&& p : players) p->Reset();
		dealer = new Dealer();
		players[0] = std::make_unique<User>(dealer->DrawCard());

		for (int x = 1; x < 4; x++)
		{
			players[x] = std::make_unique<Bot>(dealer->DrawCard());
		}
	}
	void DealNextCard()//Jonah Gibson
	{
		//cardsDisplayed++
		//for(cards displayed) reveal communitycard;

	
	}
	void NextTurn()// Ryan Dean
	{
		bool allChecked;
		for(auto&& p:players)
		{
			if (!p->hasChecked)
			{
				allChecked = false;
				break;
			}
			else
			{
				allChecked = true;
			}
		}
		
		if(allChecked) DealNextCard();
		
		if(cardsDisplayed == 5 || activePlayer == numOfPlayers-1) CheckWinner();
		 
		else
		{
			activePlayer = (activePlayer + 1) % numOfPlayers;
			players[activePlayer]->SetActive();
		}
	}
	void CheckWinner()
	{
		// card cards[7];

		// int highestScore;
		// for (int i = 0; i < 5; i++)
		// {
		// 	cards[i] = communityCards[i];
		// }
		// foreach(playersInMatch)
		// {
		// 	//sets cards 6 and 7 to the current hand of the plalyer
		//
			// checks for flushes
		// 	// sorts cards and checks for straights and flushes
			// checks for duplicate cards

			// adds the values of the hands
			// compare to the previous highestScore and if its higher set this score to the highest score
		
		// }
		// highest score is te winner
		
	}
	float Score(Card* hand)
	{
		if (CheckRoyaleFlush(hand)) return 10 + HighCard(hand);
		if (CheckForStraights(hand) && CheckForFlush(hand)) return 9 + HighCard(hand);
		if (CheckForPairs(hand) == 4) return 8 + HighCard(hand);
		if (CheckForPairs(hand) == -10) return 7 + HighCard(hand);
		if (CheckForFlush(hand)) return 6 + HighCard(hand);
		if (CheckForStraights(hand)) return 5 + HighCard(hand);
		if (CheckForPairs(hand) == 3) return 4 + HighCard(hand);
		if (CheckForPairs(hand) == 2) return 3 + HighCard(hand);
		if (CheckForPairs(hand) == 1) return 2 + HighCard(hand);
		return 1 + HighCard(hand);
	}

	bool CheckForFlush(Card* hand)
	{
		int size = sizeof(communityCards) / sizeof(communityCards[0]);

		vector<Card> cardsToScore(communityCards, communityCards + size);

		// Add two more elements
		cardsToScore.push_back(hand[0]);
		cardsToScore.push_back(hand[1]);

		for (int i = 0; i < size; i++)
		{
			int count = 0;
			for (int j = 0; j < size; j++)
			{
				if (cardsToScore[i] == cardsToScore[j]) count++;
			}
            
			if (count >= 5) return true;
		}

		return false;
	}

	int CheckForPairs(Card* hand)
	{
		int size = sizeof(communityCards) / sizeof(communityCards[0]);

		vector<Card> cardsToScore(communityCards, communityCards + size);

		int highestCount = 0;

		// Add two more elements
		cardsToScore.push_back(hand[0]);
		cardsToScore.push_back(hand[1]);

		for (int i = 0; i < size; i++)
		{
			int count = 0;
			for (int j = 0; j < size; j++)
			{
				if (cardsToScore[i] == cardsToScore[j]) count++;
			}
            
			if (highestCount == 3 && count == 2) return -10;
			if (highestCount == 2 && count == 3) return -10;
			if (count >= highestCount) highestCount = count;
		}
		return highestCount;
	}

	bool CheckForStraights(Card* hand)
	{
		int size = sizeof(communityCards) / sizeof(communityCards[0]);

		vector<Card> cardsToScore(communityCards, communityCards + size);

		cardsToScore.push_back(hand[0]);
		cardsToScore.push_back(hand[1]);
		
		sort(cardsToScore.begin(), cardsToScore.end());

		int count = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (cardsToScore[i] == (cardsToScore[i + 1] - 1))
			{
				count++;
			}
			else
			{
				count = 0;
			}
            
			if (count >= 4) return true;
		}

		return false;
	}


	bool CheckRoyaleFlush(Card* hand)
	{
		int size = sizeof(communityCards) / sizeof(communityCards[0]);

		vector<Card> cardsToScore(communityCards, communityCards + size);

		cardsToScore.push_back(hand[0]);
		cardsToScore.push_back(hand[1]);

		if (!CheckForFlush(hand)) return false;
		if (!CheckForStraights(hand)) return false;
        
		sort(cardsToScore.begin(), cardsToScore.end());
		
		if (cardsToScore.end != 12) return false;
		return true;
	}

	float HighCard(Card* hand)
	{
		int highCard = -1;

		return hand[0].value > hand[1].value ? hand[0].value * 0.01f: hand[1].value * 0.01f;
	}
	

	void NextMatch()//Jonah Gibson
	{
		//foreach(playerInRound) if(playerInRound.chips > 0) add to playersInRound
		// reset pot
		// reset deck
		// update ActivePlayers to players in match
		// reset cards displayed
		// deal new cards to playersInMatch
		// deal new cards to communityCards
		//NextTurn();

	}
};