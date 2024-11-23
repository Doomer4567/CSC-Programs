#include <iostream>
#include <fstream>
#include <vector>


//Function to find the max element in a vector
int make_max_value(std::vector<int> INTARRAY, int back, int front){
    int Num = 0;
    if(!(front & 1 << INTARRAY.front())){
        INTARRAY.pop_back();
        Num = Num + make_max_value(INTARRAY,back,front);
    }
    if(!(back & 1 << INTARRAY.back())){
        return INTARRAY.back();
    }
    return Num + INTARRAY.back();
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
    int max = 0;
    while(!fs.eof()){
        char tempint;
        fs.get(tempint);
        INTARRAY.push_back(int(tempint));
        if(fs.peek() == '\n'){
            int back = INTARRAY.back() << 1;
            int front = INTARRAY.front() << 1;
                //Debug Statement
                //std::cout << "Got Here" << std::endl;
            int tempmax = make_max_value(INTARRAY,back,front);
                //Debug Statement
                //std::cout << "Got Here" << std::endl;
            if(max <= tempmax){
                max = tempmax;
            }
            while(!INTARRAY.empty()){
                INTARRAY.pop_back();
            }
        }
        
    }

    std::cout << max << std::endl;
    //Debug Statement
    //std::cout << "Got Here" << std::endl;

    //closes the file
    fs.close();

}