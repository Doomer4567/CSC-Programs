#include <iostream>
#include <fstream>
#include <vector>

//Function to find the max element in a vector
int find_max_element(std::vector<int> INTARRAY, int SIZE){
    //Debug Statement
    //std::cout << "Got Here" << std::endl;
    int temp = 0;
    int j = 0;
    for(int i = 1;SIZE-1;i++){
        temp = INTARRAY[i];
        j = i-1;
        while(j >= 0 && INTARRAY[j] > temp){
            INTARRAY[j+1] = INTARRAY[j];
            j = j-1;
        }
        INTARRAY[j+1] = temp;
    }
    //Debug Statement
    std::cout << "Got Here" << std::endl;
    return INTARRAY.back();
    
    /*int max = 0;
    if(SIZE == 0){
        max = INTARRAY[0];
        return max;
    }
    //determines if the back of the vector is bigger than the one in front of the element
    if(INTARRAY[SIZE] > INTARRAY[SIZE-1]){
        int temp = INTARRAY[SIZE];
        INTARRAY[SIZE] = INTARRAY[SIZE-1];
        INTARRAY[SIZE] = temp;
        INTARRAY.pop_back();
        find_max_element(INTARRAY,SIZE-1);
        return max;
        
    } // if the element is smaller than the one in front of it, it pops the element off the back of the vector
    else if(INTARRAY[SIZE] <= INTARRAY[SIZE-1]){
        INTARRAY.pop_back();
        find_max_element(INTARRAY,SIZE-1);
        return max;
    }
    */
    return 0;
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
    int SIZE = 0;
    std::vector<int> INTARRAY;
    while(!fs.eof()){
        int tempint;
        fs >> tempint;
        INTARRAY.push_back(tempint);
        SIZE++;
    }
    //Debug Statement
    //std::cout << "Got Here" << std::endl;
    
    int max = find_max_element(INTARRAY,SIZE);
    if (max == 0){
        std::cout << "Something went Wrong Please Try Again" << std::endl;
    }
    else{
        std::cout << "The Max element is " << max << std::endl;
    }

    //closes the file
    fs.close();

}