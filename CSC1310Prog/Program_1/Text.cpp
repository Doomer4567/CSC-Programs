#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
#include <cstring>
using namespace std;
//Constructor initialzied from addVideoGameToArray and loadVideoGameFromFile
//this allocates space so that data entered into the array isn't mishandled
Text::Text(const char* textArray){
    
    textLength = strlen(textArray);

    char* tempTextArray = new char[textLength+1];

    strcpy(tempTextArray, textArray);

    this->textArray = tempTextArray;

}
//deconstructor that deletes all coexisting data in the textArray
Text::~Text(){
    cout << "Text destructor: Released memory for textArray." << endl;
    delete [] textArray;
}
//Displays text saved in textArray
void Text::displayText() const {
    cout << textArray;
}
//Grabs text from textArray
const char* Text::getText() const { //.change the type of this character to match textArray
    return textArray;
}
//Grabs the length of the text
int Text::getLength() const {
    return textLength;
}