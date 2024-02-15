#ifndef VideoGameLibrary_H
#define VideoGameLibrary_H
#include "VideoGame.h"
#include <iostream>
#include <fstream>
using namespace std;
class VideoGameLibrary {
    public:
        //Functions
        VideoGameLibrary(int);
       ~VideoGameLibrary();
        void resizeVideoGameArray();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(string);
        void removeVideoGameFromArray();
        void saveToFile(string);
    private:
        //Variable
         VideoGame** videoGamesArray;
         int maxGames;
         int numGames;
};

#endif 
