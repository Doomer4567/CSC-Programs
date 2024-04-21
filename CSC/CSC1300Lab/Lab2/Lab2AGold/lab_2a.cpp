#include <iostream>
#include <cmath>
using namespace std;

int main(){

    //Declaration of Variables
    string name;
    char  answer;
    bool  quiz1;
    bool quiz2;
    bool  quiz3;
    bool quiz4;
    bool  quiz5;
    int  correct;
    double  result;
    
    cout << "Welcome to the Super Bowl Quiz (2023)" << endl;

    cout << "Please enter your name: " << endl;
    getline(cin,name);
    cout << endl;

    cout << "Welcome " << name << "! \nLet's get Started!" << endl;

    cout << "How many First Downs did the Kansas Chiefs get 2022?" << endl;
    cout << "| A:358 | B:562 | C:245 | D:408 |" << endl;
    cin >> answer;
    cout << endl;

    if (answer == 'D'){
      quiz1 = true;
    } else {
      quiz1 = false;
    }

    cout << "Patrick Mahomes is KC's MVP! \nHow many Passing Yards did he get 2022?" << endl;
    cout << "| A:145 | B:23 | C:521 | D:856 |" << endl;
    cin >> answer;
    cout << endl;
    
    if (answer == 'C'){
      quiz2 = true;
    } else {
      quiz2 = false;
    }

    cout << "Philadelphia Eagles are favored this Super Bowl! \n How many Touchdowns did they have 2022?" << endl;
    cout << "| A:59 | B: 72 | C: 35 | D: 38 |" << endl;
    cin >> answer;
    cout << endl;

    if (answer == 'A'){
      quiz3 = true;
    } else {
      quiz3 = false;
    }

    cout << "Philedelphia has a pretty decent defense! \nHow many tackles did Hasson Reddick get 2022" << endl;
    cout << "| A:3 | B:6 | C:8 | D: 2 |" << endl;
    cin >> answer;
    cout << endl;

    if(answer == 'B'){
      quiz4 = true;
    } else {
      quiz4 = false;
    }

    cout << "Who do you think is gonna win Super Bowl LVII!" << endl;
    cout << "|A: Kansas City Cheifs | B: Philadelphia Eagles |" << endl;
    cin >> answer;
    cout << endl;

    if (answer == 'A'){
      quiz5 = true;
      cout << "Super Bowl LVII on FEB 12th at 5:30 PM" << endl;
    } else if (answer == 'B') {
      quiz5 = true;
      cout << "Super Bowl LVII on FEB 12th at 5:30 PM" << endl;
    }

    cout << "!Your Results!" << endl;

    if (quiz1 == true){
      correct += 1;
    }

    if (quiz2 == true){
      correct += 1;
    }

    if (quiz3 == true){
      correct += 1;
    }

    if (quiz4 == true){
      correct += 1;
    }

    if (quiz5 == true){
      correct += 1;
    }

    result = correct / 5.0;

    cout << name << ", You Got " << correct << "/5 or a " << result << "%!" << endl;
    cout << "Have a Good Day and Enjoy The SUPERBOWL" << endl;


}