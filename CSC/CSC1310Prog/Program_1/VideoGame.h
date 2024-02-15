#ifndef VideoGame_H
#define VideoGame_H
#include "Text.h"
#include <fstream>
using namespace std;
class VideoGame {
    public:
    //Functions
        VideoGame(Text*, Text*, Text*, int);
       ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &outFile);
        Text* getVideoGameTitle();
    private:
    //Variables
        Text* title;
        Text* developer;
        Text* publisher;
        int year;
};

#endif 