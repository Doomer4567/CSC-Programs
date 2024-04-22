#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


//Menu Function asks user if they want to play the program
int displayMenuGetChoice(){
    
    int choice;

    cout << "Pick from the following menu: \n1. Let's play MASH! \n2. End program." << endl;
    for (int i = 0; i != 3; i++){
        cout << "CHOOSE 1 or 2: ";
        cin >> choice;
        if(choice == 1 || choice == 2){
            break;
        } else {
            cout << "Invalid choice. " << endl;
        }
        
    }
    
    return choice;
}

//function to randomized two numbers
int random(int low, int high){

    int random = rand() % high + low;
    return random;
}

//Choices function to randomize user inputs
string Choices(string choice1, string choice2, string choice3){
    
    string selectedChoice; 

    int random = rand() % 3 + 1;
    switch (random)
    {
        case 1:

            selectedChoice = choice1;
            break;

        case 2: 

            selectedChoice = choice2;
            break;

        case 3:

            selectedChoice = choice3;
            break;

    }
    
    return selectedChoice;
}

//function to grab information from needed txt file
string File(string textFile){
    int random = rand() % 15 + 1;
    string thing;
    ifstream text;
    text.open(textFile);
    for(int i = 0; i < random; i++){
        getline(text,thing);
    }
    return thing;

}









int main(){

    //new seed thingy
    srand(time(0));
    
    //Declaration of variables
    int choice = 0;
    int n;
    int n1;
    int n2;
    int n3;
    int bN;
    int bN1;
    int bN2;
    int bN3;
    string j1;
    string j2;
    string j3;
    string o1;
    string o2;
    string o3;
    
    do{
        //calls the menu function
        choice = displayMenuGetChoice();
        //switch case for whether the user chose 1 or 2
        switch (choice)
        {
        
            case 1:
            {
                //user chooses 3 numbers any invalid must be reentered until valid number is entered
                cout << "Choose Three Number from 1 through 100, separated by a space. \n";
                cin >> n1 >> n2 >> n3;
                cout << endl;
                while (n1 <= 0 || n1 > 100){
                    cout << "Invalid choice for the first number you entered." << endl;
                    cout << "Enter a number between 1 and 100. \n";
                    cin >> n1;
                    cout << endl;
                } 
                while (n2 <= 0 || n2 > 100){
                    cout << "Invalid choice for the second number you entered." << endl;
                    cout << "Enter a number between 1 and 100. \n";
                    cin >> n2;
                    cout << endl;
                }
                while (n3 <= 0 || n3 > 100){
                    cout << "Invalid choice for the third number you entered." << endl;
                    cout << "Enter a number between 1 and 100. \n";
                    cin >> n3;
                    cout << endl;
                }

                //Horrifying nested if statements to find the highest and lowest number
                if (n1 > n2){

                    if (n1 > n3){

                        if (n2 > n3){
                            n = random(n1,n3);

                        } else {
                            n = random(n1,n2);

                        }

                    } else {
                        n = random(n3,n2);

                    }

                } else if (n2 > n1){

                    if (n2 > n3){
                        if (n3 > n1){
                            n = random(n2,n3);
                        } else {
                            n = random(n2,n1);
                        }
                    } else {
                        random(n3,n1);
                    }
                }

                //user inputs for awesome job titles
                cout << "Enter in an awesome job title: ";
                cin.ignore();
                getline(cin,j1);
                cout << endl;

                cout << "Enter in another awesome job title: ";
                getline(cin,j2);
                cout << endl;

                cout << "Enter in the worst job title ever: ";
                getline(cin,j3);
                cout << endl;

                //calls the choices function
                string Career = Choices(j1,j2,j3);

                cout << "Enter company, organization, or restaurant you like: ";
                getline(cin,o1);
                cout << endl;

                cout << "Enter another company, organization, or restaurant you like: ";
                getline(cin,o2);
                cout << endl;

                cout << "Enter company, organization, or restaurant you hate: ";
                getline(cin,o3);
                cout << endl;

                //calls the choices function
                string CareerPlace = Choices(o1,o2,o3);
                
                cout << "Choose Three Numbesr from 10,000 through 500,000; separated by a space. \n";
                cin >> bN1 >> bN2 >> bN3;
                cout << endl;

                //asks user for big number
                while (bN1 <= 10000 || bN1 > 500000){
                    cout << "Invalid choice for the first number you entered." << endl;
                    cout << "Enter a number between 10,000 through 500,000. \n";
                    cin >> n1;
                    cout << endl;
                } 
                while (bN2 <= 10000 || bN2 > 500000){
                    cout << "Invalid choice for the second number you entered." << endl;
                    cout << "Enter a number between 10,000 through 500,000. \n";
                    cin >> n2;
                    cout << endl;
                }
                while (bN3 <= 10000 || bN3 > 500000){
                    cout << "Invalid choice for the third number you entered." << endl;
                    cout << "Enter a number between 10,000 through 500,000. \n";
                    cin >> n3;
                    cout << endl;
                }

                //another horrifying nested if statements
                if (bN1 > bN2){

                    if (bN1 > bN3){

                        if (bN2 > bN3){
                            bN = random(bN1,bN3);

                        } else {
                            bN = random(bN1,bN2);

                        }

                    } else {
                        bN = random(bN3,bN2);

                    }

                } else if (bN2 > bN1){

                    if (bN2 > bN3){
                        if (bN3 > bN1){
                            bN = random(bN2,bN3);
                        } else {
                            bN = random(bN2,bN1);
                        }
                    } else {
                        random(n3,n1);
                    }
                }

                //output : D
                cout << "******   Your Future   ******" << endl;
                cout << "You and your spouse, " << File("PEOPLE.txt") << " Will live in a " << File("DWELLINGS_PC.txt")  << " in " << File("LOCATIONS.txt") << " and drive a " << File("CARS.txt") << "." << endl;
                cout << "You and your spouse will have " << n << " children." << endl;
                cout << "You will work at " << CareerPlace << " as a " << Career << " making $" << bN1 << " a year." << endl << endl << endl;



                break; 
                }
                //if they chose 2 they leave
                case 2:
                {
                    cout << "You chose to end the program" << endl;
                    break;
                }  
                
        }
        //do while to allow repeat offenders
     } while (choice != 2);

    //BYE!
    cout << "Bye!" << endl;
}