// Programmer: Will Weidler
// Date: 9/24/22
// File: fishbomb.cpp
// Assignment: HW1

#include <iostream>
using namespace std;

// Function Declarations
void findBombSpot(const int test, const int & rows, const int & columns);

// Main
int main(){
	int testNum = 0;
	int num = 0;
	cin >> testNum;
	int roundNum = 0;
	while(roundNum < testNum){
		int rowsNum = 0;
		int columnsNum = 0;
		cin >> rowsNum;
		cin >> columnsNum;
		findBombSpot(roundNum, rowsNum, columnsNum);
		roundNum++;
	}
    return 0;
}

// Function Implementations
void findBombSpot(const int test, const int & rows, const int & columns){
	// Dynamic array for the sums of each row to find the most fish
	int* rowSum = new int[rows];
	// Dynamic array for the sums of each column to find the most fish
	int* columnSum = new int[columns];
	// For use to sum each row/column
	int lineSum = 0;
	// To store the greatest cross value 
	int greatestSum = 0;
	// X coordinate for best bomb drop
	int bestX = 0;
	// Y coordinate for best bomb drop
	int bestY = 0;

	// Creates dynamic 2D array pond
	int** pond = new int*[rows];
	for (int i = 0; i < rows; i++){
		pond[i] = new int[columns];
	}
	// Fills dynamic 2D array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> pond[i][j];
		}
	}
	// Sum up each row and store those values
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			lineSum += pond[i][j];
		}
		rowSum[i] = lineSum;
		lineSum = 0;
	}
	// Sum up each column and store those values
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			lineSum += pond[j][i];
		}
		columnSum[i] = lineSum;
		lineSum = 0;
	}

	// Find most fish cross
	int fishBombed = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if ((rowSum[i] + columnSum[j] - pond[i][j]) > fishBombed) 
			{
			fishBombed = (rowSum[i] + columnSum[j] - pond[i][j]);
			bestX = i;
			bestY = j;
			}
		}
	}
	// Output results
	cout << "#" << test << ": at (" << bestX << ", " << bestY << ") Bender catches " << fishBombed << " fish." << endl;
	
	// Eliminate memory leaks
	for(int i = 0; i < rows; i++){
		delete[] pond[i];
	}

	delete[] rowSum;
	delete[] columnSum;
	delete[] pond;
	return;
}