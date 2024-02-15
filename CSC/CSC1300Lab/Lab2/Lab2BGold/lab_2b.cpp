#include <iostream>
using namespace std;

int main(){

    int customerChoice;
    int DOGS;
    double hours;
    char choice;
    int multiple;

    cout << "Welcome to TTU DogCare";

    cout << "How may we be of service \n (1. Babysit Dogs) (2. Buy PetCare items) (3. Reserve a dropoff date) \n Choose (1,2,3): ";
    cin >> customerChoice;
    cout << endl;

    if (customerChoice == 1){

        cout << "Great, our Dog sitting program has a reat of $3.00/hr per dog with a flat rate of $20.00 \n Do your understand? (y/n): ";
        cin >> choice;
        cout << endl;

        if (choice == 'n'){
            cout << "Thank you for visiting the TTU DogCare";
            abort();
        }
        

        cout << "How many Dogs would you like to drop off?: ";
        cin >> DOGS;
        cout << endl;

        cout <<"How long would you like the dogs to be out for?: ";
        cin >> hours;
        cout << endl;

        double DogHours = (3.00 * DOGS) * hours;


        cout << "With " << DOGS << " being babysat for " << hours << " hours. \n Your total is $" << DogHours << endl;
        
        cout << "Thank you for visiting the TTU DogCare";
    }
    if (customerChoice == 2){

        double item1 = 9.99;
        double item2 = 29.99;
        double item3 = 69.99;
        double item4 = 8.99;
        double item5 = 35.99;
        double item6 = 19.99;
        double item7 = 39.99;
        double item8 = 59.99;
        double item9 = 4.99;
        double total;
        double Pay;
        double amountPaid;

        cout << "Loading Stock..." << endl;

        cout << "(1) Dog Food (1lb): 9.99 \n(2) Dog Food (10lb): 29.99 \n(3) Dog Food (100lb): 69.99" << endl;
        cout << "(4)Dog Bowl: 8.99 \n(5) Automatic Dog Feeder: 35.99 \n(6) Dog Bed (small): 19.99" << endl;
        cout << "(7) Dog Bed (medium): 39.99 \n(8) Dog Bed (large): 59.99 \n(9) Dog Treats: 4.99" << endl;
        
        cout << "Please choose an item(1,2,3,4,5,6,7,8,9): ";
        cin >> customerChoice;
        cout << endl;

        if (customerChoice == 1){

            cout << "How much Dog Food (1lb) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item1 * multiple;

            cout << "Your total is $" << total << endl;


        } else if (customerChoice == 2){

            cout << "How much Dog Food (10lb) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item2 * multiple;

            cout << "Your total is $" << total << endl;            

        } else if (customerChoice == 3){

            cout << "How much Dog Food (100lb) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item3 * multiple;

            cout << "Your total is $" << total << endl;


        } else if (customerChoice == 4){

            cout << "How many Dog Bowls would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item4 * multiple;

            cout << "Your total is $" << total << endl; 


        } else if (customerChoice == 5){

            cout << "How many Automatic Dog Bowls would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item5 * multiple;

            cout << "Your total is $" << total << endl;


        } else if (customerChoice == 6){

            cout << "How many Dog Beds (small) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item6 * multiple;

            cout << "Your total is $" << total << endl;


        } else if (customerChoice == 7){

            cout << "How much Dog Beds (medium) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item7 * multiple;

            cout << "Your total is $" << total << endl;


        } else if (customerChoice == 8){

            cout << "How much Dog Beds (large) would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item8 * multiple;

            cout << "Your total is $" << total << endl;

        } else if (customerChoice == 9){
            
            cout << "How many Dog Treats would you like?: ";
            cin >> multiple;
            cout << endl;

            total = item9 * multiple;

            cout << "Your total is $" << total << endl;

        } else {
            cout << "Thank you for choosing TTU DogCare";

        }

            cout << "Please insert Payment: $";
            cin >> Pay;
            cout << endl;

            amountPaid = Pay;

            if (amountPaid < total){
                cout << "$" << Pay << " Inserted \n Please insert more payment";
                cin >> Pay;
                amountPaid += Pay;
                if (amountPaid < total){
                    cout << "Refunding..." << endl;
                } 
            }    
            cout << "Processing change" << endl;
            amountPaid = amountPaid - total;
            cout << "Refunding: $" << amountPaid << endl;
    
            

            customerChoice = 0;
    }
            cout << "Thank you for choosing TTU DogCare";

        if (customerChoice == 3){

            string Date;

            cout << "When would you like to reserver your day?: ";
            getline(cin,Date);
            cout << endl;

            cout << "How many dogs would you like to reserve?: ";
            cin >> DOGS;
            cout << endl;

            cout << "How many hours would you like to reserve?: ";
            cin >> hours;
            cout << endl;

            double DogHours = (3.00 * DOGS) * hours;


            cout << "With " << DOGS << " being babysat for " << hours << " hours. \n Your total is $" << DogHours << endl;
        
            cout << "Thank you for visiting the TTU DogCare";
    }
}
    