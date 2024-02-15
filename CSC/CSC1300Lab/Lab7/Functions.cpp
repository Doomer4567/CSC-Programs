#include "Lab7.h"
using namespace std;
//plays intro
void Intro(string& Name){

    cout << "Welcome Warrior!" << endl;
    cout << "You have been chosen to take on a quest to defeat the Giant!" << endl;
    cout << "Can I ask for your name?: ";
    cin >> Name;
    cout << endl;
    cout << "You are a brave warrior " << Name << ", and you are going to save the kingdom from the Giant!" << endl << endl;
    cout << "The Giant is located in the north, and he is extremely powerful. He has a huge body and is constantly destroying the land." << endl << endl;
    cout << "You will face 5 waves of enemies then will encounter the Giant. \nDo try to defeat them as they will provide skills to make defeating the Giant easier" << endl << endl;

}
//assings ability bonuses according to stats
int AbilityBonus(int Stat){
    int StatBonus;
    switch (Stat){
    case 1:
        StatBonus = -5;
        break;
    case 2:
    case 3:
        StatBonus = -4;
        break;
    case 4:
    case 5:
        StatBonus = -3;
        break;
    case 6:
    case 7:
        StatBonus = -2;
        break;
    case 8:
    case 9:
        StatBonus = -1;
        break;
    case 10:
    case 11:
        StatBonus = 0;
        break;
    case 12:
    case 13:
        StatBonus = 1;
        break;
    case 14:
    case 15:
        StatBonus = 2;
        break;
    case 16:
    case 17:
        StatBonus = 3;
        break;
    case 18:
    case 19:
        StatBonus = 4;
        break;
    case 20:
        StatBonus = 5;
        break;
    }

    return StatBonus;
}
//rolls for stats that users later allocate
int Stats(){
    srand(time(0));
    int Num1,Num2,Num3,Num4,Stat;
    for(int i = 0; i != 6; i++){

        Num1 = rand() % 6 + 1;
        Num2 = rand() % 6 + 1;
        Num3 = rand() % 6 + 1;
        Num4 = rand() % 6 + 1;

        if (Num1 < Num2 && Num1 < Num3 && Num1 < Num4){
            Stat = Num2 + Num3 + Num4;
        } else if (Num2 < Num1 && Num2 < Num3 && Num2 < Num4){
            Stat = Num1 + Num3 + Num4;
        } else if (Num3 < Num2 && Num3 < Num1 && Num3 < Num4){
            Stat = Num2 + Num1 + Num4;
        } else if (Num4 < Num2 && Num4 < Num3 && Num4 < Num1){
            Stat = Num2 + Num3 + Num1;
        }


    }
    return Stat;
}


