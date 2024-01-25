#include "Budget.h"
using namespace std;

int main(){
    string Name[3];
    double income[3];
    double remaining[3];
    double expenditures[4][3];

    getUserInput(Name, income, expenditures);
    calculateBalance(income, remaining, expenditures);
    int HighNum = getHighest(remaining);
    int LowNum = getLowest(remaining);

    cout << "The Student that has the highest remaining balance of $" << remaining[HighNum] << " is " << Name[HighNum] << ", who started out with an income of $" << income[HighNum] << " and expenditures of Food $" << expenditures[HighNum][0] << " Gas $" << expenditures[HighNum][1] << " Water $" << expenditures[HighNum][2] <<" Internet $" << expenditures[HighNum][3] << "." << endl;

    cout << "The Student that has the Lowest remaining balance of $" << remaining[LowNum] << " is " << Name[LowNum] << ", who started out with an income of $" << income[LowNum] << " and expenditures of Food $" << expenditures[LowNum][0] << " Gas $" << expenditures[LowNum][1] << " Water $" << expenditures[LowNum][2] <<" Internet $" << expenditures[LowNum][3] << "." << endl;
    

}