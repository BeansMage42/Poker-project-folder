


using namespace std;
#include <memory>
#include <random>
#include "GameManager.h"

#include <algorithm>

#include "Dealer.h"
#include "Player.h"

#include "string"

using namespace Game;

//std::unique_ptr<Card> communityCards[5];//stores info of cards in the center
std::unique_ptr<Player> players[4];//stores info of cards in the center
Card communityCards[5];//stores info of cards in the center
std::unique_ptr<Dealer> dealer;
int playersChecked;//how many players have called check
int cardsDisplayed;// how many cards are being displayed in the center
int pot;//total cumulative amount of chips bet this match
int highestBet;//highest bet this match for players trying to call
int activePlayer;//index of the currently active player for turn order
int numOfPlayers;//number of players in the game
int loopCount = 0;
//declarations

//sections of this code is taken from jonah gibsons midterm


//implimentations
GameManager::GameManager() 
{
	StartGame();
}
void GameManager::StartGame()//Jonah
{
	
	pot = 20;
	highestBet = 5;
	activePlayer = 0;
	//for (auto&& p : players) p->Reset();
	dealer = std::make_unique<Dealer>();
	dealer->CreateDeck();
	for (int i = 0; i < 5; i++) {
		communityCards[i] = dealer->DrawCard();
	}
	players[0] = std::make_unique<User>(dealer->DrawCard(), dealer->DrawCard());

	for (int x = 1; x < 4; x++)
	{
		players[x] = std::make_unique<Bot>(dealer->DrawCard(), dealer->DrawCard());
	}
	DealNextCard();
	DealNextCard();
	DealNextCard();
	NextTurn();
}
void GameManager::DealNextCard()//Jonah Gibson
{
	cardsDisplayed++;
}
void GameManager::NextTurn()// Ryan Dean
{
	

	//some of this code borrowed from jonahs midterm
	
		if (!players[activePlayer]->hasFolded) {
			Card* ptr;
			ptr = players[activePlayer]->GetHand();
			std::cout << "\n it is " << players[activePlayer]->name << "'s turn";
			std::cout << "\n Current pot = " << pot;
			std::cout << "\n Revealed cards are: ";
			for (int l = 0; l < cardsDisplayed; l++)
			{

				std::cout << EvaluateCard(communityCards[l]) << " , ";
			}
			std::cout << "\n Your hand is: " << EvaluateCard(ptr[0]) << " and " << EvaluateCard(ptr[1]);
			std::cout << "\n the highest bet this round is " << highestBet << "\n";
			int bet = players[activePlayer]->SetActive(highestBet, Score(ptr));
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
		activePlayer = (activePlayer + 1) % 4;
		bool allChecked = false;

		if (activePlayer == 3)
		{
			
			for (auto&& p : players)
			{
				cout << p->name << " checking shit" << p->hasChecked;
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
			for (auto&& p : players)
			{
				if (!p->hasFolded) {
					p->hasChecked = false;
				}
			}
		}
		int numFolded = 0;
		for (auto&& p : players)
		{
			if (p->hasFolded)
			{
				numFolded++;
			}
		}

		if (allChecked) DealNextCard();

		if (cardsDisplayed == 5 || numFolded == 3)
		{
			CheckWinner();
			
		}
		else {
			loopCount++;
			if (loopCount >= 100) return;

			NextTurn();


		}
}
void GameManager::CheckWinner()//jonah gibson
{
	float highestScore = Score(players[0]->GetHand());
	players[0]->RemoveChipsBet();
	int winningPlayer = 0;

	for (int i = 1; i < 4; i++)
	{
		
		if (!players[i]->hasFolded && players[i]->chips > 0)
		{
		cout << players[i]->hasFolded << " foldcheck" << endl;
			float newScore = Score(players[i]->GetHand());
			if (newScore > highestScore) {
				winningPlayer = i;
				highestScore = newScore;
			}
		}
		players[i]->RemoveChipsBet();
	}

	cout << players[winningPlayer]->name << " won with a " << EvaluateHandType(highestScore) << " earning " << pot << " chips\n";
	players[winningPlayer]->addChips(pot);
	NextMatch();
}

void GameManager::NextMatch()//Jonah Gibson
{
	cout << "Starting next match";
	highestBet = 5;
	cardsDisplayed = 3;
	dealer->CreateDeck();
	for (int x = 0; x < 5; x++) {
		communityCards[x] = dealer->DrawCard();
	}
	for (int i = 0; i < 4; i++)
	{
		if (players[i]->chips > 0)
		{
			players[i]->chipsBet = 5;
			pot += 5;
			players[i]->hasFolded = false;

			players[i]->SetHand(dealer->DrawCard(), dealer->DrawCard());
		}

	}
	activePlayer = 0;
	NextTurn();
}

string GameManager::EvaluateHandType(float handL)//JOnah Gibson
{
	int hand = std::floor(handL);
	string type;
	switch (hand)
	{
	default:
		type = "High Card";
		break;
	case 2:
		type = "Pair";
		break;
	case 3:
		type = "Two Pair";
		break;
	case 4:
		type = "Three of a kind";
		break;
	case 5:
		type = "Straight";
		break;
	case 6:
		type = "Flush";
		break;
	case 7:
		type = "Full House";
		break;
	case 8:
		type = "Four of a kind";
		break;
	case 9:
		type = "Straight flush";
		break;
	case 10:
		type = "Royal flush";
		break;
	}
	return type;
}
float GameManager::Score(Card* hand)//Zachary Obrien and all the checks
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

bool GameManager::CheckForFlush(Card* hand)
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
			if (cardsToScore[i].suit == cardsToScore[j].suit) count++;
		}

		if (count >= 5) return true;
	}

	return false;
}

