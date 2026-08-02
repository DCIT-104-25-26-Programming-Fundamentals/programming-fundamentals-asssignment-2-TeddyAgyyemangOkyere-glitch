// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Part A: Transpose
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    cout << "\nTransposed Matrix:\n";
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Part B: Add Two Matrices
void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum Matrix:\n";
    displayMatrix(sum, rows, cols);
}

// Part C: Multiply Two Matrices
void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct Matrix:\n";
    displayMatrix(result, m, p);
}

int main()
{
    int choice;

    cout << "1. Transpose Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int matrix[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        inputMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, rows, cols);
    }
    else if (choice == 2)
    {
        int A[10][10], B[10][10];
        int rows, cols;

        cout << "Enter rows: ";
        cin >> rows;
        cout << "Enter columns: ";
        cin >> cols;

        cout << "\nEnter Matrix A:\n";
        inputMatrix(A, rows, cols);

        cout << "\nEnter Matrix B:\n";
        inputMatrix(B, rows, cols);

        addMatrices(A, B, rows, cols);
    }
    else if (choice == 3)
    {
        int A[10][10], B[10][10], result[10][10];
        int m, n, p;

        cout << "Enter rows of Matrix A: ";
        cin >> m;
        cout << "Enter columns of Matrix A: ";
        cin >> n;

        cout << "\nEnter Matrix A:\n";
        inputMatrix(A, m, n);

        cout << "\nEnter columns of Matrix B: ";
        cin >> p;

        cout << "\nEnter Matrix B (" << n << " x " << p << "):\n";
        inputMatrix(B, n, p);

        multiplyMatrices(A, B, result, m, n, p);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
