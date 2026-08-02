// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

using namespace std;

// Define Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function declarations
void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverageScore(const vector<Student>& students);
double getStudentAverage(const Student& student);

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Please enter a number between 1 and 4.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageScore(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n\n";
                break;
        }
    }

    return 0;
}

// Display main menu
void displayMenu() {
    cout << "====================================\n";
    cout << "     STUDENT RECORD SYSTEM MENU     \n";
    cout << "====================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
}

// Helper function to calculate a student's average
double getStudentAverage(const Student& student) {
    if (student.scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

// 1. Add a Student
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cin.ignore(); // Clear newline from input stream
    cout << "Student name: ";
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    while (!(cin >> newStudent.id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Please enter a valid integer ID: ";
    }

    int numScores;
    cout << "How many scores? ";
    while (!(cin >> numScores) || numScores < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid non-negative number of scores: ";
    }

    for (int i = 1; i <= numScores; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        while (!(cin >> score)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid score. Re-enter score " << i << ": ";
        }
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully.\n\n";
}

// 2. Display All Students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n\n";
        return;
    }

    cout << "\n================ ALL STUDENT RECORDS ================\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id << " | Name: " << student.name << "\n";
        cout << "Scores: ";
        if (student.scores.empty()) {
            cout << "None";
        } else {
            for (size_t i = 0; i < student.scores.size(); i++) {
                cout << student.scores[i] << (i + 1 < student.scores.size() ? ", " : "");
            }
        }
        cout << "\nAverage Score: " << fixed << setprecision(2) << getStudentAverage(student) << "\n";
        cout << "----------------------------------------------------\n";
    }
    cout << endl;
}

// 3. Calculate Average Score for a Specific Student
void calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n\n";
        return;
    }

    int targetId;
    cout << "Enter student ID: ";
    if (!(cin >> targetId)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID format!\n\n";
        return;
    }

    bool found = false;
    for (const auto& student : students) {
        if (student.id == targetId) {
            double avg = getStudentAverage(student);
            cout << student.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << "\n\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student with ID " << targetId << " not found!\n\n";
