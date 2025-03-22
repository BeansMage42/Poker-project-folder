#include "GameManager.h"

class Player {
public:
    static Card currentHand[2];  // Player's two-card hand
    bool isActive;               // Is this player currently active?
    bool hasChecked;             // Has this player checked?
    int chips;                   // Total chips available
    int chipsBet;                // Chips bet in this round

    void SetActive() {
        // Set isActive to true
        // Indicate this player is now the active one for their turn
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
    void Check() {
        // hasChecked = true
        // Player opts to pass without betting more
        // Notify GameManager to proceed to next turn
    }

    void Raise(int amount) {
        // if (chips >= amount AND amount > chipsBet)
        //     chips -= amount
        //     chipsBet = amount
        //     hasChecked = false
        //     Notify GameManager to increase pot by amount
        //     Update highestBet in GameManager if amount > highestBet
        // Player increases the bet, forcing others to match or fold
    }

    void Call() {
        // int amountToCall = GameManager.highestBet - chipsBet
        // if (chips >= amountToCall)
        //     chips -= amountToCall
        //     chipsBet += amountToCall
        //     hasChecked = true
        //     Notify GameManager to increase pot by amountToCall
        // Player matches the current highest bet
    }

    void Fold() {
        // isActive = false
        // hasChecked = true
        // Notify GameManager to remove this player from playersInMatch
        // Player gives up their hand for this round
    }
};

