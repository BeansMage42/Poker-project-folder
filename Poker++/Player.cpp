using namespace std;
using namespace Game;
#include "GameManager.h"
#include "Player.h"
#include <string>

// Player.cpp and player.h were primarily developed by Eugenio Morales

class Player {
public:
    string name;
    static Card currentHand[2];  // Player's two-card hand
    bool isActive;               // Is this player currently active?
    bool hasChecked;             // Has this player checked?
    int chips;                   // Total chips available
    int chipsBet;                // Chips bet in this round
    int highestBid;
    int highestBidThisRound;
    bool hasFolded;

    //sections of this code is taken from Jonah Gibsons midterm
    int SetActive() {
        if (hasFolded) return -1;
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
            cout << "You would like to raise. How many chips above " << highestBid << " would you like to bid? \n";
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

    void SetHand(Card hand[2]) {
        currentHand[0] = hand[0];
        currentHand[1] = hand[1];
        // Assign the two cards to this player's hand
    }

    Card* GetHand() {
        return currentHand; // Return pointer to currentHand array
        // Allows access to player's cards for evaluation
    }

    void addChips(int chipsAdd) {
        chips += chipsAdd;
        // Increase player's chip count by the given amount
    }

    int GetChips() {
        return chips;
        // Provide current chip total for display or game logic
    }


// protected methods were refined and partly developed by Eugenio Morales, alongside any bug fixes of Jonah's base segments
protected:
    //If there were more turns, this function would be more useful
    //sections of this code is taken from Jonah Gibsons midterm
    int Check()
    {
        cout << name << " Checked! \n";
        hasChecked = true;
        return 0;
    }
    //sections of this code is taken from jonah gibsons midterm
    int Raise(int raiseAmount)
    {

        if ((highestBidThisRound + raiseAmount) > chips)
        {
            cout << "you dont have enough chips to raise that much, try a different action! \n";
            return SetActive(); //loops so the player can choose new input
        }
        else
        {

            chips += raiseAmount;
            cout << name << " Raised by " << raiseAmount << " to " << chipsBet << endl;
            return chipsBet;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Call()
    {
        cout << name << " called! \n";
        //checks if the player has enough chips left to call
        if (highestBidThisRound > chips)
        {
            cout << "\n you dont have enough chips to call, try a different action! \n";
            return SetActive();
        }
        else
        {
            chipsBet = highestBidThisRound;

            return chipsBet;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Fold()
    {
        cout << name << " has folded! \n";
        hasFolded = true;
        return 0;
    }
};

