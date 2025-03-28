
using namespace std;
using namespace Game;
#include <algorithm>    // std::random_shuffle
#include <memory>
#include <random>
#include "Player.h"
#include "GameManager.h"
#include "Dealer.h"

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

	std::unique_ptr<Player> players[4];//all the players in the current match that havent folded
	Card communityCards[5];//stores info of cards in the center
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
	int score(Card* hand)
	{

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