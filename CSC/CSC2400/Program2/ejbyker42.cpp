#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

//Author: Ethan Byker
//Date: 10/6/2024
//Description: Finding Max Element with bruteforce


int main(int argc, char* argv[]){
    std::fstream fs;
    //Opening File
    if(argc > 1){
    std::string arg1(argv[1]);
    fs.open(arg1);
    }
    //fs.open("no-error.txt");
    //Checks to make sure file opens correctly!
    if(fs.fail()){
        std::cout << "File Failed to Open!" << std::endl;
        exit(0);
    }


    //adds Integers from file into a array
    std::vector<int> INTARRAY;
    int size = 0;
    //adds numbers from files into the vector array
    while(!fs.eof()){
        std::string strTemp;
        fs >> strTemp;
        //eof doesn't actually check if the end of the file is reached only if the bit is flipped.
        //therefore this checks if the next values read from file is blank
        if(strTemp == ""){
            break;
        }
        //checks for characters in each line
        for(char ch : strTemp){
            if(isalpha(ch)){
                std::cout << "Integer only Numbers on the given File!" << std::endl;
                exit(0);
            }
        }
        //converts strTemp into a Integer then pushes the integer into the Array
        int intTemp = std::stoi(strTemp);
        INTARRAY.push_back(intTemp);
        size++;
    }
    //checks for the max value in the array
    int MAX = INTARRAY.front();
    for(int i = 0; i < size; i++){
        if(MAX < INTARRAY[i]){
            MAX = INTARRAY[i];
        }
    }
    
    //Prints the max value
    std::cout << "The Max element in this list is " << MAX << "!" << std::endl;

    fs.close();

    return 0;
}