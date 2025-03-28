
using namespace std;
using namespace Game;
#include <algorithm>    // std::random_shuffle
#include <memory>
#include <random>
#include "Player.h"
#include "GameManager.h"

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

	list<Player> playersInMatch;//all the players in the current match that havent folded
	list<Player> playersInRound;//all the players that havent lost all their chips
	Card communityCards[5];//stores info of cards in the center
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
		using namespace Game;


		int deck[52];
		int activePlayer = 0;
		int highestBet = 5;
		int currentPot = 20;
		int commCards[5];
		int deckDepth = 0;
		//creates an array of ints from 0-51
		for (int i = 0; i < 52; i++)
		{
			deck[i] = i;
		}
		//the ability to shuffle the deck was found here https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements
		std::random_device rd;   //when i couldnt figure out why the deck would have duplicate cards using the stack overflow method, I asked chatgpt for help https://chatgpt.com/share/67e20dfb-68ac-8006-b542-35dc1d2be754
		std::mt19937 rng(rd());
		//shuffles the deck
		std::shuffle(std::begin(deck), std::end(deck), rng);

		//grabs the top 5 cards of the deck
		for (deckDepth; deckDepth < 5; deckDepth++)
		{
			commCards[deckDepth] = deck[deckDepth];
		}

		//this reddit comment helped me figure out how to make an array using unique pointers https://www.reddit.com/r/learnprogramming/comments/lp15tn/comment/go8rtdg/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
		std::unique_ptr<Player> players[4];

		players[0] = std::make_unique<User>(deck[deckDepth++], deck[deckDepth++]);

		for (int x = 1; x < 4; x++)
		{

			players[x] = std::make_unique<Bot>(x, deck[deckDepth++], deck[deckDepth++]);
		}
		int* ptr;
		for (activePlayer; activePlayer < 4; activePlayer++)
		{
			ptr = players[activePlayer]->GetHand();
			std::cout << "\n it is " << players[activePlayer]->name << "'s turn";
			std::cout << "\n Current pot = " << currentPot;
			std::cout << "\n Revealed cards are: ";
			for (int card : commCards)
			{
				std::cout << EvaluateCard(card) << " , ";
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
			currentPot = temp;

		}
		std::cout << "the ending pot is " << currentPot << endl;


		return 0;
	}
	//implimentations
	void StartGame()//Jonah Gibson
	{
		//foreach(player in round) reset all their variables to the defaults
		//reset deck to defaults
		//reset pot, highest bid and active players
	
	}
	void DealNextCard()//Jonah Gibson
	{
		//cardsDisplayed++
		//for(cards displayed) reveal communitycard;

	
	}
	void NextTurn()// Jonah Gibson
	{
		//RenderTable();
		//bool allChecked
		//foreach(player in match){
		//if(!player.hasChecked){
		// allChecked = false
		// break;
		// 
		// }
		// else allChecked = true
		//}
		// 
		//if(allChecked) DealNextCard();
		//
		// if(cardsDisplayed == 5 || activePlayers == 1) CheckWinner();
		// 
		// else{
		//activePlayer = (activePlayer + 1) % numOfPlayers
		//PlayersInMatch[activePlayer].SetActive();
		//}


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

	void RenderTable() //Ryan Dean
	{
		// render pairs of the back of card texture at the top and left sides of screen and place their number of chips and amount bet next to them
		//for(int i = 0; i < cards
		//for(int i = 0; i < 5;i++ )
		// {
		//		if(i < cardsDisplayed)
		//      {
		//			render front face from code of communityCards[i]
		//      }
		//		else
		//		{
		//			render back face texture
		//		}
		//	
		// }
		//type pot amount
		//render players hand cards at bottom and type out instructions for next move
	}
	
};