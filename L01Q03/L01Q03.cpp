/*
Author: Peter O'Donohue
Creation Date: 05/17/18
Modification Date: 05/17/18
Description: This program prints the smallest and largest values after seaching an entire array.
*/

#include <iostream>
using namespace std;

const int MAX_ROWS = 2;  // stores number of array rows
const int MAX_COLS = 3;  // stores number of array columns
const int MAX_DEPTH = 4;  // stores array depth

// function prototypes
void exit();
void greeting(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH]);
int computeMax(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH]);
int computeMin(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH]);

int main()
{
	int maxValue = 0;  // stores maximum array value
	int minValue = 0;  // stores minimum array value

	// initialize 3D array
	int arrayOne[MAX_ROWS][MAX_COLS][MAX_DEPTH] =
	{
		{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} },
		{ {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24} }
	};

	greeting(arrayOne);  // display greeting message
	maxValue = computeMax(arrayOne);  // compute and assign max array value
	minValue = computeMin(arrayOne);  // compute and assign min array value
	
	// print results
	cout << "The minimum value is: " << minValue << endl
		 << "The maximum value is: " << maxValue << endl << endl;

	system("pause");
	return 1;
}

// function definitions

void greeting(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH])
{
	//  PRE: tempArray has been initialized
	//  POST: the array has been read and printed

	// print greeting message
	cout << "Hello, this program searches the array below " << endl
		<< "for the largest and smallest values. The program then " << endl
		<< "prints these values out to you. " << endl;
	
	// print array
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		cout << endl << "{ ";
		for (int j = 0; j < MAX_COLS; ++j)
		{
			cout << "{";
			for (int k = 0; k < MAX_DEPTH; ++k)
			{
				cout << tempArray[i][j][k];
				if (k <= 2)
					cout << ", ";
				else if (k == 3)
					cout << "} ";
			}
		}
		cout << "}";
	}
	cout << endl << endl;
	return;
}

int computeMax(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH])
{
	// PRE: tempArray is initialized
	// POST: tempMax has new value and is returned to main function by value

	int tempMax = 0;  // stores maximum value 
	tempMax = tempArray[0][0][0];  // assign first array element to max value
	
	// search through entire array for largest value
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLS; ++j)
		{
			for (int k = 0; k < MAX_DEPTH; ++k)
			{
				if (tempMax < tempArray[i][j][k]) 
					tempMax = tempArray[i][j][k];  // assign new max value 
			}
		}
	}
	return tempMax;
}

int computeMin(int tempArray[MAX_ROWS][MAX_COLS][MAX_DEPTH])
{

	// PRE: the tempArray has been initialized
	// POST: tempMin has a new value and is returned to the main function by value
	int tempMin = 0;
	tempMin = tempArray[0][0][0]; // assign first array element to min value
	
	// search through entire array for smallest value
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLS; ++j)
		{
			for (int k = 0; k < MAX_DEPTH; ++k)
			{
				if (tempMin > tempArray[i][j][k])
					tempMin = tempArray[i][j][k];  // assign new min value 
			}
		}
	}
	return tempMin;
}

void exit()
{
	// PRE: the function of type void has been declared
	// POST: the function returns no value back to the main function

	cout << "Thanks for using my program, goodbye." << endl;
	return;
}
