#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void winner(string winner){
    // opening streams to display winner output
    ifstream in;
    ofstream out;
    string coolArt;
    in.open("Art.txt");
    out.open("winner.txt");
    //if statments to find out which monster won
    if (winner == "Losers"){

        for(int i =0; i != 13; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }

    } else if (winner == "Bandit"){
        //for statments to chose which lines to be outputted
        for(int i = 0; i != 14; i ++){
            getline(in,coolArt);
        }
        for (int i = 0; i != 92; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }

    } else if (winner == "Dragon"){

        for(int i = 0; i != 14; i ++){
            getline(in,coolArt);
        }
        for (int i = 0; i != 12; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }
        for (int i = 0; i != 82; i++){
            getline(in,coolArt);
        }
        for (int i = 0; i != 55; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }

    } else if (winner == "Giant Snail"){

        for(int i = 0; i != 14; i ++){
            getline(in,coolArt);
        }
        for (int i = 0; i != 12; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }
        for (int i = 0; i != 134; i++){
            getline(in,coolArt);
        }
        for(int i =0; i != 55; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }

    } else if (winner == "Orc"){

        for(int i = 0; i != 14; i ++){
            getline(in,coolArt);
        }
        for (int i = 0; i != 12; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }
        for (int i = 0; i != 193; i++){
            getline(in,coolArt);
        }
        for  (int i = 0; i != 54; i++){
            getline(in,coolArt);
            out << coolArt << endl;
        }

    }
    out << endl << endl << endl;
    out << "Winning Monster: " << winner << endl;

}


void Monster(string monstChoice, int& hp, int& dm, int& df){
    
    ifstream info;
    ofstream data;
    //opens text files to add information
    info.open(monstChoice + ".txt");
    if(info.is_open()){
        
        info >> hp;
        info >> dm;
        info >> df;
        info.close();
 
    } else {
        //if user enters a wrong name it adds it to a text file
        data.open("Ideas.txt", fstream::app);
        cout << "You have choosen an unknown monster-we have put them in a datasheet for later" << endl;
        data << monstChoice << endl;
        data.close();
        cout << "Thank you!" << endl;
        exit(0);
    }

}

string enemyMonster(){
    //choses which monster the enemy gets
    int enemynum = rand() % 4 + 1;
    string enemyChoice;
     switch(enemynum){
        case 1:
        {
            enemyChoice = "Bandit" ;
            break;
        }

        case 2:
        {
            enemyChoice = "Dragon";
            break;
        }

        case 3:
        {
            enemyChoice = "Giant Snail";
            break;
        }

        case 4:
        {
            enemyChoice = "Orc";
            break;
        }
    }
    return enemyChoice;
}








int main(){
    //seeded randomizer
    srand(time(0));
    //Declaration of variables
    int userChoice;
    string monstChoice;
    string enemyChoice;
    bool Abil;
    int hp1;
    int dm1;
    int df1;
    int hp2;
    int dm2;
    int df2;


    cout << "Welcome to Monster Fighter 2023!" << endl;
    cout << "We have a few Monsters to select from!" << endl;
    cout << "Please type in the monster you would like to fight as! (Bandit, Dragon, Giant Snail, Orc): ";
    getline(cin,monstChoice);
    //user chooses what monster to be
    if (monstChoice == "Bandit" || monstChoice == "bandit" ){

        monstChoice = "Bandit";

    } else if (monstChoice == "Dragon" || monstChoice == "dragon" ){

        monstChoice = "Dragon";

    } else if (monstChoice == "Giant Snail" || monstChoice == "Giant Snail" ){

        monstChoice = "Giant Snail";

    } else if (monstChoice == "Orc" || monstChoice == "Orc" ){

        monstChoice = "Orc";

    } 
    
    Monster(monstChoice, hp1, dm1, df1);

    enemyChoice = enemyMonster();
    Monster(enemyChoice, hp2, dm2, df2);
    //shows the user which monster they chose and the monster they will be facing
    cout << "You have Chosen a " << monstChoice << endl;
    cout << "You will be fighting a " << enemyChoice << endl;
    cout << "Let the fight Begin!" << endl;
    //FIGHT
    for(int i = 1; i <= 5; i++){
        
        cout << "Round " << i << endl;
        cout << "Would you like to (1)Fight (2)Defend (3)Run Away : ";
        cin >> userChoice;
        cout << endl;
        switch (userChoice)
        {
            //7/10 chance to hit the enemy otherwise you miss
        case 1:
            if((rand() % 10) > 3 ){
                hp2 -= dm1;
            } else {
                cout << "Your monster missed" << endl;
            }
            break;
            //you can defend incase you dont trust your luck
        case 2:
            cout << "You will defend" << endl;
            break;
            //HOW DARE YOU!
        case 3:
            cout << "You ran away shaming your species" << endl;
            exit(0);
        }
        //50% chance to get hit
        switch(rand() % 2 + 1){
            case 1:{
                cout << "enemy monster attacks" << endl;
                //if user defends takes half damage
                if (userChoice == 2){
                    cout << "You defend! only taking half the damage" << endl;
                    hp1 = hp1 - (dm2/2);
                    break;
                }
                //normal reducing health
                hp1 -= dm2;
                break;
            }
            //they can miss
            case 2:
            {
                cout << "Monster Misses" << endl;
                break;
            }
        }
        //if else statements to figure out who won
        if (hp1 > 0 && hp2 > 0){
        cout << "A stalemate between monsters happened" << endl;
        } else if(hp1 <= 0){
            cout << "Your monster died" << endl;
            break;
        } else if (hp2 <= 0){
            cout << "You have defeated the enemy" << endl;
            break;
        }
    }
    
    //same if else statments but calls the winner function
    if (hp1 > 0 && hp2 > 0){
        winner("Losers");
    } else if (hp1 > 0){
        winner(monstChoice);
    } else if (hp2 > 0){
        winner(enemyChoice);
    } 

}

