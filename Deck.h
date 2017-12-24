#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck {

public:
	// constructor which creates a deck of 52 cards
	Deck();

	// deal a card to player
	Card deal();

	// shuffle the cards in the deck
	void shuffle();

	//Count the cards left in the deck
	int cardsLeft();

	//show the deck;
	void displayDeck();
        
        void addCard(Card c);
        void addBank(Deck d);

	Card storage[52];
	int size;

};

#endif