//Generates Charactes Base Stats and allows user to allocate accordingly
void Character(int& AC, int& Str, int& StrBonus, int& Dex, int& DexBonus, int& Con, int& ConBonus, int& Int, int& IntBonus, int& Wis, int& WisBonus, int& Cha, int& ChaBonus, int& HP){
    srand(time(0));
    int Choice = 0;
    int Stat;
    cout << "Let's roll for stats!" << endl;
    do{
        do{   
            Stat = Stats();
            cout << "Choose which stat to put " << Stat << " in." << endl;
            cout << "(1)Str (2)Dex (3)Con (4)Int (5)Wis (6)Cha" << endl;
            cout << "Choose (1-6): ";
            cin >> Choice;
            if(Choice < 1 || Choice > 6){
                cout << "Invalid choice, try again" << endl;
            } else {
                switch (Choice)
                {
                case 1:
                    Str = Stat;
                    StrBonus = AbilityBonus(Stat);
                    break;

                case 2:
                    Dex = Stat;
                    DexBonus = AbilityBonus(Stat);
                    break;

                case 3:
                    Con = Stat;
                    ConBonus = AbilityBonus(Stat);
                    break;

                case 4:
                    Int = Stat;
                    IntBonus = AbilityBonus(Stat);
                    break;

                case 5:
                    Wis = Stat;
                    WisBonus = AbilityBonus(Stat);
                    break;

                case 6:
                    Cha = Stat;
                    ChaBonus = AbilityBonus(Stat);
                    break;

                }
            }
        }while (Choice < 1 || Choice > 6);
    
        cout << "Str: " << Str << " Mod: " << StrBonus << endl;
        cout << "Dex: " << Dex << " Mod: " << DexBonus << endl;
        cout << "Con: " << Con << " Mod: " << ConBonus << endl;
        cout << "Int: " << Int << " Mod: " << IntBonus << endl;
        cout << "Wis: " << Wis << " Mod: " << WisBonus << endl;
        cout << "Cha: " << Cha << " Mod: " << ChaBonus << endl;
    }while(Str == 0 || Dex == 0 || Con == 0 || Int == 0 || Wis == 0 || Cha == 0);

    cout << "What Armour would you like to wear" << endl;
    cout << "(1) Padded Armor, (2) Hide Armor, (3) Leather Armor" << endl;
    cout << "(4) Ring Mail, (5) Studded Leather Armor, (6) Chain Shirt" << endl;
    cout << "(7) Scale Mail, (8) Chain Mail, (9) Spiked Armor" << endl;
    cout << "(10) Splint Armor" << endl;
    cout << "Choose (1-10): ";
    cin >> Choice;
    cout << endl;
    switch (Choice)
    {
    case 1:
        AC = 11 + DexBonus;
        break;
    case 2:
        AC = 12 + DexBonus;
        break;
    case 3:
        AC = 11 + DexBonus;
        break;
    case 4:
        AC = 14;
        break;
    case 5:
        AC = 12 + DexBonus;
        break;
    case 6:
        AC = 13 + DexBonus;
        break;
    case 7:
        AC = 14 + DexBonus;
        break;
    case 8:
        AC = 16;
        break;
    case 9:
        AC = 14 + DexBonus;
        break;
    case 10:
        AC = 17;
        break;
    }
    AC += 1;
    cout << "You have " << AC << " Armor Class." << endl;

    cout << "Rolling for your HP" << endl;
    HP = (rand() % 10 + 1) + 3 + ConBonus;
    for(int i = 1; i != 5; i++){
        HP += (rand() % 10 + 1);
    }
    cout << "You have " << HP << " Hp!" << endl; 
}
//Levels up Characters Health
void LevelUp(int& HP, int& Level, int ConBonus){
    cout << "LEVEL UP" << endl;
    HP += (rand() % 10 + 1);
    cout << "You have " << HP << " Hp!" << endl; 
}

//Attack Function using if statments asking for user input
int PlayerAttack(){
    cout << "You have 4 Options!" << endl;
        do{
            cout << "(1)Attack (2) Defend (3) Act (4) Run Away" << endl;
            cout << "Please Choose (1-4): ";
            cin >> choice;
            cout << endl;
            if (choice < 1 || choice > 4){
                cout << "Invalid Number, Please Try Again" << endl;
            }
        }while (choice < 1 || choice > 4);

        switch(choice){
            /*Attack 1*/ case 1:
                cout << "You have Three Weapons!" << endl;
                do{
                    cout << "(1)GreatSword (2)Dagger (3)Fists" << endl;
                    cout << "Please choose (1-3)";
                    cin >> choice;
                    cout << endl;
                    if (choice < 1 || choice > 3){
                        cout << "Invalid Number, Please Try Again" << endl;
                    }
                }while (choice < 1 || choice > 3);

                Attack = (rand() % 20 + 1) + 3 + StrBonus;

                    switch(choice){
                        case 1:
                            cout << "You will Attack with the GreatSword!" << endl;
                            Damage = (rand() % 6 + 1) + (rand() % 6 + 1) + StrBonus;
                            break;
                        case 2:
                            cout << "You will Attack with the Dagger!" << endl;
                            Damage = (rand() % 4 + 1) + StrBonus;
                            break;
                        case 3:
                            cout << "You will Attack with the Fists!" << endl;
                            Damage = 1 + StrBonus;
                            break;
                    }
            break;
            /*Attack 2*/case 2:
                cout << "You will defend against your next attack!" << endl;
                break;

            /*Attack 3*/case 3:
                cout << "You have 3 options!" << endl;
                do{
                    cout << "(1)Second Wind (2)Potion of Healing (3)Persuade" << endl;
                    cout << "Please choose (1-3): ";
                    cin >> choice;
                    cout << endl;
                    if (choice < 1 || choice > 3){
                        cout << "Invalid Number, Please Try Again" << endl;
                    }
                }while (choice < 1 || choice > 3);
            break;
            /*Attack 4*/case 4: 
                if(EName != "Cloud Giant"){
                    Running = (rand() % 100 + 1);
                    if (Running > 40){
                        cout << "You have Successfully Ran Away!" << endl;
                        exit(0);
                    } else if (Running > 10 || Running <= 40){
                        cout << "You have Failed to Run Away!" << endl;
                    } else if (Running <= 10 || Running > 0){{
                        cout << "You have ran STRAIGHT into the BOSS" << endl;
                        Chance = 3;
                        break;
                    }
                    
                } else {
                    cout << "You can not run from the Giant" << endl;
                }
            break;
        }
    }
        return Damage;
}


