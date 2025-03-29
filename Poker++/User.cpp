using namespace std;
using namespace Game;
#include "Player.h"
#include <iostream>
#include <string>

class User: public Player  {
    //code taken from jonahs final exam
	int SetActive(int highestBid)
	{
        
        if (hasFolded) return 0;
        if (chips == 0) return 0;
        hasChecked = false;
        highestBidThisRound = highestBid;
        cout << "\n Your turn! You currently have: " << (chips - chipsBet) << " chips left and have bid " << chipsBet << " chips this round. \n";
        cout << "\n Chose your action: \n 1: Check \n 2: Call \n 3: Raise \n 4: fold \n";
        int action;
        int amountOfChipsToAddToPot;
        cin >> action;

        switch (action)
        {
        default:

            amountOfChipsToAddToPot = Check();
            break;
        case 2:

            amountOfChipsToAddToPot = Call();
            break;

        case 3:
            cout << "You would like to raise. How many chips above " << highestBidThisRound << " would you like to bid? \n";
            int amountBid;
            cin >> amountBid;
            amountOfChipsToAddToPot = Raise(amountBid);
            break;

        case 4:

            amountOfChipsToAddToPot = Fold();
            break;
        }
        return amountOfChipsToAddToPot;

	}

	// Inspired by Jonah Gibson's code and adapted by Eugenio Morales
	User(Card card1, Card card2) : Player(card1, card2) 
	{
		name = "Player 1";
		cout << "User Initialized \n";
	}



};