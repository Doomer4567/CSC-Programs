/*                                    *
 *    Filename: Lab4                  *
 *    Author: Ethan Byker             *
 *    Date: 2/9/23 -                  *
 *    Purpose: Dungeon Crawler        *
 *                                    */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    /*Declaration Of Variables*/

    //seeding
    srand(time(0));

    //Character Variables
    string playerName;
    string charName;
    string Weapon1;
    string Weapon2;
    int Str = 0;
    int Dex = 0;
    int Con = 0;
    int Int = 0;
    int Wis = 0;
    int Cha = 0;
    int AC;
    int StrBonus = 0;
    int DexBonus = 0;
    int ConBonus = 0;
    int IntBonus = 0;
    int WisBonus = 0;
    int ChaBonus = 0;
    //Battle Variables
    int DamMod;
    int HitMod;
    int Prof;
    int Hitting;
    int Damage;


    //Encounter Varaibles
    int playerHealth;
    int LUCK = 0;
    int enemyHealth1 = 0;
    int enemyHit = 1;
    int enemyAC = 12;

    //Misc. Variables
    string choice;
    int Choice;
    int j = 0;
    int roll1;
    int roll2;
    int roll3;
    int roll4;

    
    //Welcome
    cout << "Welcome Adventuerer, Have you come to sign into the Guild?: ";
    cin >> choice;
    cout << endl;

 
    if (choice == "Yes" || choice == "yes"){
            
        //Asking for Users Name  
        cout << "What is your name Player: ";
        cin >> playerName;
        cout << endl;

        cout << "Great Warrior What is your Name!: ";
        cin >> charName;
        cout << endl;

        //Rand functions to determine ability scores
        cout << "Let's see what you are made of!: " << endl;
        cout << "These dice will determine your abilities in battle." << endl;

        //Rolling for Base Stats
        for (int i = 0; i < 6; i++){
                    
            roll1 = (rand() % 6) + 1;
            roll2 = (rand() % 6) + 1;
            roll3 = (rand() % 6) + 1;
            roll4 = (rand() % 6) + 1;
            //if else statements getting rid of the lowest number for better
            if ((roll1 < roll2) && (roll1 < roll3) && (roll1 < roll4)){

                LUCK += roll2;
                LUCK += roll3;
                LUCK += roll4;
                
            } else if ((roll2 < roll1) && (roll2 < roll3) && (roll2 < roll4)){

                LUCK += roll1;
                LUCK += roll3;
                LUCK += roll4;
                
            } else if ((roll3 < roll2) && (roll3 < roll1) && (roll3 < roll4)){

                LUCK += roll1;
                LUCK += roll2;
                LUCK += roll4;
                
            } else if ((roll4 < roll2) && (roll4 < roll3) && (roll4 < roll1)){

                LUCK += roll1;
                LUCK += roll2;
                LUCK += roll3;
                
            }

                    
            
            cout << "You rolled " << LUCK << "! Assign the value to one of your ability scores! (Str, Dex, Con, Int, Wis, Cha): ";
            cin >> choice;
            cout << endl;


            if (choice == "Str" || choice == "str"){

                Str = LUCK;
                switch (Str){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;

            } else if (choice == "Dex" || choice == "dex"){

                Dex = LUCK;
                switch (Dex){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;
            
            } else if (choice == "Con" || choice == "Con") {

                Con = LUCK;
                switch (Con){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;

            } else if (choice == "Int" || choice == "int") {

                Int = LUCK;
                switch (Int){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;

            } else if (choice == "Wis" || choice == "wis") {

                Wis = LUCK;
                switch (Wis){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;

            } else if (choice == "Cha" || choice == "cha") {

                Cha = LUCK;
                switch (Cha){
                    case 11:
                    case 12:
                        ConBonus = 1;
                        break;
                    case 13:
                    case 14:
                        ConBonus = 2;
                        break;
                    case 15:
                    case 16:
                        ConBonus = 3;
                        break;
                    case 17:
                    case 18:
                        ConBonus = 4;
                        break;
                    case 19:
                    case 20:
                        ConBonus = 5;
                        break;
                    default:
                        ConBonus = 0;
                        break;
                }
                LUCK = 0;

            } else {
                if (j == 3){
                    cout << "!You have had enough!";
                } else {
                cout << "Please Try Again!" << endl; 
                i -= 1;
                j += 1;
                }
                
            }

        }
                //Defining base stats
                AC = 10 + DexBonus + ConBonus;
                Weapon1 = "Greataxe";
                Weapon2 = "Dagger";
                playerHealth = 12 + ConBonus;
                Prof = 2;
                DamMod = 3;
                HitMod = StrBonus + Prof;
                cout << "Health: " << playerHealth << endl;
                cout << "AC: " << AC << endl;
                cout << "Do you wish to continue (y,n): ";
                cin >> choice;
                cout << endl;

        //Battle time
        cout << "A enemy has appeared what would you like to do?" << endl;
        enemyHealth1 = 11;
        //while loop to continue battle until enemy is dead
        while(!(enemyHealth1 <= 0)){
            if (playerHealth <= 0){
                cout << "You have been killed" << endl;
                break;
            }
                cout << "You Have Two weapons" << endl;
                cout << "(1) " << Weapon1 << ", (2) " << Weapon2 << " :";
                cin >> Choice;
                cout << endl;
                //switch statement to hit with weapon user chose
                switch (Choice)
                {
                    //Using Greataxe
                    case 1:
                    {
                        //Check to Hit
                        roll1 = (rand() % 20) + 1;
                        Hitting = roll1 + HitMod;
                        //If statement if hitting
                        if (Hitting >= enemyAC){
                            //rolling for damage
                            roll1 = (rand() % 12) + 1;
                            Damage = roll1 + DamMod;
                            //giving damage
                            cout << "You hit for " << Damage << " Damage!" << endl;
                            enemyHealth1 = enemyHealth1 - Damage;
                            //check if enemy is dead
                            if (enemyHealth1 <= 0){
                                cout << "You have finished off the enemy" << endl;
                                break;
                            }
                        } else {
                            cout << "Ah you missed!" << endl;
                        }
                        //enemy's turn
                        if (enemyHealth1 != 0){
                            cout << "Enemies Turn!" << endl;
                            //check to hit
                            roll1 = (rand() % 20) + 1;
                            Hitting = roll1 + 3;
                            if (Hitting >= AC){
                                //rolling for enemy damage
                                roll1 = (rand() % 6) + 1;
                                playerHealth = playerHealth - (roll1 + enemyHit);
                                cout << "You have " << playerHealth << " HP!" << endl;
                            } else {
                                cout << "Swing and a miss!" << endl;
                            }
                        }
                        break;
                    }
                    // like case 1 but to hit with a dagger
                    case 2:
                    {
                        roll1 = (rand() % 20) + 1;
                        Hitting = roll1 + HitMod;
                        if (Hitting >= enemyAC){
                            roll1 = (rand() % 4) + 1;
                            enemyHealth1 = enemyHealth1 - (roll1 + DamMod);
                            if (enemyHealth1 <= 0){
                                cout << "You have finished off the enemy" << endl;
                                break;
                            }
                        } else {
                        cout <<"AH you missed" << endl;;
                        }
                        cout << "Enemies Turn!" << endl;
                        if (enemyHealth1 != 0){
                            roll1 = (rand() % 20) + 1;
                            Hitting = roll1 + 3;
                            if (Hitting >= AC){
                                roll1 = (rand() % 6) + 1;
                                playerHealth = playerHealth - (roll1 + enemyHit);
                            } else {
                                cout << "Swing and a miss!" << endl;
                            }
                        }
                    //if user choses a invalid option enemy gets a turn
                    default:
                        cout << "Enemies Turn!" << endl;
                        if (enemyHealth1 != 0){
                            roll1 = (rand() % 20) + 1;
                            Hitting = roll1 + 3;
                            if (Hitting >= AC){
                                roll1 = (rand() % 6) + 1;
                                playerHealth = playerHealth - (roll1 + enemyHit);
                            } else {
                                cout << "Swing and a miss!" << endl;
                            }
                        break;
                        }
                    }
                }
            }
    } else {
        cout << "My apolgies, Have a good Day" << endl;  
    }
}
