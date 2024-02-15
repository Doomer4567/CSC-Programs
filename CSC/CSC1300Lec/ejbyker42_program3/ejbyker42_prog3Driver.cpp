#include "ejbyker42_prog3.h"
using namespace std;

int main(){
    srand(time(0));
    int playerCount = 0;
    char CHOICE = 'y';
    do{
      
       
        cout << "Welcome to The Game Of Consequences!" << endl;
        do{
            cout << "How many players are there?: ";
            cin >> playerCount;
            cout << endl;
            if(playerCount < 1){
                cout << "You must have at least one player!" << endl;
                cout << "Try again: " << endl;
            } else if(playerCount > 25){
                cout << "You can't have more than 25 players!" << endl;
                cout << "Try again: " << endl;
            }
        }while(playerCount < 1 || playerCount > 25);

        string player[playerCount];
        int boardSpace[playerCount];
        int money[playerCount];

        GetPlayersNames(player, boardSpace, money, playerCount);
        TurnBase(player, boardSpace, money, playerCount);

        cout << "Would you like to play again? (Press N to quit/ Press Y to Continue):";
        cin >> CHOICE;
        cout << endl;
        
    }while(!(CHOICE == 'n' || CHOICE == 'N'));
}
