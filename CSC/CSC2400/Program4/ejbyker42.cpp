#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


//Function to find the max element in a vector
int make_max_value(std::vector<int> INTARRAY, int Iterator, bool &sofe){
    std::stack<int> intst;
    int max = 0;
    //checks if the function reached the front of the array
    //if the function reaches either the memory limit of the computer
    //or the safe memory limit a device, text editor, or ide gives
    //the base case will catch that and set sofe(StackOverFlowError to ON)
    try{
        if(INTARRAY[Iterator] != INTARRAY.front()){
        max = make_max_value(INTARRAY,Iterator-1,sofe);
    }
    } catch (const std:: overflow_error){
        sofe = 1;
    }

    //As long as the error checker is ON,
    //the following lines will do as follows
    //1. save where in the stack the error happened
    //2. clear out all stacks to free up memory
    //3. set the iterator to the value held from when the error was thrown
    //4. set the error checker to Off
    //5. continue running the function
    if(sofe == 1){
        int holditerator = intst.size();
        while(!intst.empty()){
            return max;
        }
        Iterator = holditerator;
        sofe == 0;
    }
    //if max is less than whhere we are in the array change max
    if(max < INTARRAY[Iterator]){
        max = INTARRAY[Iterator];
        return max;
    }   

    return max;
}

int main(int argc, char* argv[]){
    std::stack<int> intst;
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
   //fs.open("max-element-10.txt");

    
    

    //makes a array to hold integers from file
    std::vector<int> INTARRAY;
    int num;
    while (!fs.eof())
    {
        fs >> num;
        INTARRAY.push_back(num);
        
    }
    num = INTARRAY.size();
    bool sofe = 0;
    std::cout << make_max_value(INTARRAY,num,sofe) << std::endl;
    //Debug Statement
    //std::cout << "Got Here" << std::endl;

    //closes the file
    fs.close();
    return 0;
}