//Generates Enemy Stats
void Enemies(int x, string& EName, int& EAC, int& EStr, int& EStrBonus, int& EDex, int& EDexBonus, int& ECon, int& EConBonus, int& EWis, int& EWisBonus, int& EInt, int& EIntBonus, int& ECha, int& EChaBonus, int& EHP){


    switch(x){
        case 1: 
            EName = "Animated Table";
            AC = 15;
            EStr = 18;
            EStrBonus = 4;
            EDex = 8;
            EDexBonus = -1;
            ECon = 13;
            EConBonus = 1;
            EWis = 3;
            EWisBonus = -4;
            EInt = 4;
            EIntBonus = -5;
            ECha = 1;
            EChaBonus = -2;
            EHP = 6;
            for(int i =  0; i != 6; i++){
                EHP += (rand() % 10 + 1);
            }
           break;

        case 2:
            EName = "Blood Hunter";
            AC = 16;
            EStr = 18;
            EStrBonus = 4;
            EDex = 12;
            EDexBonus = 1;
            ECon = 15;
            EConBonus = 2;
            EWis = 16;
            EWisBonus = 3;
            EInt = 9;
            EIntBonus = -1;
            ECha = 11;
            EChaBonus = 0;
            EHP = 20;
            for(int i = 0; i != 10; i++){
                EHP += (rand() % 8 + 1);
            }

            break;

        case 3:
            EName = "Cloud Giant";
            AC = 14;
            EStr = 27;
            EStrBonus = 8;
            EDex = 10;
            EDexBonus = 0;
            ECon = 22;
            EConBonus = 6;
            EWis = 16;
            EWisBonus = 3;
            EInt = 12;
            EIntBonus = 1;
            ECha = 16;
            EChaBonus = 3;
            EHP = 96;
            for(int i = 0; i != 16; i++){
                EHP += (rand() % 12 + 1);
            }
            
        break;
    }
}
//Enemy Attack Function
int EnemyAttack(int Chance){
    switch (Chance)
    {
    case 1:
        Damage = (rand() % 8 + 1) + (rand() % 8 + 1) + StrBonus;
        break;
    
    case 2:
        for(int i = 0; i != 2; i++){

            Chance = (rand() % 2 + 1);
            switch (Chance)
            {
            case 1:
                Damage = StrBonus;
                Damage = Damage + (rand() % 6 + 1) + (rand() % 6 + 1);
                break;
            case 2:
                Damage = DexBonus;
                Damage = Damage + (rand() % 10 + 1);
                break;
            }
                
        }
        break;

    case 3:
        Chance = (rand() % 2 + 1);
            switch (Chance)
            {
            case 1:
            Damage = StrBonus * 2;
                for(int i = 0; i != 2; i++){
                    Damage = Damage + (rand() % 8 + 1) + (rand() % 8 + 1) + (rand() % 8 + 1);
                    break;
                }
            case 2:
                Damage = StrBonus;
                Damage = Damage + (rand() % 10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1);
                break;
            }
        break;
    }
    return Damage;
}
