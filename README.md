# Project2

Rental calculator 

Determines the rental based on the number of days and number of miles.

Input the odometer readings at the start and end of the rental, the number of days the car was rented, the customer's name, whether or not the car is a luxury car, and the month the rental started.

Here is an example of a dialog with the program (user input is shown here in boldface):

	Odometer at start: 2417
	Odometer at end: 2754
	Rental days: 4
	Customer name: Mario Andretti
	Luxury car? (y/n): n
	Starting month (1=Jan, 2=Feb, etc.): 10
	---
	The rental charge for Mario Andretti is $276.99

The base charge for a rental is $45 per day for a non-luxury car, or $75 per day for a luxury car. In addition to the base charge, there is a charge per mile driven.
The first 100 miles driven cost $0.33 per mile.
In addition, for the next 500 miles driven, the charge is $0.33 per mile for a rental starting in a winter month (December through March, inclusive), or $0.27 per mile for rentals starting in other months.
In addition, for every mile beyond 600 miles, the charge is $0.21 per mile.

Odometer start, odometer end, rental days, must be integers. Customer name cannot be empty. Luxury car input must be "y" or "n", no capital letters. Starting month must be a integer between 1 to 12. 

- If the starting odometer reading is negative:

The starting odometer reading must not be negative.
   
- If the ending odometer reading is less than the starting reading:

The ending odometer reading must be at least as large as the starting reading.
   
- If the number of rental days is not positive:

The number of rental days must be positive.
   
- If an empty string was provided for the customer name:

You must enter a customer name.
   
- If the luxury status is not y or n (must be lower case):

You must enter y or n.
   
- If the month number is not an integer between 1 and 12 inclusive:

The month number must be in the range 1 through 12.
   
- If the input is valid and none of the preceding situations holds:

The rental charge for customer is $amount
