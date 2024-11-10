// Chp5_PopulationBarChart.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Introductory Statement 
	cout << "This program generates a bar chart showing the population growth of Prairieville over the past century." << endl;
	cout << "(Each * represents 1,000 people)" << endl;

	// Open the file
	ifstream inputFile("People.txt");
	if (!inputFile) {
		cerr << "Error: Could not open file People.txt. Make sure the file exists and is in the correct directory." << endl;
		return 1;  // Exit program if file cannot be opened

	}

	cout << "\nPRAIRIEVILLE POPULATION GROWTH" << endl;
	cout << "(each * represents 1,000 people)" << endl;

	int year, population;

	// Read data from the file and display the bar chart
	while (inputFile >> year >> population) {
		// Validate the data to ensure population is non-negative
		if (population < 0) {
			cerr << "Error: Population data should be non-negative. Check the file contents." << endl;
			return 1;
		}

		cout << year << " ";

		// Calculate number of asterisks (each representing 1,000 people)
		int numAsterisks = population / 1000;
		for (int i = 0; i < numAsterisks; ++i) {
			cout << "*";
		}
		cout << endl;
	}

	// Check for file read errors
	if (inputFile.bad()) {
		cerr << "Error reading from file. Please check the file contents and format." << endl;
		return 1;
	}

	// Close the file 
	inputFile.close();
	return 0;

}

