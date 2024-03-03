#include <iostream>
#include <string>
using namespace std;

// Decription: This program does basic arithmetic
// Program: Calculator
// Programmer: Tim Artz
// Last Modified: 3/1/2024

int main() {

	cout << "Decription: This program does basic arithmetic\n"
			"Program: Calculator\n"
			"Programmer: Tim Artz\n"
			"Last Modified: 3/1/2024\n\n"<< endl;

	cout << "*******************Menu********************\n\n" << endl;	// Displaying the operator menu
	cout << "        OPERATORS: + - * / %\n\n" << endl;
	cout << "*******************************************\n\n" << endl;

	char _operator;						// This variable holds the sign that the user chooses
	int operand1, operand2;				// Numeric variables to hold the two numbers that the user enters and the solution				
	double solution;
	


	cout << "Enter first operand: ";		// Prompt to enter first number
	cin >> operand1;

	/////////
	
	if (!(operand1 >= -2147483648 && operand1 <= 2147483647))
	{
		cout << "\nPlease restart and select a number between -2,147,483,648 and 2,147,483,647";		// This prevents the user from entering an number
		return 0;																						// too large for an integer variable to hold																
	}
	

	cout << "\nEnter second operand: ";		// Prompt to enter second number
	cin >> operand2;

	if (!(operand2 >= -2147483648 && operand2 <= 2147483647))
	{
		cout << "\nPlease restart and select a number between -2,147,483,648 and 2,147,483,647";		// This prevents the user from entering an number
		return 0;																						// too large for an integer variable to hold																

	}
	///////////

	cout << "\nSelect an operator from the menu: ";		// Prompt to select operator sign
	cin >> _operator;

	if (_operator == '/' && operand2 == 0)				// If statement to prevent division by 0
	{
		cout << "\nCannot divide by 0\n\nPress any key to exit...";		// Program exits if user attempts to divide by 0
		cin.ignore();
		cin.get();
		return 0;
	}

	switch (_operator)							// Switch statement to do the appropriate mathematical operation
	{
	case '+': solution = operand1 + operand2;
		break;
	case '-': solution = operand1 - operand2;
		break;
	case '*': solution = operand1 * operand2;
		break;
	case '/': solution = operand1 / operand2;
		break;
	case '%': solution = operand1 % operand2;
		break;
	default:
		{
			cout << "\nPlease restart and enter an operator from the menu" << endl;		// If operator is not from menu, program exits
			cout << "\nPress any key to exit..." << endl;

			cin.ignore();
			cin.get();

			return 0;
		}
	}

	cout << "\nSOLUTION: " << endl;
	cout << "___________________________________________" << endl;
	cout << operand1 << " " << _operator << " " << operand2 << " = " << solution << endl;
	cout << "___________________________________________" << endl;
			


	cout << "\n\nPress any key to exit..." << endl;		//I put this here so the program won't automatically close

	cin.ignore();		//This is to clear the keyboard buffer of the newline character after the last enter key press
	cin.get();			//This waits for a key press

	return 0;
}