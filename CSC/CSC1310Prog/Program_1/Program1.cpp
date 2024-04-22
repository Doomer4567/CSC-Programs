/*

    Name: Ethan Byker
    Course: CSC1310-002
    Due Date: 09/15/2023
    Purpose: This program is designed to keep track of items in a video game library 
    that the dedicated user can update and change at will

*/
#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
using namespace std;

int main(){
    //Starting program with welcome text and very needed variables
    string file;
    int answer;

    cout << "How many Video games can your library hold?: ";
    cin >> answer;
    cout << endl;
    //Initializing our Arra
    VideoGameLibrary* VideogameLibrary = new VideoGameLibrary(answer);
    //Menu Option
    do{
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Load video games from file." << endl;
        cout << "2. Save video games to a file." << endl;
        cout << "3. Add a video game." << endl;
        cout << "4. Remove a video game." << endl;
        cout << "5. Display all video games." << endl;
        cout << "6. Remove ALL video games from this library and end program." << endl;
        cout << "Choose 1-6: ";
        cin >> answer;
        cout << endl;
        //Switch case for selected options
        switch (answer){
            //Loads data into array
            case 1:
                cout << "What is the name of the file? (example.txt): ";
                cin >> file;
                cout << endl;
                VideogameLibrary->loadVideoGamesFromFile(file);
                break;
            //Saves current state into an external file
            case 2:
                cout << "What do you want to name the file? (example.txt): ";
                cin >> file;
                cout << endl;
                VideogameLibrary->saveToFile(file);
                cout << "All video games in your library have been printed to  " << file << endl;
                break;
            //Adds a single videogame to the array
            case 3:
                VideogameLibrary->addVideoGameToArray();
                break;
             //Removes a specific video game by listing its title
             //user selects a number corresponging to the listed games
            case 4:
                VideogameLibrary->removeVideoGameFromArray();
                break;
            case 5:
                VideogameLibrary->displayVideoGames();
                break;
            //Deletes all saved data allocated to memory and exits program
            case 6:
                delete VideogameLibrary;
                break;
                //default for user error
            default:
                cout << "Please input a number from 1-6!!" << endl;
                
        }
        //checks if user entered 6 :)
    }while(answer != 6);
    
    cout << "GOODBYE!" << endl;
    return 0;
}