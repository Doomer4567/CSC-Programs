#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
using namespace std;
//When NumGames is equal to maxGames we double the size of maxGames to store more games :)
void VideoGameLibrary::resizeVideoGameArray(){
    
    int max = maxGames * 2;
    cout << "Resizing VideoGameArray from " << maxGames << " to " << max << "." << endl;
    VideoGame** tempArray = new VideoGame*[max];
    for(int i=0;i < numGames; i++){
        tempArray[i] = videoGamesArray[i]; 
    }
    delete [] videoGamesArray;
    videoGamesArray = tempArray;
    maxGames = max;
    
}
//Constructor to initialize our array
VideoGameLibrary::VideoGameLibrary(int maxLib){
    maxGames = maxLib;
    numGames = 0;
    videoGamesArray = new VideoGame* [maxLib];
}
//Deconstructor to delete objects from memory
VideoGameLibrary::~VideoGameLibrary(){
    
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself" << endl;
    for(int i = 0; i < numGames; i++){
        delete videoGamesArray[i];
    }
    delete [] videoGamesArray;
}
/*After being called from Program1.cpp, This askes the user for the title,developer,
publisher, and year of the videogame the user inputs*/
void VideoGameLibrary::addVideoGameToArray(){
    Text* title;
    Text* developer;
    Text* publisher;
    int year;

    char tempStr[100];
    cin.ignore();
    cout << "Please enter the VideoGame Title: ";
    cin.getline(tempStr, 100);
    title = new Text(tempStr);
    cout << "\nPlease enter the Developer's Name: ";
    cin.getline(tempStr, 100);
    developer = new Text(tempStr);
    cout << "\nPlease enter the Publisher's Name: ";
    cin.getline(tempStr, 100);
    publisher = new Text (tempStr );
    cout << "\nPlease Enter the Year of Release: ";
    cin >> year;

    VideoGame* VideoGmae = new VideoGame(title, developer, publisher, year);

    if (numGames == maxGames)
        resizeVideoGameArray();

    videoGamesArray[numGames] = VideoGmae;

    (numGames)++;
    
}
//Case option that displays all videogames saved in the array
void VideoGameLibrary::displayVideoGames(){ 
    if(numGames > 0){
        
        for(int i=0; i < numGames; i++){
            cout << endl << right << setw(50) <<"----------Video Game " << i+1 << "----------" << endl;
            videoGamesArray[i]->printVideoGameDetails();
            
        }
    }
}
//similar to displayVideoGames() except only display the title. (Called from removeVideoGameFromArray)
void VideoGameLibrary::displayVideoGameTitles(){
    Text* title;
    for(int i=0; i<numGames; i++){
        title = videoGamesArray[i]->getVideoGameTitle();
        title->displayText();
    }
}
//as the name suggests, this reads string from a file named by the user
void VideoGameLibrary::loadVideoGamesFromFile(string File){
    Text* title;
    Text* developer;
    Text* publisher;
    int year;

    ifstream INFILE;
    INFILE.open(File);
    if(INFILE.fail()){
        cout << "Sorry, I was unable to open the file." << endl;

    } else {
        while(!(INFILE.eof())){
            char tempStr[100];
            INFILE.getline(tempStr,100);
            string name = tempStr;
            title = new Text(tempStr);
            INFILE.getline(tempStr,100);
            developer =new Text(tempStr);
            INFILE.getline(tempStr,100);
            publisher = new Text(tempStr);
            INFILE >> year;
            INFILE.ignore();

            VideoGame* VideoGae = new VideoGame(title, developer, publisher, year);

            if (numGames == maxGames)
                resizeVideoGameArray();

            videoGamesArray[numGames] = VideoGae;
            
            (numGames)++;
            cout << name << " was added successfully" << endl << endl;
        }
    }
}
//Removes a video game from the videogamearray and then moves all existing games to fill in empty spaces
void VideoGameLibrary::removeVideoGameFromArray(){
    int answer;
    if(numGames < 1){
        cout << "The Video Game Library must have at least one Game!" << endl;
    } else {
        displayVideoGameTitles();
        cout << "Please choose a game between 1 and " << numGames << ": ";
        cin >> answer;
        cout << endl;
        Text* title = videoGamesArray[answer-1]->getVideoGameTitle();
        cout << "The video game ";
        title->displayText();
        cout << " has been successfully deleted. " << endl;
        delete videoGamesArray[answer-1];

        for(int i = answer; i <= numGames-1; i++){
            videoGamesArray[i-1] = videoGamesArray[i]; 
        }
        videoGamesArray[numGames] = NULL;
        numGames -= 1;
    }
}
//Saves all games currently in array to either a existing file or will make a new file
void VideoGameLibrary::saveToFile(string File){

    ofstream outFile;

    outFile.open(File);

    for(int i=0; i < numGames; i++){
        videoGamesArray[i]->printVideoGameDetailsToFile(outFile);
    }
    outFile.close();
}