/*
	Title:  Lab2.cpp
	Author: Ethan Byker
	Date:  9/13/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";//first
		cout << "\t2.  IsMember Array Function\n";//third
		cout << "\t3.  String Reverser\n";//fourth
		cout << "\t4.  Palindrome Detector\n";//fifth
		cout << "\t5.  Recursive Multiplication\n";//second
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << endl << "The Result is: " << sumOfNumbers(num) << endl;
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if(isMember(myArray,num,ARRAY_SIZE) == true){
					cout << endl << "YES!, " << num << " is in the array." << endl;
				} else {
					cout << endl << "NO!, " << num << " is NOT in the array." << endl;
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString + "  ",num);
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				isPalindrome(userString);
				//print out whether the user's string is a palindrome or not here.
				if(isPalindrome(userStrModified) == true){
					cout << endl << "YES! " << userString << " is a palindrome!" << endl;
				} else {
					cout << endl << "NO! " << userString << " is NOT a palindrome!" << endl;
				}

				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << endl << "The value of " << num1 << " x " << num2 << " is " << multiply(num1,num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int numLoop) {
	if(numLoop != 0){
		return numLoop + sumOfNumbers(numLoop - 1);
	} else {
		return 0;
	}
}

bool isMember(int* myArray, int num, int size){
	if(size != -1){
		if(myArray[size-1] == num){
			return true;
		} else {
			isMember(myArray, num, size-1);
		}
	} else {
		return false;
	}
	return 0;
}
/*	absusing calling an integer after misunderstanding that i infact could change most of the main function
	to bypass c++ placing a random integer whe changer integer to 0 but make sure that it cant be
	reinitalized.
	we then basically loop the function until we find the length of the string.
	finding the length we slowly reinput the letters up a space and delete the existing.
	after a few tries length goes to 0 ending the loop and printing out the remaining text and returning back to
	the main function.
*/
void stringReverser(string text, int length){
	if(length >= 100 || length < 0)
		length = 0;
		if(isblank(text[length]) && isblank(text[length+1]))
			if(length != 0){
				text += text[length-1];
				text[length-1] = ' ';
				stringReverser(text,length-1);
			} else {
				cout << endl << text << endl;
				return;
			}
		else
			stringReverser(text,length+1);
}

bool isPalindrome(string text){
	char first = text.front();
	char last = text.back();
	if(first == last){
		if(text.length() == 1  || text.length() == 0){
			return true;
		}
		text.erase(0,1);
		text.pop_back();
		if(isPalindrome(text))
			return true;
		else	
			return false;
	} 
	else {
		return false;
	}
}


int multiply(int num1, int num2){ 
	if(num1 != 0){
		multiply(num1-1,num2+num2);
	} else {
		return num2;
	}
	return 0;
}