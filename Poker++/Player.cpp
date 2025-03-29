

// Player.cpp and player.h were primarily developed by Eugenio Morales
using namespace std;
#include "Card.h"
#include "Player.h"
#include <string>
namespace Game {

    

    // Inspired by Jonah Gibson's code and adapted by Eugenio Morales
    Player::Player(Card card1, Card card2)
    {
        currentHand[0] = card1;
        currentHand[1] = card2;
        hasChecked = false;
        hasFolded = false;
        chipsBet = 5;
        chips = 100;
        highestBidThisRound = 5;

        cout << "Player" << isActive << "Initialized \n";
    }
    void Player::RemoveChipsBet()
    {
        hasFolded = false;
        chips -= chipsBet;
    }
    void Player::SetHand(Card card1, Card card2) {
        currentHand[0] = card1;
        currentHand[1] = card2;
        // Assign the two cards to this player's hand
    }

    Card* Player::GetHand() {
        return currentHand;
    }

    void Player::addChips(int chipsAdd) {
        chips += chipsAdd;
        // Increase player's chip count by the given amount
    }

    void Player::Reset() {
        chips = 0;
        chipsBet = 0;
        highestBidThisRound = 0;
        isActive = false;
        hasChecked = false;
        hasFolded = false;
        hasChecked = false;
    }


    // protected methods were refined and partly developed by Eugenio Morales, alongside any bug fixes of Jonah's base segments

        //If there were more turns, this function would be more useful
        //sections of this code is taken from Jonah Gibsons midterm
    int Player::Check()
    {
        cout << name << " Checked! \n";
        hasChecked = true;
        return 0;
    }
    //sections of this code is taken from jonah gibsons midterm
    int Player::Raise(int raiseAmount)
    {

        if ((highestBidThisRound + raiseAmount) > chips)
        {
            cout << "you dont have enough chips to raise that much, try a different action! \n";
            return SetActive(highestBidThisRound); //loops so the player can choose new input
        }
        else
        {

            chips += raiseAmount;
            cout << name << " Raised by " << raiseAmount << " to " << chipsBet << endl;
            return chipsBet;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Player::Call()
    {
        cout << name << " called! \n";
        //checks if the player has enough chips left to call
        if (highestBidThisRound > chips)
        {
            cout << "\n you dont have enough chips to call, try a different action! \n";
            return SetActive(highestBidThisRound);
        }
        else
        {
            chipsBet = highestBidThisRound;

            return chipsBet;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Player::Fold()
    {
        cout << name << " has folded! \n";
        hasFolded = true;
        return 0;
    }

    //code taken from jonahs final exam
    int User::SetActive(int highestBid)
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
    User::User(Card card1, Card card2) : Player(card1, card2)
    {
        name = "Player 1";
        cout << "User Initialized \n";
    };



    void PickAction()
    {
        /*
        if (confidence too low and greed too low)
            {
                Fold()
            }
        if (confidence high and greed high)
            {
                Raise()
            }
        if ((condience high and greed low) or (if confidence low and greed high))
            {
                Call()
            }
        */
    }


    // Inspired by Jonah Gibson's code and adapted by Eugenio Morales
    Bot::Bot(Card card1, Card card2) : Player(card1, card2)
    {
        name = "bot";
        cout << name << "Bot Initialized \n";
    }
    int Bot::SetActive(int highestBid)
    {
        return 0;
    }
};

