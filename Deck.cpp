#include <iostream>
using namespace std;
#include "Deck.h"
#include "Card.h"
#include <ctime>
#include <stdlib.h>

// constructor which creates a deck of 52 cards
Deck::Deck()
{
	size = 52;
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			storage[counter].setCard(i, j);
			counter++;
		}
	}
}

//deal a card
Card Deck::deal()
{
	size--;
	
	Card card1 = storage[size];
	return card1;
}

// shuffle the cards in the deck
void Deck::shuffle()
{
	srand(time(0));
	int a, b;

	for (int i = 0; i < size; i++) {
		a = rand() % size;
		b = rand() % size;

		Card c1 = storage[a];
		storage[a] = storage[b];
		storage[b] = c1;
	}

}

//Count the cards left in the deck
int Deck::cardsLeft()
{
	return size;
}

void Deck::addCard(Card c){
    storage[size++] = c;
}


void Deck::addBank(Deck d){
    for( int i = 0; i<d.cardsLeft(); i++){
        storage[size++] = d.deal();
    }
}

//show the deck;
void Deck::displayDeck()
{
	for (int i = 0; i < size; i++) {
		storage[i].display();
	}
}