#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"
#include <string>
#include <algorithm>
#include <stdio.h>
#include <fcntl.h>
#include "checkers.h"
#include <fstream>
#include<string>
using namespace std;
	void printpieces(wpiece whitepiece[12]);
	int findpiece(wpiece whitepiece[12], int x, int y);
	int getxcoord(void);
	int getycoord(void);
	void showboard(int matrix[8][8]);
	char convert(int number);
	void game(Deck deck1, Deck p1Deck, Deck p2Deck);

	//method for playing the game

	void game(Deck deck1, Deck p1Deck, Deck p2Deck) {

		Card t1;
		int x = 0, y = 0;
		Deck bank;
		bank.size = 0;

		cout << "Get ready to play WAR!!!" << endl;
		for (int i = 0; i < 52; i++) {
			t1 = deck1.deal();
			if ((i % 2) == 0) {
				p1Deck.storage[x++] = t1;
			}
			else {
				p2Deck.storage[y++] = t1;
			}
		}
		//p1Deck.displayDeck();
		//p2Deck.displayDeck();
	L:

		while (p1Deck.cardsLeft() > 0 && p2Deck.cardsLeft() > 0) {

			cout << "player 1 card is:" << endl;
			Card player1 = p1Deck.deal();
			bank.addCard(player1);
			player1.display();
			cout << "player 2 card is:" << endl;
			Card player2 = p2Deck.deal();
			bank.addCard(player2);
			player2.display();

			if (player1.getValue() > player2.getValue()) {
				cout << "Player 1 Wins!!!" << endl;
				p1Deck.addBank(bank);

			}
			else if (player1.getValue() < player2.getValue()) {
				cout << "Player 2 Wins!!!" << endl;
				p2Deck.addBank(bank);

			}
			else {
				cout << "It's a Tie!!!" << endl;
				for (int i = 0; i < 3; i++) {
					bank.addCard(p1Deck.deal());
					bank.addCard(p2Deck.deal());
				}
				goto L;
			}
		}
		if (p2Deck.cardsLeft() <= 0 && p1Deck.cardsLeft() > 0) {
			cout << "player 1 wins the game\n" << endl;
		}
		else if (p1Deck.cardsLeft() <= 0 && p2Deck.cardsLeft() > 0) {
			cout << "player 2 wins the game\n" << endl;

		}
	};//end game emthod

	//menu method for display
	void menu() {
		cout << "1)	Get a new card deck" << endl;
		cout << "2)	Show all remaining cards in the deck" << endl;
		cout << "3)	Shuffle" << endl;
		cout << "4)	Play WAR!" << endl;
		cout << "5)	Exit\n" << endl;
	};//end menu method

	//main class 
	int main() {

		fstream file; //object of fstream class

					  //opening file "sample.txt" in out(write) mode
		file.open("sample.txt", ios::out);

		if (!file)
		{
			cout << "Error in creating file!!!" << endl;
			return 0;
		}


		//write text into file
		string num1;
		cout << "Enter your name and last name: \n";
		getline(cin, num1);
		file << num1;
		//closing the file
		file.close();

		//again open file in read mode
		file.open("sample.txt", ios::in);

		if (!file)
		{
			cout << "Error in opening file!!!" << endl;
			return 0;
		}

		//read untill end of file is not found.
		char ch; //to read single character


		while (!file.eof())
		{
			file >> ch; //read single character from file

		}

		file.close(); //close file



		int number, num, age;
		cout << "W E L O C O M E! " << num1 << "\n";

		cout << "If you Have Account Press 1\nif you need To Connect Press 2\n";
		cin >> num;
		while (num != 1 && num != 2) {
			cout << "Press Again";
			cin >> num;
		}

		if (num == 1) {

			cout << "Enter Your Password\n";
			cin >> num;
			cout << "To play the Checkers Game tap 2, Or to play the War Game tap 1\n";
			cin >> number;
			while (number != 1 && number != 2) {
				cout << "To play the Checkers Game tap 2, and to play the War Game tap 1\n";
				cin >> number;
			}
		}
		if (num == 2) {
			cout << "To Connect You Need To enter age and after you need to enter password\n";
			cout << "Enter Age 1-120\n";
			cin >> age;
			while (age < 1) {
				cout << "Press Again\n";
				cin >> age;
			}
			cout << "Enter Password\n";
			cin >> num;
			cout << "To play the Checkers Game tap 2 ,and to play the War Game tap 1\n";
			cin >> number;
			while (number != 1 && number != 2) {
				cout << "To play the Checkers Game tap 2, and to play the War Game tap 1\n";
				cin >> number;
			}
		}
		if (number == 1) {
			int userChoice;
			bool wChoice = true;
			Deck deck1;
			Deck p1Deck;
			Deck p2Deck;

			while (wChoice) {
				menu();
				cin >> userChoice;

				switch (userChoice) {
				case 1:
					cout << "New card deck created\n" << endl;
					break;
				case 2:
					deck1.displayDeck();
					break;
				case 3:
					deck1.shuffle();
					cout << "deck has been shuffled!\n" << endl;
					break;
				case 4:
					game(deck1, p1Deck, p2Deck);
					break;

				case 5:
					cout << "Goodbye " << num1 << endl;
					wChoice = false;
					break;
				}
			}
		}
		else {
			int n;
			cout << "1-Play\n2-Exit\n";
			cin >> n;

			if (n == 1) {
				int matrix[8][8] = { 1,0,1,0,1,0,1,0,
					0,1,0,1,0,1,0,1,
					1,0,1,0,1,0,1,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,2,0,2,0,2,0,2,
					2,0,2,0,2,0,2,0,
					0,2,0,2,0,2,0,2 };
				int xposition;
				int yposition;
				int xposition2;
				int yposition2;
				int index;

				wpiece whitepiece[12] = { wpiece(1,1,0),wpiece(3,1,0),wpiece(5,1,0),wpiece(7,1,0),wpiece(2,2,0),wpiece(4,2,0),wpiece(6,2,0),wpiece(8,2,0),wpiece(1,3,0),wpiece(3,3,0),wpiece(5,3,0),wpiece(7,3,0) };

				//printpieces(whitepiece);

				bool turn = 0;

				showboard(matrix);

				while (turn == 0)
				{
					cout << "=-WHITE'S TURN-=" << endl;
					cout << "Enter coordinates of piece to move" << endl;
					xposition = getxcoord();
					yposition = getycoord();


					while (findpiece(whitepiece, xposition, yposition) == 12)
					{
						cout << "No White Piece found - Enter coordinates of piece to move" << endl;
						xposition = getxcoord();
						yposition = getycoord();
					}

					index = findpiece(whitepiece, xposition, yposition);

					cout << "Where do you want to move it?" << endl;
					xposition2 = getxcoord();
					yposition2 = getycoord();

					cout << xposition2 << ", " << yposition2 << endl;

					while (findpiece(whitepiece, xposition2, yposition2) != 12)
					{
						cout << findpiece(whitepiece, xposition2, yposition2) << endl;
						cout << "Already a Piece there - Enter different place to move" << endl;
						xposition2 = getxcoord();
						yposition2 = getycoord();
					}

					if (whitepiece[index].jumpup(xposition2, yposition2, matrix) == 0 && whitepiece[index].moveup(xposition2, yposition2, matrix) == 0)
					{
						cout << "Not a valid move - Enter different place to move" << endl;
					}

					showboard(matrix);
				}
			}
			if (n == 2) {
				cout << "Good Bye: " << num1;
			}

			return 0;
		}
	}

	//FUNCTIONS

	int getxcoord(void)
	{
		char letter;
		int x = 9;

		cout << "A - H: ";

		while (x == 9)
		{
			cin >> letter;
			letter = toupper(letter);
			switch (letter)
			{
			case 'A':   x = 1;
				break;
			case 'B':   x = 2;
				break;
			case 'C':   x = 3;
				break;
			case 'D':   x = 4;
				break;
			case 'E':   x = 5;
				break;
			case 'F':   x = 6;
				break;
			case 'G':   x = 7;
				break;
			case 'H':   x = 8;
				break;
			default:   cout << "Please give a letter from A to H: ";
			}
		}

		return(x);
	}

	int getycoord(void)
	{
		int y = 9;

		cout << "1 - 8: ";
		cin >> y;
		while (y < 1 || y > 8)
		{
			cout << "Please give a number from 1 to 8: ";
			cin >> y;
		}

		return(y);
	}

	int findpiece(wpiece whitepiece[12], int x, int y)
	{
		int finder;

		for (finder = 0; finder < 12; finder++)
		{
			if (whitepiece[finder].givexposition() == x && whitepiece[finder].giveyposition() == y)
			{
				whitepiece[finder].select();
				return(finder);
			}
		}

		return(finder);
	}

	void showboard(int matrix[8][8])
	{
		int bigcount;
		int counter;

		cout << "|----|----|----|----|----|----|----|----|" << endl;

		for (bigcount = 7; bigcount >= 0; bigcount--)
		{
			for (counter = 0; counter < 8; counter++)
			{
				cout << "| " << convert(matrix[bigcount][counter]) << "  ";
			}

			cout << "|" << endl << "|----|----|----|----|----|----|----|----|" << endl;
		}
	}

	char convert(int number)
	{
		switch (number)
		{
		case 0:   return(' ');
			break;
		case 1:   return('0');
			break;
		case 2:   return('X');
			break;
		case 3:   return('0');
			break;
		case 4:   return('X');
			break;
		default:   return('!');
		}
	}


	void printpieces(wpiece whitepiece[12])
	{
		int count;

		for (count = 0; count < 12; count++)
		{
			cout << "White Piece Index Number " << count << " has coordinates: " << whitepiece[count].givexposition() << ", " << whitepiece[count].giveyposition() << endl;
		}
	}


