/*                                   *
 *                                    *
 *    Filename: Lab3                  *
 *    Author: Ethan Byker             *
 *    Date: 2/9/23 -                  *
 *    Purpose: Make your dream car    *
 *                                    */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    // Seed Timing
    srand(time(0));

    // Declaration of Variables
    string player1Car;
    string player2Car;
    int Players = 0;
    string choice;
    string brand;
    string model;
    int makeChoice = 0;
    string make;
    string Vehicle;
    string fuelType;
    int engineChoice = 0;
    string engine;
    string Car1;
    string Car2;
    int MSRP = 0;
    double price1Dollars = 0;
    double price1Cents = 0;
    double price2Dollars = 0;
    double price2Cents = 0;
    double price1 = 0.00;
    double price2 = 0.00;

    cout << "Welcome to the Drag Race" << endl;

    cout << "Is there One Racer or Two Racers? (one/two) ";
    cin >> choice;
    cout << endl;

    if ((choice == "one") || (choice == "One")){

        Players = 1;

        cout << "One Racer Selected" << endl;
        cout << endl;

        cout << "Time to Build your car!\n" << endl;

        cout << "Please enter your brand!: ";
        cin >> brand;
        cout << endl;

        cout << "Please enter your model name!: ";
        cin >> model;
        cout << endl;

        cout << "Please choose a make of your car! (1,2,3,4,5,6,7): " << endl;
        cout << "(1)Sedan, (2)SUV, (3)Pickup Truck, (4)Coupe, (5)Sports Car, (6)Super Car, (7)Hatchback" << endl;
        cin >> makeChoice;
        cout << endl;

        switch(makeChoice){
            case 1:
            {  
                make = "Sedan";
                break;  
            }
            case 2:
            {
                make = "SUV";
                break;
            }
            case 3:
            {
                make = "Pickup Truck";
                break;
            }
            case 4:
            {
                make = "Coupe";
                break;
            }
            case 5:
            {
                make = "Sports Car";
                break;
            }
            case 6:
            {
                make = "Super Car";
                break;
            }
            case 7:
            {
                make = "Hatchback";
                break;
            }
            default:
            {
                make = "Paperback";
                fuelType = "Paper engine";
                engine = "Paper Mache Engine";
                break;
            }
        }

        Vehicle = brand + " " + model + " " + make;

        cout << "What Fuel does your engine take? (Electric,Gasoline,Diesel): ";
        cin >> fuelType;
        cout << endl;

        if ((fuelType == "Electric") || (fuelType == "electric")){

            cout << "Choose an engine! (1,2,3): " << endl;
            cout << "(1) Electric Lawnmower Engine, (2) Tesla Engine, (3) Super Car Electric Engine" << endl;
            cin >> engineChoice;
            cout << endl;

            switch (engineChoice)
            {
            case 1:
            {
                engine = "Electric Lawnmower Engine";
                break;
            }
            case 2:
            {
                engine = "Tesla Engine";
                break;
            }
            case 3:
            {
                engine = "Super Car Electric Engine";
                break;
            }
            default:
                engine = "Paper Mache Engine";
                break;
            }

            

        } else if ((fuelType == "Gasoline") || (fuelType == "gasoline")) {

            cout << "Choose an engine! (1,2,3,4): " << endl;
            cout << "(1) Gasoline Lawnmower Engine, (2) 4.0 Liter V6 Engine, (3) 3.0 liter I6 Engine, (4) 6.0 liter V12 Engine" << endl;
            cin >> engineChoice;
            cout << endl;

            switch (engineChoice)
            {
            case 1:
            {
                engine = "Gasoline Lawnmower Engine";
                break;
            }
            case 2:
            {
                engine = "4.0 liter V6 Engine";
                break;
            }
            case 3:
            {
                engine = "3.0 liter I6 Engine";
                break;
            }
            case 4:
            {
                engine = "6.0 liter V12 Engine";
                break;
            }
            default:
                engine = "Paper Mache Engine";
                break;
            }


        } else if ((fuelType == "Diesel") || (fuelType == "diesel")){

            cout << "Choose an engine! (1,2): " << endl;
            cout << "(1) 5.0L V8 Engine, (2) 7.3L V8 Engine" << endl;
            cin >> engineChoice;
            cout << endl;

            switch (engineChoice)
            {
            case 1:
            {
                engine = "5.0L V8 Engine";
                break;
            }
            case 2:
            {
                engine = "7.3L V8 Engine";
                break;
            }
            default:
                engine = "Paper Mache engine";
                break;
            }


        } else {
            fuelType = "Paper fuel";
            engine = "Paper Mache engine";
        }

        cout << "Your vehicle has been developed!" << endl;  
        cout << "You have made a " << brand << " " << model << " " << make << "!" << endl;
        cout << "your " << Vehicle << " is " << fuelType << " with a " << engine << "!" << endl;

        cout << "How much do you think your vehicle is worth? (Integers Only): $";
        cin >> MSRP;
        cout << endl;

        price1Dollars = (rand() % MSRP) + 1;
        price1Cents = ((rand() % 100) + 1) / 100.00;
        price1 = price1Dollars + price1Cents;


        cout << fixed << setprecision(2) << "Your vehicle is worth $" << price1 << endl; 

        Car1 = Vehicle + " With a  " + fuelType + " " + engine;
        
    } else if ((choice == "two") || (choice == "Two")){

        cout << "Two Racers Selected!" << endl;

        while (Players != 2)
        {
            

            if (Players == 0){
                Players +=1;

                cout << "Racer 1: Time to Build your car!\n" << endl;

                cout << "Please enter your brand!: ";
                    cin >> brand;
                    cout << endl;

                    cout << "Please enter your model name!: ";
                    cin >> model;
                    cout << endl;

                    cout << "Please choose a make of your car! (1,2,3,4,5,6,7): " << endl;
                    cout << "(1)Sedan, (2)SUV, (3)Pickup Truck, (4)Coupe, (5)Sports Car, (6)Super Car, (7)Hatchback" << endl;
                    cin >> makeChoice;
                    cout << endl;

                    switch(makeChoice){
                        case 1:
                        {  
                            make = "Sedan";
                            break;  
                        }
                        case 2:
                        {
                            make = "SUV";
                            break;
                        }
                        case 3:
                        {
                            make = "Pickup Truck";
                            break;
                        }
                        case 4:
                        {
                            make = "Coupe";
                            break;
                        }
                        case 5:
                        {
                            make = "Sports Car";
                            break;
                        }
                        case 6:
                        {
                            make = "Super Car";
                            break;
                        }
                        case 7:
                        {
                            make = "Hatchback";
                            break;
                        }
                        default:
                        {
                            make = "Paperback";
                            fuelType = "Paper fuel";
                            engine = "Paper Mache engine";
                            break;
                        }
                    }

                    Vehicle = brand + " " + model + " " + make;

                    cout << "What Fuel does your engine take? (Electric,Gasoline,Diesel): ";
                    cin >> fuelType;
                    cout << endl;

                    if ((fuelType == "Electric") || (fuelType == "electric")){

                        cout << "Choose an engine! (1,2,3): " << endl;
                        cout << "(1) Electric Lawnmower Engine, (2) Tesla Engine, (3) Super Car Electric Engine" << endl;
                        cin >> engineChoice;
                        cout << endl;

                        switch (engineChoice)
                        {
                        case 1:
                        {
                            engine = "Electric Lawnmower Engine";
                            break;
                        }
                        case 2:
                        {
                            engine = "Tesla Engine";
                            break;
                        }
                        case 3:
                        {
                            engine = "Super Car Electric Engine";
                            break;
                        }
                        default:
                            engine = "Paper Mache Engine";
                            break;
                        }

                        

                    } else if ((fuelType == "Gasoline") || (fuelType == "gasoline")) {

                        cout << "Choose an engine! (1,2,3,4): " << endl;
                        cout << "(1) Gasoline Lawnmower Engine, (2) 4.0 Liter V6 Engine, (3) 3.0 liter I6 Engine, (4) 6.0 liter V12 Engine" << endl;
                        cin >> engineChoice;
                        cout << endl;

                        switch (engineChoice)
                        {
                        case 1:
                        {
                            engine = "Gasoline Lawnmower Engine";
                            break;
                        }
                        case 2:
                        {
                            engine = "4.0 liter V6 Engine";
                            break;
                        }
                        case 3:
                        {
                            engine = "3.0 liter I6 Engine";
                            break;
                        }
                        case 4:
                        {
                            engine = "6.0 liter V12 Engine";
                            break;
                        }
                        default:
                            engine = "Paper Mache Engine";
                            break;
                        }


                    } else if ((fuelType == "Diesel") || (fuelType == "diesel")){

                        cout << "Choose an engine! (1,2): " << endl;
                        cout << "(1) 5.0L V8 Engine, (2) 7.3L V8 Engine" << endl;
                        cin >> engineChoice;
                        cout << endl;

                        switch (engineChoice)
                        {
                        case 1:
                        {
                            engine = "5.0L V8 Engine";
                            break;
                        }
                        case 2:
                        {
                            engine = "7.3L V8 Engine";
                            break;
                        }
                        default:
                            engine = "Paper Mache engine";
                            break;
                        }


                    } else {
                        fuelType = "Paper fuel";
                        engine = "Paper Mache Engine";
                    }

                cout << "Your vehicle has been developed!" << endl;  
                cout << "You have made a " << brand << " " << model << " " << make << "!" << endl;
                cout << "Your " << Vehicle << " is " << fuelType << " with a " << engine << "!" << endl;

                cout << "How much do you think your vehicle is worth? (Integers Only): $";
                cin >> MSRP;
                cout << endl;

                price1Dollars = (rand() % MSRP) + 1;
                price1Cents = (rand() % 100) + 1;
                price1 = price1Dollars + (price1Cents/100);
                
                cout << fixed << setprecision(2) << "Your vehicle is worth $" << price1 << endl; 


                Car1 = Vehicle + " With a  " + fuelType + " " + engine;

            } else if (Players == 1){
                Players += 1;

                cout << "Racer 2:Time to Build your car!\n" << endl;

                cout << "Please enter your brand!: ";
                cin >> brand;
                cout << endl;

                cout << "Please enter your model name!: ";
                cin >> model;
                cout << endl;

                cout << "Please choose a make of your car! (1,2,3,4,5,6,7): " << endl;
                cout << "(1)Sedan, (2)SUV, (3)Pickup Truck, (4)Coupe, (5)Sports Car, (6)Super Car, (7)Hatchback" << endl;
                cin >> makeChoice;
                cout << endl;

                switch(makeChoice){
                    case 1:
                    {  
                        make = "Sedan";
                        break;  
                    }
                    case 2:
                    {
                        make = "SUV";
                        break;
                    }
                    case 3:
                    {
                        make = "Pickup Truck";
                        break;
                    }
                    case 4:
                    {
                        make = "Coupe";
                        break;
                    }
                    case 5:
                    {
                        make = "Sports Car";
                        break;
                    }
                    case 6:
                    {
                        make = "Super Car";
                        break;
                    }
                    case 7:
                    {
                        make = "Hatchback";
                        break;
                    }
                    default:
                    {
                        make = "Paperback";
                        fuelType = "Paper fuel";
                        engine = "Paper Mache Engine";
                        break;
                    }


                }

                Vehicle = brand + " " + model + " " + make;

                cout << "What Fuel does your engine take? (Electric,Gasoline,Diesel): ";
                cin >> fuelType;
                cout << endl;

                if ((fuelType == "Electric") || (fuelType == "electric")){

                    cout << "Choose an engine! (1,2,3): " << endl;
                    cout << "(1) Electric Lawnmower Engine, (2) Tesla Engine, (3) Super Car Electric Engine" << endl;
                    cin >> engineChoice;
                    cout << endl;

                    switch (engineChoice)
                    {
                    case 1:
                    {
                        engine = "Electric Lawnmower Engine";
                        break;
                    }
                    case 2:
                    {
                        engine = "Tesla Engine";
                        break;
                    }
                    case 3:
                    {
                        engine = "Super Car Electric Engine";
                        break;
                    }
                    default:
                        engine = "Paper Mache Engine";
                        break;
                    }

                    

                } else if ((fuelType == "Gasoline") || (fuelType == "gasoline")) {

                    cout << "Choose an engine! (1,2,3,4): " << endl;
                    cout << "(1) Gasoline Lawnmower Engine, (2) 4.0 Liter V6 Engine, (3) 3.0 liter I6 Engine, (4) 6.0 liter V12 Engine" << endl;
                    cin >> engineChoice;
                    cout << endl;

                    switch (engineChoice)
                    {
                    case 1:
                    {
                        engine = "Gasoline Lawnmower Engine";
                        break;
                    }
                    case 2:
                    {
                        engine = "4.0 liter V6 Engine";
                        break;
                    }
                    case 3:
                    {
                        engine = "3.0 liter I6 Engine";
                        break;
                    }
                    case 4:
                    {
                        engine = "6.0 liter V12 Engine";
                        break;
                    }
                    default:
                        engine = "Paper Mache Engine";
                        break;
                    }


                } else if ((fuelType == "Diesel") || (fuelType == "diesel")){

                    cout << "Choose an engine! (1,2): " << endl;
                    cout << "(1) 5.0L V8 Engine, (2) 7.3L V8 Engine" << endl;
                    cin >> engineChoice;
                    cout << endl;

                    switch (engineChoice)
                    {
                    case 1:
                    {
                        engine = "5.0L V8 Engine";
                        break;
                    }
                    case 2:
                    {
                        engine = "7.3L V8 Engine";
                        break;
                    }
                    default:
                        engine = "Paper Mache Engine";
                        break;
                    }


                } else {
                    fuelType = "Paper";
                    engine = "Paper Mache";
                }

                        cout << "Your vehicle has been developed!" << endl; 
                        cout << endl; 
                        cout << "You have made a " << brand << " " << model << " " << make << "!" << endl;
                        cout << endl; 
                        cout << "your " << Vehicle << " is " << fuelType << " with a " << engine << "!" << endl;
                        cout << endl; 

                        cout << "How much do you think your vehicle is worth? (Integers Only): $";
                        cin >> MSRP;
                        cout << endl;

                       price2Dollars = (rand() % MSRP) + 1;
                       price2Cents = (rand() % 100) + 1;
                       price2 = price2Dollars + (price2Cents/100);

                        cout << fixed << setprecision(2) << "Your vehicle is worth $" << price2 << endl; 


                        Car2 = Vehicle + " With a  " + fuelType + " " + engine;




            } else if (Players == 2){
                cout << "All vehicles have been Made!" << endl;

            }
    
            
        }
        
        

    }

    if(Players == 1){
        
        int TimeSeconds;
        double TimeMiliSeconds;
        double Time;

        cout << "Time to Race!" << endl;

        cout << fixed << setprecision(2) << "Your " << Car1 << " Worth $" << price1 << " is going for a new time! ";

         TimeSeconds = (rand() % 60) + 1;
         TimeMiliSeconds = ((rand() & 999) + 1) / 1000.000;
         Time = TimeSeconds + TimeMiliSeconds;

        cout << fixed << setprecision(3) << "Your Vehicle made a " << Time << endl; 



    } else if (Players == 2){

        int TimeSeconds1;
        double TimeMiliSeconds1;
        double Time1;
        int TimeSeconds2;
        double TimeMiliSeconds2;
        double Time2;

        cout << "Time to Race!" << endl;
        cout << "Player 1" << endl;
        cout << fixed << setprecision(2) << "Your " << Car1 << " Worth $" << price1 << " is going for a new time!" << endl;
        cout << endl;

         TimeSeconds1 = (rand() % 60) + 1;
         TimeMiliSeconds1 = ((rand() & 999) + 1) / 1000.000;
         Time1 = TimeSeconds1 + TimeMiliSeconds1;

        cout << "Your Vehicle made a " << Time1 << endl; 
        cout << endl;

        cout << "Player 2" << endl;
        cout << "Your " << Car2 << " Worth $" << price2 << " is going for a new time!" << endl;
        cout << endl;

         TimeSeconds2 = (rand() % 60) + 1;
         TimeMiliSeconds2 = ((rand() % 999) + 1) / 1000.000;
         Time2 = TimeSeconds2 + TimeMiliSeconds2;

        cout << fixed << setprecision(3) << "Racer 1: Your Vehicle made a " << Time1 << endl; 
        cout << endl;

        cout << fixed << setprecision(3) << "Racer 2: Your Vehicle made a " << Time2 << endl;
        cout << endl;

            if (TimeSeconds1 > TimeSeconds2){
                cout << "Player 1 Wins" << endl;
            } else if (TimeSeconds1 < TimeSeconds2){
                cout << "Player 2 Wins" << endl;
            } else if (TimeSeconds1 == TimeSeconds2){
                if (TimeMiliSeconds1 > TimeMiliSeconds2){
                cout << "Player 1 Wins" << endl;
                } else if (TimeMiliSeconds1 < TimeMiliSeconds2){
                cout << "Player 2 Wins" << endl;
                } else {
                    cout << "The Cars Have Tied" << endl;
                }
            }


    } else {
        cout << "Critical Error, Please Try Again" << endl;
    }


}