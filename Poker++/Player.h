#pragma once
#include "Card.cpp"        // Include Card class for hand management
#include "GameManager.h"   // Include GameManager for interaction with the game
#include <iostream>
#include <string>
namespace Game {
    class Player {
    public:
        static Card currentHand[2];  // Player's two private cards
        bool isActive;               // Indicates if it's this player's turn
        bool hasChecked;             // Tracks if player has checked this round
        int chips;                   // Total chips player has
        int chipsBet;                // Chips bet in the current round

        // Public method declarations
        int SetActive();            // Set this player as the active one
        void SetHand(Card*);       // Assign the player's two cards
        Card* GetHand();             // Return the player's current hand
        void addChips(int chipsAdd); // Add chips to player's total
        int GetChips();              // Return player's chip count

    protected:
        // Protected method declarations (for player actions)
        int Check();                // Player opts to check
        int Raise(int amount);      // Player increases the bet
        int Call();                 // Player matches the current bet
        int Fold();                 // Player forfeits the hand
    };

    class Bot:public Player
    {

    };
    class User :public Player
    {
        void Input();
    };
}