int GameManager::CheckForPairs(Card* hand)
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
			if (cardsToScore[i].value == cardsToScore[j].value) count++;
		}

		if (highestCount == 3 && count == 2) return -10;
		if (highestCount == 2 && count == 3) return -10;
		if (count >= highestCount) highestCount = count;
	}
	return highestCount;
}

bool GameManager::CheckForStraights(Card* hand)
{
	int size = sizeof(communityCards) / sizeof(communityCards[0]);

	vector<int> cardsToScore;

	for (Card num : communityCards) {
		cardsToScore.push_back(num.value);
	}

	cardsToScore.push_back(hand[0].value);
	cardsToScore.push_back(hand[1].value);

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


bool GameManager::CheckRoyaleFlush(Card* hand)
{
	int size = sizeof(communityCards) / sizeof(communityCards[0]);

	vector<int> cardsToScore;

	for (Card num : communityCards) {
		cardsToScore.push_back(num.value);
	}

	cardsToScore.push_back(hand[0].value);
	cardsToScore.push_back(hand[1].value);

	if (!CheckForFlush(hand)) return false;
	if (!CheckForStraights(hand)) return false;

	sort(cardsToScore.begin(), cardsToScore.end());
	

	if (cardsToScore[7] != 12) return false;
	return true;
}

float GameManager::HighCard(Card* hand)
{
	int highCard = -1;

	return hand[0].value > hand[1].value ? hand[0].value * 0.01f : hand[1].value * 0.01f;
}


//borrowed code from jonahs midterm exam
string GameManager::EvaluateCard(Card card)
{
	int rank = card.value;
	int suit = card.suit;
	//cout << "card rank " << rank << " card suit " << suit << endl;
	string suitName;
	string rankName;

	switch (rank)
	{

	case 9:
		rankName = "Jack";
		break;
	case 10:
		rankName = "Queen";
		break;
	case 11:
		rankName = "King";
		break;
	case 12:
		rankName = "Ace";
		break;
	default:
		rankName = std::to_string((rank + 2));
		break;
	}

	switch (suit)
	{

	case 1:
		suitName = "Spades";
		break;
	case 2:
		suitName = "Diamonds";
		break;
	case 3:
		suitName = "Hearts";
		break;
	default:
		suitName = "Clubs";
		break;
	}
	return rankName + " of " + suitName;
}