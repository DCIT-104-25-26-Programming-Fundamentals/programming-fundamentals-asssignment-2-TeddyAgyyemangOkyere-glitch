// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


// Function to print the multiplication table for a single number from 1 to 12 (PART A)
void printTable(int num) {
    cout << "Multiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << (num * i) << "\n";
    }
}

// Function for Part A
void partA() {
    int num;
    cout << "--- PART A: Single Table ---\n";
    cout << "Enter a number: ";
    cin >> num;
    cout << "\n";
    printTable(num);
}

// Function for Part B
void partB() {
    int n;
    cout << "--- PART B: Tables from 1 to N ---\n";
    cout << "Enter a number N: ";
    cin >> n;
    cout << "\n";
    
    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i < n) {
            cout << "------------------------------------\n";
        }
    }
}

int main() {
    // You can test both Part A and Part B sequentially:
    partA();
    cout << "\n====================================\n\n";
    partB();

    return 0;
}
