

// Player.cpp and player.h were primarily developed by Eugenio Morales

#include "Card.h"
#include "Player.h"
#include <string>
#include <random>
#include <ctime>
using namespace std;
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
        currentHandScore = 0;
        cout << "Player" << isActive << "Initialized \n";
    }
    void Player::RemoveChipsBet()//Jonah Gibson
    {
        hasFolded = false;
        chips -= chipsBet;
    }
    void Player::SetHand(Card card1, Card card2) 
    {
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

    void Player::Reset() //Rya Dean
    {
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
            return SetActive(highestBidThisRound, currentHandScore); //loops so the player can choose new input
        }
        else
        {

            chipsBet += raiseAmount;
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
            return SetActive(highestBidThisRound, currentHandScore);
        }
        else
        {
            chipsBet = highestBidThisRound;
            cout << "you have now bid" << chipsBet;
            return chipsBet;
        }
    }
    //sections of this code is taken from jonah gibsons midterm
    int Player::Fold()
    {
        cout << name << " has folded! \n";
        hasFolded = true;
        hasChecked = true;
        return 0;
    }

    //code taken from jonahs final exam
    int User::SetActive(int highestBid, float score)
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




    int minHandscore;
    static int botNum;
    // Inspired by Jonah Gibson's code and adapted by Eugenio Morales
    Bot::Bot(Card card1, Card card2) : Player(card1, card2)
    {
        std::random_device rd;  // Seed from hardware
        std::mt19937 gen(rd());
        botNum++;
        minHandscore = rand() % (7) +2;
        name = "bot " + std::to_string(botNum);
        cout << name << "Bot Initialized \n";
    }
    
    int Bot::SetActive(int highestBid, float score)//jonah gibson
    {
      
        highestBidThisRound = highestBid;
        currentHandScore = score;
        int choice = 0;
        std::random_device rd;  // Seed from hardware
        std::mt19937 gen(rd());
        int temp = rand() % (4 + 1) + score;
        if (currentHandScore < minHandscore)
        {
            
            if (temp > 6)
            {
                temp = rand() % (5);
                if (temp >= 3)
                {
                    choice = 1;
                }
                else if (temp >=2)
                {
                    choice = 2;
                }
                else choice = 4;

            }
            else 
            {
                temp = rand() % (5);
                if (temp >= 2)
                {
                    choice = 4;
                }
                else choice = 1;
            }
        }
        else 
        {
            if (score >= 8) 
            {
                choice = 3;
            }
            else 
            {
                temp = rand()%6;
                if (temp >= 4) 
                {
                    choice = 2;
                }
                else if (temp >= 2)
                {
                    choice = 2;
                }
                else {
                    choice = 1;
                }
            }
        }
        int amountToRaiseBy = (highestBid + 10) - chipsBet;
        if (choice == 2 || choice == 3) 
        {
            int chipsRemainingToBet = chips - chipsBet;
            if (chipsRemainingToBet == 0) {
                choice = 0;
            }
            if (choice == 2 && highestBid == chipsBet) choice = 3;
            if (highestBid > chips && highestBid != chipsBet)
            {
                temp = rand() % 5;
                if (temp >= 2)choice = 0;
                else choice = 4;
            }
            if (choice == 3 && (highestBid + 10) > chipsRemainingToBet) 
            {
                temp = rand() % 5;
                if (temp >= 2)choice = 0;
                else choice = 4;
            }
            

        }

        if (choice == 2) 
        {
            temp = rand() % 3;
            if (temp >= 2)
            {
                choice = 0;
            }

        }

        if (highestBid > 50 && currentHandScore < 5)
        {
            temp = rand() % 3;
            if (temp >= 2)
            {
                choice = 0;
            }
            else choice = 4;
        }
        int amountOfChipsToAddToPot;
       

        switch (choice)
        {
        default:

            amountOfChipsToAddToPot = Check();
            break;
        case 2:

            amountOfChipsToAddToPot = Call();
            break;

        case 3:
            
            amountOfChipsToAddToPot = Raise(amountToRaiseBy);
            break;

        case 4:

            amountOfChipsToAddToPot = Fold();
            break;
        }
        return amountOfChipsToAddToPot;


        return 0;
    }
};

