#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	double userNum;															// Variable for the factorial
	unsigned long long int total = 1;										// Initializing as an unsigned long long int
																			// because the total can get very large
cout << "Please enter a positive whole number :  ";
cin >> userNum;

while ( (round(userNum) != userNum) || userNum < 0 || userNum > 1000000  )	// Comparing the number entered to a rounded off version to make
{																			// sure it is a whole number. Also checking that it's in the range
	cin.clear();															// of 0 to 1,000,000
	cin.ignore(10000, '\n');
	cout << "\nEnter a positive whole number (up to 1,000,000):  ";
	cin >> userNum;
}

if (userNum == 0)												// If the user enters 0, the factorial is one. This 'if' statment is
{																// here because it's a special case that wouldn't work with the
	cout << "\nThe factorial is 1." << endl;					// normal factorial formula. 
}
else
{
	while (userNum >= 1)
	{
		total *= userNum--;										// Multiplies the total, which starts at 1, with the number given and
	}															// then subtracts 1 from the number. Repeats until the number is 1.
	cout << "\nThe factorial is " << total << endl;
}

cout << "\n\nPress enter to exit..." << endl;

cin.ignore();			// Press enter to exit
cin.get();




return 0;
}