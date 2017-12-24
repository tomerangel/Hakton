#ifndef CARD_H
#define CARD_H

class Card {
public:
	// create a blank card
	Card();

	// constructor to create a card, setting the suit and rank
	Card(int suit, int rank);

	// set an existing card to a particular value
	void setCard(int suit, int rank);

	// return the point value of the card. Ace = 1, 2 thru 10, face cards can be 11, 12, 
	int getValue();

	// display the card
	void display();

private:
	int rank;
	int suit;

};

#endif 