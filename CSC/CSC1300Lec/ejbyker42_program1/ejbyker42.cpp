/* 
*   Author: Ethan Byker *
*   Class: CSC 1300-002 *
*/

#include <iostream>
using namespace std;

int main()
{
    //Declaration of Variables

    string userName;
    int userAge;
    char userSeggs;
    int weightNumber;
    char smoka;
    bool smoke;
    char alcholic;
    bool alchol;
    int exercise;
    char pet;
    bool animal;
    int prison;
    char bbSiter;
    bool old;
    int moneyMaka;
    char breakFast;
    bool morning;
    char deadParents;
    bool reallyDead;
    char tomato;
    bool Fruit;
    char veggieTales;
    bool veggie;
    int lonely;
    int IQlevel;





    // input statements to give variables values
    cout << "********** Life Expectancy Calculator **********" << endl;
    cout << "Enter your name: ";
    cin >> userName;
    cin.ignore();
    cout << endl;

    cout << "Enter your current age: ";
    cin >> userAge;
    cin.ignore();
    cout << endl;

    cout << "Are you male or female? (Enter m or f): ";
    cin >> userSeggs;
    cin.ignore();
    cout << endl;

    cout << "What is your weight satus?\n (1)Underweight, (2)Just right,  (3)Overweight, (4)Obese\n (Enter 1, 2, 3 or 4): ";
    cin >> weightNumber;
    cin.ignore();
    cout << endl;

    cout << "Do you smoke cigarettes? (Enter y or n): ";
    cin >> smoka;
    cin.ignore();
    cout<< endl;

    cout << "Do you drink more than one alcoholic beverage every day? \n (Enter y or n): ";
    cin >> alcholic;
    cin.ignore();
    cout << endl;

    cout << "Do you exercise? \n (1)None, (2)Very Little, (3)Periodically, (4)Active, (5)Athlete\n (Enter 1, 2, 3, 4 or 5) ";
    cin >> exercise;
    cin.ignore();
    cout << endl;

    cout << "Do you have a pet? (Enter y or n): "; 
    cin >> pet;
    cin.ignore();
    cout << endl;

    cout << "Are you married? \n (1)Divorced, (2)Single, (3)Married, (4)Happily Married \n (Enter 1, 2, 3, or 4): ";
    cin >> prison;
    cin.ignore();
    cout << endl;

    cout << "Are you a caretaker? (Enter y or n): ";
    cin >> bbSiter;
    cin.ignore();
    cout << endl;

    cout << "How do you feel about your job? \n (1)Hate it!, (2)Dislike it, (3)It's ok, (4)Enjoyable, (5)Love it! \n (Enter 1, 2, 3, 4, or 5): ";
    cin >> moneyMaka;
    cin.ignore();
    cout << endl;

    cout << "Do you eat breakfast every day? (Enter y or n): ";
    cin >> breakFast;
    cin.ignore();
    cout << endl;

    cout << "Did either of your biological parents or any of your biological grandparents die before the age of 50? (Enter y or n): ";
    cin >> deadParents;
    cin.ignore();
    cout << endl;

    cout << "Do you eat fruits every day? (Enter y or n): ";
    cin >> tomato;
    cin.ignore();
    cout << endl;

    cout << "Do you eat vegetable every day? (Enter y or n): ";
    cin >> veggieTales;
    cin.ignore();
    cout << endl;

    cout << "Do you hang out with your friends? \n (1)Never, (2) periodically, (3)Often \n (Enter 1, 2 or 3): ";
    cin >> lonely;
    cin.ignore();
    cout << endl;

    cout << "What is your education level? \n (1)No degrees, (2)Highschool degree, (3)Associates degree, (4)Bachelors degree, (5)Masters/PHD degree \n (Enter 1, 2, 3, 4, or 5): ";
    cin >> IQlevel;
    cin.ignore();
    cout << endl;


    // Math Time :)

    // declaring a double variable to calculate Life expectancy
    double LIFE;
    if (userAge < 60) {
        LIFE = 60;
    } else {
        LIFE = userAge;
    }

    // output statement to keep track of math
    cout << "Starting Life Expectancy: " << LIFE << endl;

    if (userSeggs == 'f'){
        LIFE +=4;
    }

    cout << "Life Expectancy after gender: " << LIFE << endl;

    //if else statements to output the correct equation
    if (weightNumber == 1){
        LIFE -= 1;
    } else if (weightNumber == 2){
        LIFE += 5;
    } else if (weightNumber == 3){
        LIFE -= 2;
    } else if (weightNumber == 4){
        LIFE -= 5;
    }

    cout << "Life Expectancy after weight: " << LIFE << endl;

    //if statement to see if the user smokes change into a boolean than pick the right equation
    if (smoka == 'y') {
        smoke = true;
    } else {
        smoke = false;
    }

    if (smoke == true){
        LIFE -= 5;
    } else {
        LIFE += 5;
    }

    cout << "Life Expectancy after smoke: " << LIFE << endl;

    if (alcholic == 'y'){
        alchol = true;
    } else {
        alchol = false;
    }

    if (alchol = true){
       LIFE -= 5;
    } else {
       LIFE += 2; 
    }

    cout << "Life Expectancy after alcohol: " << LIFE << endl;

    if (exercise == 1){
        LIFE -= 5;
    } else if (exercise == 2){
        LIFE -=2;
    } else if (exercise == 4){
        LIFE += 5;
    } else if (exercise == 5){
        LIFE += 7;
    }

    cout << "Life Expectancy after exercise: " << LIFE << endl;

    if (pet == 'y'){
        animal = true;
    } else {
        animal = false;
    }

    if (animal == true){
        LIFE += 3;
    } else {
        LIFE -= 1;
    }

    cout << "Life Expectancy after pet: " << LIFE << endl;

    if (prison == 1){
        LIFE -= 5;
    } else if (prison == 2){
        LIFE -=2;
    } else if (prison == 3){
        LIFE += 2;
    } else if (prison == 4){
        LIFE += 5;
    }

    cout << "Life Expectancy after married: " << LIFE << endl;

    if (bbSiter == 'y'){
        old = true;
    } else {
        old = false;
    }

    if (old == true){
        LIFE -= 2;
    }

    cout << "Life Expectancy after caretaker: " << LIFE << endl;

    if (moneyMaka == 1){
        LIFE -= 5;
    } else if (moneyMaka == 2){
        LIFE -= 2;
    } else if (moneyMaka == 4){
        LIFE += 2;
    } else if (moneyMaka == 5){
        LIFE += 5;
    }

    cout << "Life Expectancy after job stress: " << LIFE << endl;

    if (breakFast == 'y'){
        morning = true;
    } else {
        morning = false;
    }

    if (morning == true){
        LIFE += 5;
    } else {
        LIFE -= 2;
    }   

    cout << "Life Expectancy after breakfast: " << LIFE << endl;

    if (deadParents == 'y'){
        reallyDead = true;
    } else {
        reallyDead = false;
    }

    if (reallyDead == true){
       LIFE -= 2; 
    } else {
        LIFE += 5;
    }

    cout << "Life Expectancy after died: " << LIFE << endl;

    if (tomato == 'y'){
        Fruit = true;
    } else {
        Fruit = false;
    }

    if (Fruit == true){
        LIFE += 5;
    } else {
        LIFE -= 5;
    }

    cout << "Life Expectancy after fruits: " << LIFE << endl;

    if (veggieTales == 'y'){
        veggie = true;
    } else {
        veggie = true;
    }

    if  (veggie = true){
        LIFE += 5;
    } else {
        LIFE -= 5;
    }

    cout << "Life Expectancy after vegetables: " << LIFE << endl;

    if (lonely == 1){
        LIFE -=2 ;
    } else if (lonely == 3){
        LIFE += 2;
    }

    cout << "Life Expectancy after friends: " << LIFE << endl;

    if (IQlevel == 1){
        LIFE -= 5;
    } else if (IQlevel == 2){
        LIFE -= 2;
    } else if (IQlevel == 3){
        LIFE += 2;
    } else if (IQlevel == 4){
        LIFE +=5;
    } else if (IQlevel == 5){
        LIFE += 7;
    }

    if (LIFE < userAge){
        LIFE = userAge;
    }

        cout << "Life Expectancy after education level: " << LIFE << endl;

    cout << "************************************************" << endl;
    cout << endl;
    cout << "           Name:\t" << userName << endl;
    cout << "    Current Age:\t" << userAge << endl;
    cout << "Life Expectancy:\t" << LIFE << endl;
    cout << endl;
    cout << "************************************************" << endl;
}   