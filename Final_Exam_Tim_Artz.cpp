#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void get_allocation();					// Function prototypes
void createFile(int, string, string[], int[], int[]);


string pointAllocationTests[100];			// Holds the assignment name
int pointAllocationPercent[100];			// Holds the percentage for the assignment as an integer
string dumpPercent;					// Gets rid of the percent sign in the syllabus
ifstream inputFile;
ofstream outputFile;


int main() 
{

	get_allocation();


	return 0;
}

void get_allocation()
{
	int count = 0;
	int numStudents;
	int numGrades;					// For the number of assignments to be graded
	string studentfile;				// For the student# filename
	string studentName1;			//For students first name
	string studentName2;			// For students second name
	string studentName3;			// For students last name
	string studentFullName;			// For students full name



	string pointsFile;
	

	cout << "Where are the point allocations stored?   ";

	cin >> pointsFile;


	inputFile.open(pointsFile);

	while (!inputFile)						// Check for valid file
	{
		cout << "Could not open file\nWhere are the point allocations stored?   " << endl;
		cin >> pointsFile;
		inputFile.open(pointsFile);
	}

	while (inputFile)						// Writes the data from the file into three arrays
	{
		inputFile >> pointAllocationTests[count];		// Array with the assignment names
		inputFile >> pointAllocationPercent[count];		// Array with the assignment percentage value as an integer
		inputFile >> dumpPercent;						// Writes the percent sign into a variable so it can be skipped

		count++;

		

	}
	

	inputFile.close();
	

	numGrades = --count;				// This is the number of tests and quizzes in selected syllabus


	cout << "\n\nThere are " << numGrades << " parts in this syllabus";
	cout << "\n\nHow many students?   ";
	cin >> numStudents;

	while (numStudents < 1 || numStudents > 3)
	{
		cout << "\n\nPlease enter a minimum of one and a maximum of 3 students:   ";
		cin >> numStudents;
	}

	

	
	for (int i = 0; i < numStudents; i++)
	{
		studentfile = "Student#" + to_string(i + 1) + ".txt";

		inputFile.open(studentfile);
		
		cout << "\nI'm opening \"" << studentfile << "\" answers\n";

		int gradesArray[100];			// To hold the students grades. 

		
			inputFile >> studentName1;				// Write the students name from the file and into a variable
			inputFile >> studentName2;
			inputFile >> studentName3;
			studentFullName = studentName1 + " " + studentName2 + " " + studentName3;


			
			
				for (int x = 0; x < numGrades; x++)
				{
					inputFile >> gradesArray[x];

					

				}
				createFile(numGrades, studentFullName, pointAllocationTests, pointAllocationPercent, gradesArray);

			inputFile.close();
	}
	
}

void createFile(int assignments, string student, string test[], int allocationPercent[], int gradesArr[])
{
	double credit[100];						// For the credit earned for each assignment
	double totalCredit = 0;						// Running tally of students credit

	outputFile.open(student + ".txt");

	

	outputFile << "\t" << student << "'s results\n\n" << setw(16) << "ITEM" << setw(16) << "WEIGHT";
	outputFile << setw(16) << "GRADE" << setw(16) << "POINTS EARNED" << "\n\n";

	for (int i = 0; i < assignments; i++)
	{
		credit[i] = static_cast<double>(allocationPercent[i] * gradesArr[i]) / 100;
		totalCredit += credit[i];

		outputFile << setw(16) << test[i] << setw(15) << allocationPercent[i] << "%" << setw(16) << gradesArr[i] << setw(16) << credit[i] << "\n";
		
	}

	outputFile << "\nCourse grade is " << totalCredit << "%\n\n";

	if (totalCredit < 70)
		outputFile << "\t" << student << " FAILED this course";
	else
		outputFile << "\t" << student << " PASSED this course";
	
	outputFile.close();

	cout << student << "'s results were stored in the corresponding file.\n";
}


