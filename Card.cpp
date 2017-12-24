#include <iostream>
using namespace std;
#include "Card.h"
#include <string>

// create a “blank” card
Card::Card()
{
	rank;
	suit;
}

// constructor to create a card, setting the suit and rank
Card::Card(int s, int r)
{
	rank = r;
	suit = s;
}

// set an existing card to a particular value
void Card::setCard(int s, int r)
{
	rank = r;
	suit = s;
}

// return the point value of the card. Ace = 1, 2 thru 10, face cards can be 11, 12, 
int Card::getValue()
{
	return rank;
}

// display the card
void Card::display()
{
	string displayString;
	displayString.append("   ");

	string displayDesign;

	switch (rank) {
	case 11: displayString.append("Jack");
		break;
	case 12: displayString.append("Queen");
		break;
	case 13: displayString.append("King");
		break;
	case 1: displayString.append("Ace");
		break;
        default: displayString.append(std::to_string(rank));
		break;
	}

	displayString.append(" of ");

	switch (suit) {
	case 0: displayString.append("Spades");
		switch (rank) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[    10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + std::to_string(rank) + "      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      " + std::to_string(rank) + "]\n -------\n");
			break;
		}
		break;

	case 1: displayString.append("Hearts");
		switch (rank) {
                    case 10: displayDesign.append("\n -------\n[" + std::to_string(rank) + "     ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[     " + std::to_string(rank) + "]\n -------\n");
			break;
		case 11: displayDesign.append("\n -------\n[J      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12: displayDesign.append("\n -------\n[Q      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13: displayDesign.append("\n -------\n[K      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1: displayDesign.append("\n -------\n[A      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      A]\n -------\n");
			break;
                default: displayDesign.append("\n -------\n[" + std::to_string(rank) + "      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      " + std::to_string(rank) + "]\n -------\n");
			break;
		}
		break;
	case 2: displayString.append("Diamonds");
		switch (rank) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[     10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + std::to_string(rank) + "      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      " + std::to_string(rank) + "]\n -------\n");
			break;
		}
		break;
	case 3: displayString.append("Clubs");
		switch (rank) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   * 10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + std::to_string(rank) + "      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  " + std::to_string(rank) + "]\n -------\n");
			break;
		}
		break;
	}

	cout << displayString
		<< displayDesign << endl;



}

