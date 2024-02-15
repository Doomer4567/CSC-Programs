#include "ejbyker42_prog3.h"
#include <iostream>
using namespace std;

void TurnBase(string player[], int boardSpace[], int money[], int playerCount){
	do{
		for(int i = 0; i != playerCount; i++){
			cout << player[i] << "'s Turn!: ";
			pressEnterhehe();
			boardSpace[i] += RollDice();
			if(boardSpace[i] >= 25){
				cout << "You Survived The Game Of Consequences!" << endl;
				PlayerFinishedBoard(player, boardSpace, money, i);
				break;
			} else {
				ActivateActionOnSpace(money, i);
			}
			
		}
	}while(boardSpace[0] < 25 && boardSpace[1] < 25);
}

void GetPlayersNames(string player[], int boardSpace[], int money[], int playerCount){
																																																																																																																																																																																											//help
	for(int i = 0; i != playerCount; i++){
            cout << "Enter the name of player " << i + 1 << ": ";
            cin >> player[i];
            cout << endl;
            boardSpace[i] = 0;
            money[i] = 0;
            cout << player[i] << " " << boardSpace[i] << " " << money[i] << endl;
        }
}

int RollDice(){
	int move;
	int dieRoll = rand() % 6 + 1;
	switch(dieRoll){
		case 1:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|    o    |\n";
			cout << "|         |\n";
			cout << "|_________|\n\n";
			break;
		case 2:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|  o      |\n";
			cout << "|      o  |\n";
			cout << "|_________|\n\n";
			break;
		case 3:
			cout << " _________\n";
			cout << "| o       |\n";
			cout << "|    o    |\n";
			cout << "|       o |\n";
			cout << "|_________|\n\n";
			break;
		case 4:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|         |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
		case 5:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|    o    |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
		case 6:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
	}
	cout << "You Rolled A " << dieRoll << "!" << endl;
	return dieRoll;
}

void ActivateActionOnSpace(int money[], int i){

	string Action;
	string MoneyStr;
	int Money;
	int Karma = rand() % 2 + 1;
	int random = rand() % 20 + 1;
	ifstream File;
	switch(Karma){
		case 1:
			File.open("goodactions.txt");
			cout << "		#\n #		  #\n  		  #\n #	 	  #\n 		#" << endl;
			cout << "You Landed on a Good Space" << endl;             
			for(int j = 0; j != random; j++){
				getline(File,Action);
			}
			Money = rand() % 100000 + 1;
			cout << Action << endl << "You got $" << Money << "!" << endl;
			money[i] += Money;
			File.close();
			break;
		case 2:
			File.open("badactions.txt");
			cout << "		   #\n #		  #\n  		  #\n #	 	  #\n 		   #" << endl;
			cout << "You Landed on a Bad Space" << endl;
			for(int j = 0; j != random; j++){
				getline(File,Action);
			}
			Money = rand() % 100000 + 1;
			cout << Action << endl << "You lost $" << Money << "!" << endl;
			money[i] -= Money;
			File.close();
			break;
	}
}

void PlayerFinishedBoard(string player[], int boardSpace[], int money[], int i){ 
	cout << "WINNING PLAYER!: " << player[i];
	cout << " has won $" << money[i] << "!\n";
}

void pressEnterhehe(){
	cout << "Press ENTER to continue.\n";
	cin.get();
}
