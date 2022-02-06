// CIS-269-Module-4-Assignment-2.cpp 
// Author: John Gumm
// Created: 2/4/2022

/*

Write a program that uses a 3 × 3 array and randomly place each integer from 1 to 9 into the nine squares. 
The program calculates the magic number by adding all the numbers in the array and then dividing the sum by 3. 
The 3 × 3 array is a magic square if the sum of each row, each column, and each diagonal is equal to the magic number. 

Your program must contain at least the following functions: 
    a function to randomly fill the array with the numbers 
    and a function to determine if the array is a magic square. 
    
Run these functions for some large number of times, say 1,000, 10,000, or 1,000,000, and see the number of times the array is a magic square.

*/

#include <iostream>
#include <time.h>

using namespace std;

const int squareSize = 3;

//Function Prototypes
void randArray(int squareArray[squareSize][squareSize]);
void displayArray(int squareArray[squareSize][squareSize]);
double magicNumberCalculator(int squareArray[squareSize][squareSize]);
bool rowSum(int squareArray[squareSize][squareSize], double num);
bool colSum(int squareArray[squareSize][squareSize], double num);
bool diagSum(int squareArray[squareSize][squareSize], double num);

int main()
{
    // Initialize array
    int square[squareSize][squareSize];

    // Seed Randomizer
    srand(time(NULL));
    
    // Ask how many times to run
    int timesToRun;
    cout << "How many times would you like to run the program?" << endl;
    cin >> timesToRun;
    cout << endl;

    // Declare vars used in each iteration
    double magic;
    bool row;
    bool col;
    bool diag;
    int numOfMagicSquares = 0;

    // Each iteration of squares
    for (int i = 0; i < timesToRun; i++) {
    
        // Populate array with random numbers
        randArray(square);

        // Magic Number
        magic = magicNumberCalculator(square);

        // Row test
        row = rowSum(square, magic);

        // Column test
        col = colSum(square, magic);

        // Diagonal test
        diag = diagSum(square, magic);

        // Results
        if (row && col && diag) {
            displayArray(square);
            cout << "Square is a magic square" << endl << endl;
            numOfMagicSquares++;
        }

    }

    cout << "Total magic squares:     " << numOfMagicSquares << endl;
    cout << "Total non-magic squares  " << (timesToRun - numOfMagicSquares);

    return 0;
}

void randArray(int squareArray[squareSize][squareSize]) 
{
    for (int i = 0; i < squareSize; i++) {
        for (int j = 0; j < squareSize; j++) {
            
            squareArray[i][j] = (rand() % 9) + 1;
        }
    }
}

void displayArray(int squareArray[squareSize][squareSize])
{
    for (int i = 0; i < squareSize; i++) {
        for (int j = 0; j < squareSize; j++) {

            cout << squareArray[i][j] << " ";
        }
        cout << endl;
    }
}

double magicNumberCalculator(int squareArray[squareSize][squareSize])
{
    double magicNumber = 0;

    for (int i = 0; i < squareSize; i++) {
        for (int j = 0; j < squareSize; j++) {

            magicNumber += squareArray[i][j];
        }
    }

    return (magicNumber/squareSize);
}

// Return true if all rows add to magic number
bool rowSum(int squareArray[squareSize][squareSize], double num)
{

    double calc;

    for (int i = 0; i < squareSize; i++) {

        calc = 0;

        for (int j = 0; j < squareSize; j++) {

            calc += squareArray[i][j];
        }

        if (calc != num) { return false; }

    }

    return true;
}

// Return true if all columns add to magic number
bool colSum(int squareArray[squareSize][squareSize], double num) 
{
    
    double calc;

    for (int i = 0; i < squareSize; i++) {

        calc = 0;

        for (int j = 0; j < squareSize; j++) {

            calc += squareArray[j][i];
        }

        if (calc != num) return false;

    }

    return true;
}

bool diagSum(int squareArray[squareSize][squareSize], double num)
{
    
    // Starting at [0][0]
    double calc = 0;

    for (int i = 0; i < squareSize; i++) {

        calc += squareArray[i][i];

    }

    if (calc != num) return false;

    calc = 0;

    for (int i = 0; i < squareSize; i++) {
        
        calc += squareArray[i][squareSize - i];

    }

    if (calc != num) return false;

    return true;

}