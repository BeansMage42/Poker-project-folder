
using namespace std;
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
	void NextMatch()//Jonah Gibson
	{
		//foreach(playerInRound) if(playerInRound.chips > 0) add to playersInRound
		// reset pot
		// reset deck
		// update ActivePlayers to players in match
		// reset cards displayed
		// deal new cards to playersInMatch
		// deal new cards to communityCards
		//

	}

	
};