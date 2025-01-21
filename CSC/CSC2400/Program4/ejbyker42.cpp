// Author: Ethan Byker
// Date:11/22/24
// Class: CSC 2400-003
#include <iostream>
#include <fstream>
#include <vector>


//Function to find the max element in a vector
int max_value(std::vector<int> INTARRAY, int Iterator){
    int max = INTARRAY[0];
    //checks if the function reached the front of the array
    if(INTARRAY[Iterator] != INTARRAY.front()){
        max = max_value(INTARRAY,Iterator-1);
    }

    //if max is less than whhere we are in the array change max
    if(max < INTARRAY[Iterator]){
        return INTARRAY[Iterator];;
    }   

    return max;
}

int main(int argc, char* argv[]){
    //Opens and checks if an argument is given and if the file given opens
    std::fstream fs;
    if(argc > 1){
        std::string arg1(argv[1]);
        fs.open(arg1); 
    }
    if(fs.fail()){
        std::cout << "File Failed to Open!" << std::endl;
        exit(0);
    }

    
    

    //makes a array to hold integers from file
    std::vector<int> INTARRAY;
    int num = 0;
    //inputs lines from the file into the array
    while (!fs.eof())
    {
        fs >> num;
        INTARRAY.push_back(num);
        
    }

    //reuses the num variable setting it to the size of the array
    //then printing out the result of the max_value function
    num = INTARRAY.size();
    std::cout << max_value(INTARRAY,num) << std::endl;


    //closes the file
    fs.close();
    return 0;
}