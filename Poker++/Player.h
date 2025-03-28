#pragma once
#include "Card.cpp"        // Include Card class for hand management
#include "GameManager.h"   // Include GameManager for interaction with the game
#include <iostream>
#include <string>

// Player.cpp and player.h were primarily developed by Eugenio Morales


namespace Game {
    class Player {
    public:
        string name;
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
        void Reset();               //Return character to base set
=======
        Player(Card card1, Card card2);
>>>>>>> Stashed changes
=======
        Player(Card card1, Card card2);
>>>>>>> Stashed changes
=======
        Player(Card card1, Card card2);
>>>>>>> Stashed changes

    protected:
        // Protected method declarations (for player actions)
        int Check();                // Player opts to check
        int Raise(int amount);      // Player increases the bet
        int Call();                 // Player matches the current bet
        int Fold();                 // Player forfeits the hand
    };

    // Inspired by Jonah Gibson's code and adapted by Eugenio Morales
    class Bot:public Player
    {
        Bot(Card card1, Card card2);
    };

    // Inspired by Jonah Gibson's code and adapted by Eugenio Morales
    class User :public Player
    {
        void Input();
        User(Card card1, Card card2);
    };
}

