#include "Budget.h"
using namespace std;

void getUserInput(string Name [], double income [], double expenditures[][3]){

        for(int i = 0; i != 3; i++){
            cout << "Enter name: ";
            getline(cin,Name[i]);
            cout << "Enter income: ";
            cin >> income[i];
            cout << "Enter expenditures" << endl;
            for(int j = 1; j != 5; j++ ){
                switch (j){
                case 1:
                    cout << "Food: ";
                    cin >> expenditures[i][j];
                    break;
                
                case 2:
                    cout << "Gas: ";
                    cin >> expenditures[i][j];
                    break;
                case 3:
                    cout << "Water: ";
                    cin >> expenditures[i][j];
                    break;
                
                case 4:
                    cout << "Internet: ";
                    cin >> expenditures[i][j];
                    break;
                }
            }
        }
}

void calculateBalance(double income[], double remaining [], double expenditures [][3]){
        for(int i = 0; i != 3; i++){
            remaining[i] = income[i] - expenditures[i][1] - expenditures[i][2] - expenditures[i][3];
        }
}
int getHighest(double remaining []){
    int HighNum;
    for(int i = 0; i != 3; i++){
        if(remaining[i] > remaining[HighNum])
        HighNum = i;
    }    
    return HighNum;
}

int getLowest(double remaining []){
    int LowNum;
    for(int i = 0; i != 3; i++){
        if(remaining[i] < remaining[LowNum])
        LowNum = i;
    }

    return LowNum;
}