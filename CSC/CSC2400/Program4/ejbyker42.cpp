#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


//Function to find the max element in a vector
int make_max_value(std::vector<int> INTARRAY, int Iterator, bool &sofe){
    std::stack<int> intst;
    int max = 0;
    //checks if the function reached the front of the array
    if(INTARRAY[Iterator] != INTARRAY.front()){
        max = make_max_value(INTARRAY,Iterator-1,sofe);
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