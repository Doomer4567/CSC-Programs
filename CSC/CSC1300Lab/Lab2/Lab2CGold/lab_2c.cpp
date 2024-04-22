#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    //Declaration of Variables
    string month;
    double game1;
    double game2;
    double game3;
    double game4;
    double game5;
    double game6;
    double game7;
    double game8;
    double game9;

    //WELCOME
    cout << "------------------------------------Welcome User---------------------------------------------" << endl;

    cout << "We will calculate how much money you spend on games with some simple inputs from yours truly!" << endl;

    //input statements
    cout << "Enter the month: ";
    cin >> month;
    cout << endl;

    cout << "Price of Game 1: ";
    cin >> game1;
    cout << endl;

    cout << "Price of Game 2: ";
    cin >> game2;
    cout << endl;

    cout << "Price of Game 3: ";
    cin >> game3;
    cout << endl;

    //output statement to keep track of monthly payments
    cout << "Total cost of all three games for $" << month << ": " << game1 + game2 + game3 << endl;

    cout << "Enter the month: ";
    cin >> month;
    cout << endl;

        //if statement to input a new month
    if (month == month){
        string newmonth;
        cout << "Please enter a NEW month: ";
        cin >> newmonth;
        cout << endl;
        if (newmonth == month) {
            cout << "No more fun for you!";
            abort();
        } else {
            month = newmonth;
        }
    } 

    cout << "Price of Game 4: ";
    cin >> game4;
    cout << endl;

    cout << "Price of Game 5: ";
    cin >> game5;
    cout << endl;

    cout << "Price of Game 6: ";
    cin >> game6;
    cout << endl;

    cout << "Total cost of all three games for $" << month << ": " << game4 + game5 + game6 << endl;

    cout << "Enter the month: ";
    cin >> month;
    cout << endl;

    //if statement to input a new month
    if (month == month){
        string newmonth;
        cout << "Please enter a NEW month: ";
        cin >> newmonth;
        cout << endl;
        if (newmonth == month) {
            cout << "No more fun for you!";
            abort();
        } else {
            month = newmonth;
        }
    } 

    cout << "Price of Game 7: ";
    cin >> game7;
    cout << endl;

    cout << "Price of Game 8: ";
    cin >> game8;
    cout << endl;

    cout << "Price of Game 9: ";
    cin >> game9;
    cout << endl;

    cout << "Total cost of all three games for " << month << ": $" << game7 + game8 + game9 << endl;

    cout << endl;

    //total cost of all three months
    cout << "Total amount spent over the three months: $" << game1 + game2 + game3 + game4 + game5 + game6 + game7 + game8 + game9 << endl;
    
    cout << endl;

    //Average price of all games
    cout << fixed << setprecision(2) << "Average price per game: $" << (game1 + game2 + game3 + game4 + game5 + game6 + game7 + game8 + game9) / 9 << endl;
}