// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Defining constants
    const double baseNonlux = 45;
    const double baseLux = 75;
    const double first100 = 0.33;
    const double next500Winter = 0.33;
    const double next500Other = 0.27;
    const double after600 = 0.21;
    //Defining inputs
    int startOdometer, endOdometer, daysRental, startMonth;
    string customerName = "";
    char luxuryCar; //y or n
    double rentalCharge = 0;

    //User inputs
    cout << "Odometer at start: \n";
    cin >> startOdometer;
    cout << "Odometer at end: \n";
    cin >> endOdometer;
    cout << "Rental days: \n";
    cin >> daysRental;
    cout << "Customer name: \n";
    cin.ignore();
    getline(cin, customerName);
    cout << "Luxury car? (y/n): \n";
    cin >> luxuryCar;
    cout << "Starting month (1=Jan, 2=Feb, etc.): \n";
    cin >> startMonth;
    cout << "---" << endl;

    //Math
    if (startOdometer < 0)
    {
        cout << "The starting odometer reading must not be negative." << endl;
    }
    else if (endOdometer < startOdometer)
    {
        cout << "The ending odometer reading must be at least as large as the starting reading." << endl;
    }
    else if (daysRental <= 0)
    {
        cout << "The number of rental days must be positive." << endl;
    }
    else if (customerName == "")
    {
        cout << "You must enter a customer name." << endl;
    }
    else if (luxuryCar != 'y' && luxuryCar != 'n')
    {
        cout << "You must enter y or n." << endl;
    }
    else if (startMonth < 1 || startMonth > 12)
        cout << "The month number must be in the range 1 through 12." << endl;
    else
    {
        if (luxuryCar == 'y') //base charges
        {
            rentalCharge = baseLux * daysRental;
        }
        else
        {
            rentalCharge = baseNonlux * daysRental;
        }
        double distance = endOdometer - startOdometer;
        if (distance <= 100) //first 100 charge
        {
            rentalCharge += first100 * distance;
        }
        else
        {
            rentalCharge += first100 * 100;
            distance -= 100; //accounted for in previous line
            double cost = 0;
            if (startMonth == 12 || startMonth <= 3) //check month to define cost
            {
                cost = next500Winter;
            }
            else 
            {
                cost = next500Other;
            }
            if (distance <= 500) //next 500
            {
                rentalCharge += cost * distance;
            }
            else //after 600
            {
                rentalCharge += 500 * cost;
                distance -= 500; //accounted for in previous line
                rentalCharge += after600 * distance;
            }
        }
        cout << "The rental charge for " << customerName << " is $" << fixed << setprecision(2) << rentalCharge << endl;
    }
    return 0;
}
