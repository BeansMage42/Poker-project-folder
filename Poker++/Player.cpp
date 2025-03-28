#include "GameManager.h"

class Player {
public:
    static Card currentHand[2];  // Player's two-card hand
    bool isActive;               // Is this player currently active?
    bool hasChecked;             // Has this player checked?
    int chips;                   // Total chips available
    int chipsBet;                // Chips bet in this round
    int highestBidThisRound;
    bool hasFolded;

    //sections of this code is taken from Jonah Gibsons midterm
    int SetActive() {
        if (hasFolded) return -1;
        highestBidThisRound = highestBid;
        cout << "\n Your turn! You currently have: " << (currentChipPool - chipBetThisRound) << " chips left and have bid " << chipBetThisRound << " chips this round. \n";
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
        // currentHand[0] = hand[0]
        // currentHand[1] = hand[1]
        // Assign the two cards to this player's hand
    }

    Card* GetHand() {
        // Return pointer to currentHand array
        // Allows access to player's cards for evaluation
    }

    void addChips(int chipsAdd) {
        // chips += chipsAdd
        // Increase player's chip count by the given amount
    }

    int GetChips() {
        // Return chips
        // Provide current chip total for display or game logic
    }

protected:
    //If there were more turns, this function would be more useful
    //sections of this code is taken from Jonah Gibsons midterm
    int Check()
    {
        cout << name << " Checked! \n";
        checked = true;
        return 0;
    }
    //sections of this code is taken from jonah gibsons midterm
    int Raise(int raiseAmount)
    {

        if ((highestBidThisRound + raiseAmount) > currentChipPool)
        {
            cout << "you dont have enough chips to raise that much, try a different action! \n";
            return PlayerTurn(highestBidThisRound);//loops so the player can choose new input
        }
        else
        {

            chipBetThisRound += raiseAmount;
            cout << name << " Raised by " << raiseAmount << " to " << chipBetThisRound << endl;
            return chipBetThisRound;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Call()
    {
        cout << name << " called! \n";
        //checks if the player has enough chips left to call
        if (highestBidThisRound > currentChipPool)
        {
            cout << "\n you dont have enough chips to call, try a different action! \n";
            return PlayerTurn(highestBidThisRound);
        }
        else
        {
            chipBetThisRound = highestBidThisRound;

            return chipBetThisRound;
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

