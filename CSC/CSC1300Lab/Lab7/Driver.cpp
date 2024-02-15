#include "Lab7.h"
#include "Functions.cpp"
using namespace std;

int main(){
    

    Intro(Name);
    Character(AC, Str, StrBonus, Dex, DexBonus, Con, ConBonus, Int, IntBonus, Wis, WisBonus, Cha, ChaBonus, HP);

    
    //6 Rounds of Combat
    for(int i = 1; i != 6; i++){
        cout << "Round: " << i << ":" << endl;
        //Rolling Player Initative
        cout << "Rolling for Initative" << endl;
        Initative = (rand() % 20 + 1) + 3;
        cout << "You Rolled a " << Initative << "!" << endl;
        //Rolling Enemy Initative
        cout << "Your Enemy will be a ";
        Chance = (rand() % 3 + 1);
        Enemies(Chance, EName, EAC, EStr, EStrBonus, EDex, EDexBonus, ECon, EConBonus, EWis, EWisBonus, EInt, EIntBonus, ECha, EChaBonus, EHP);
        cout << EName << "!" << endl;
        EInitative = (rand() % 20 + 1);
        //if Giant do Boss fight encounter
        /* This is how combat works
        1st: if the player initative is higher than the enemy Initative! Player goes first. Enemy Second. Works other way around
        2nd: Run Neccsary functions for either player or enemy. then if the player attacks, determine if player has ran and if so deal damage otherwise figure out what the player did with a if else statement. Enemies attack like normal displaying player health.
        3rd: figure out whether enemy or player has died
        4th: either continue combat or run ending and breaks of the do while loop
        5th: repeat steps 2-4 until either the player has died or the enemy */


        if(EName == "Cloud Giant"){
            cout << "YOU ENCOUNTERED THE GIANT!!!" << endl;
            do{
                if (Initative > EInitative){
                    EHP -= PlayerAttack();
                    if (Damage != 0){
                        cout << "You Attacked Dealing " << Damage << " Damage!" << endl;
                    } else {
                        cout << "You defended against the monster" << endl;
                    }
                    if(EHP <= 0){
                    cout << "You have Defeated the Giant and have Saved The World!" << endl;
                    cout << "The End!" << endl;
                    exit(0);
                    }
                    HP -= EnemyAttack(Chance);
                    cout << "You were Attacked! You have taken " << Damage << " Damage!" << endl;
                    cout << "You have " << HP << " Hp Left!" << endl;
                    if (HP <= 0){
                        cout << "YOU WERE DEFEATED!" << endl;
                        cout << "The World Cries as it dies" << endl;
                        exit(0);
                    }
                } else if (EInitative > Initative){
                    HP -= EnemyAttack(Chance);
                    cout << "You were Attacked! You have taken " << HP << " Damage!" << endl;
                    cout << "You have " << HP << " Hp Left!" << endl;
                    EHP -= PlayerAttack();
                    if(EHP <= 0){
                    cout << "You have Defeated the Giant and have Saved The World!" << endl;
                    cout << "The End!" << endl;
                    exit(0);
                    }
                }
            }while(HP > 0 && EHP > 0);

        } else {
            do{
                if (Initative > EInitative){
                    EHP -= PlayerAttack();
                    if (Damage != 0){
                        cout << "You Attacked Dealing " << Damage << " Damage!" << endl;
                        if(EHP <= 0){
                            cout << "You have Defeated the Enemy and are ready for the Next Challenge" << endl;
                            LevelUp(HP,Level,ConBonus);
                            break;
                        }
                    } else if (Running > 40){
                    cout << "You have Successfully Ran Away!" << endl;
                    exit(0);
                    } else if (Running > 10 || Running <= 40){
                        cout << "You have Failed to Run Away!" << endl;
                    } else if (Running <= 10 || Running > 0){
                        cout << "You have ran STRAIGHT into the BOSS" << endl;
                        Chance = 3;
                        break;
                    } else {
                        cout << "You defended against the monster" << endl;
                    }
                    HP -= EnemyAttack(Chance);
                    cout << "You were Attacked! You have taken " << HP << " Damage!" << endl;
                    cout << "You have " << HP << " Hp Left!" << endl;
                    if (HP <= 0){
                        cout << "YOU WERE DEFEATED!" << endl;
                        cout << "The World Cries as it dies" << endl;
                        exit(0);
                    }
                } else if (EInitative > Initative){
                    HP -= EnemyAttack(Chance);
                    cout << "You were Attacked! You have taken " << HP << " Damage!" << endl;
                    cout << "You have " << HP << " Hp Left!" << endl;
                    EHP -= PlayerAttack();
                    if (Damage != 0){
                        cout << "You Attacked Dealing " << Damage << " Damage!" << endl;
                        if(EHP <= 0){
                        cout << "You have Defeated the Enemy and are ready for the Next Challenge" << endl;
                        LevelUp(HP,Level,ConBonus);
                        }
                    }   
                   if (Running > 40){
                    cout << "You have Successfully Ran Away!" << endl;
                    exit(0);
                    } else if (Running > 10 || Running <= 40){
                        cout << "You have Failed to Run Away!" << endl;
                    } else if (Running <= 10 || Running > 0){
                        cout << "You have ran STRAIGHT into the BOSS" << endl;
                         Chance = 3;
                        break;
                    } else {
                        cout << "You defended against the monster" << endl;
                    }
                }
            }while(HP > 0 && EHP > 0);

        }


    }
    //if the user runs through 5 rounds succesfully then they fight the boss
    Chance = 3;
    cout << "YOU ENCOUNTERED THE GIANT!!!" << endl;
    do{
        if (Initative > EInitative){
            EHP -= PlayerAttack();
            if (Damage != 0){
                cout << "You Attacked Dealing " << Damage << endl;
            }
            if(EHP <= 0){
                    cout << "You have Defeated the Giant and have Saved The World!" << endl;
                    cout << "The End!" << endl;
                    exit(0);
                    }
            HP -= EnemyAttack(Chance);
            cout << "You were Attacked! You have taken " << HP << " Damage!" << endl;
            cout << "You have " << HP << " Hp Left!" << endl;
            if (HP <= 0){
                cout << "YOU WERE DEFEATED!" << endl;
                cout << "The World Cries as it dies" << endl;
                exit(0);
            }
        } else if (EInitative > Initative){
            HP -= EnemyAttack(Chance);
            cout << "You were Attacked! You have taken " << HP << " Damage!" << endl;
            cout << "You have " << HP << " Hp Left!" << endl;
            if (HP <= 0){
                cout << "YOU WERE DEFEATED!" << endl;
                cout << "The World Cries as it dies" << endl;
                exit(0);
            }
            EHP -= PlayerAttack();
            if (Damage != 0){
                cout << "You Attacked Dealing " << Damage << endl;
            }
            if(EHP <= 0){
                cout << "You have Defeated the Giant and have Saved The World!" << endl;
                cout << "The End!" << endl;
                exit(0);
            }
        }
    }while(HP > 0 && EHP > 0);

}