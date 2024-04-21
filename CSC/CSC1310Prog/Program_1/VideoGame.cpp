#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
//Constructor that fills in information to the new array made (this is called from addVideoGame to Array and loadVideoGameFromFile)
VideoGame::VideoGame(Text* temptitle, Text* tempdeveloper, Text* temppublisher, int tempyear){ //these NEED to be of type TEXT not string (except for year)
    title = temptitle;
    developer = tempdeveloper;
    publisher = temppublisher;
    year = tempyear;
}
//Deconstructor, deletes all videogame details from the array
VideoGame::~VideoGame(){
    cout << "VideoGame destructor: Released memory for VideoGame object." << endl;
    delete title;
    delete developer;
    delete publisher;
}
//Called from displayVideoGames and displayVideoGameTitles
//simply outputs text and grabs data using displayText to output the correct game from the array
void VideoGame::printVideoGameDetails(){
    
    cout << right << setw(30) << "Game Title:\t" << left; 
    title->displayText();
    cout << endl;
    cout << right << setw(30) << "Developer:\t" << left;
    developer->displayText();
    cout << endl;
    cout << right << setw(30) << "Publisher:\t" << left;
    publisher->displayText();
    cout << endl;
    cout << right << setw(30) << "Year Released:\t" << left << year << endl;
    
}
//call from loadVideoGamesFromFile, this simply grabs data using getText and outputs it to the file
void VideoGame::printVideoGameDetailsToFile(ofstream &outFile){
    char temp[1000];
    strncpy(temp, title->getText(), 1000);
    outFile << "/n" << temp << endl;
    strncpy(temp, developer->getText(), 1000);
    outFile << temp <<endl;
    strncpy(temp, publisher->getText(), 1000);
    outFile << temp <<endl;
    outFile << year;

}
//Gets videoGame title :)
Text* VideoGame::getVideoGameTitle(){
    return title;
}