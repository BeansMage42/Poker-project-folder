#pragma once

#include "Card.h"   
#include "GameManager.h"   
#include <iostream>
#include <string>
using namespace std;
namespace Game {

    class Player {
    public:
        string name;
        static Card currentHand[2];  // Player's two private cards
        bool isActive;               // Indicates if it's this player's turn
        bool hasChecked;             // Tracks if player has checked this round
        int chips;                   // Total chips player has
        int chipsBet;                // Chips bet in the current round
        int highestBidThisRound;
        bool hasFolded;

        // Public method declarations
        virtual int SetActive(int highestBid) = 0;  // Set this player as the active one
        void SetHand(Card card1, Card card2);        // Assign the player's two cards
        Card* GetHand();                            // Return the player's current hand
        void addChips(int chipsAdd);                // Add chips to player's total
        void RemoveChipsBet();                      // Called at end of round
        void Reset();                               // Reset character to base set

        // Constructor
        Player(Card card1, Card card2);

    protected:
        // Protected method declarations (for player actions)
        int Check();     // Player opts to check
        int Raise(int amount);  // Player increases the bet
        int Call();      // Player matches the current bet
        int Fold();      // Player forfeits the hand
    };

    // Bot class (inherits from Player)
    class Bot : public Player {
    public:
        int SetActive(int highestBid) override;  // Override SetActive
        Bot(Card card1, Card card2);  // Constructor
    };

    // User class (inherits from Player)
    class User : public Player {
    public:
        int SetActive(int highestBid) override final;  // Override and finalize SetActive
        User(Card card1, Card card2);  // Constructor
    };
}
