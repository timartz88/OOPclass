#include <iostream>

using namespace std;

int linearSearch(const int[], int, int);				// Function prototype

int main()
{
	const int SIZE = 10;
	int luckyNums[SIZE] = { 13579, 26791, 26792, 33445, 55555, 
							62483, 77777, 79422, 85647, 93121 };		// Players tickets
	int results;
	int winNum;			// Winning number for the week

	cout << "Please enter the winning lottery number: ";
	cin >> winNum;

	while (winNum < 00000 || winNum > 99999)			// Input validation for legitimate 5 digit number
	{
		cout << "The winning lottery number must be 5 digits.\nPlease enter the winning lottery number: ";
		cin >> winNum;
	}

	results = linearSearch(luckyNums, SIZE, winNum);

	if (results == -1)
	{
		cout << "\n\nYou did not win this week!";
	}
	else
	{
		cout << "\n\nYou have a winning ticket! " << luckyNums[results];
	}

	return 0;
}

int linearSearch(const int arr[], int size, int value)
{
	int index = 0;       // Used to search the array
	int position = -1;   // Recods position of search value
	bool found = false;  // Flag to indicate if the value was found

	while (index < size && !found)
		{
		if (arr[index] == value)   // If the value is found
			{
			found = true;           // Set the flag
			position = index;       // Record the value's subscript
			}
		index++;                   // Go to the next element
		}
	return position;              // Return the position, or −1
	
}