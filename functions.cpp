#include "srms.h"
#include <iostream>

// ============================================================================
// MODULE 1: STUDENT ARRAY MANAGER (STATIC ARRAYS)
// ============================================================================
// CONCEPT: ARRAY
// Description: Store and access student records using static arrays with 
//              traversal, insertion, deletion, and search functions.
// ============================================================================

// Global variables
Student studentArray[MAX_STUDENTS];
int totalStudents = 0;

// Global instances
History history;
UndoSystem undoSystem;
PrintQueue printQueue;
BST bst;
void displayAllStudents() {
    cout << "\n=== ALL STUDENTS ===" << endl;
    if (totalStudents == 0) {
        cout << "No students found." << endl;
        return;
    }
    
    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". ";
        studentArray[i].display();
    }
    cout << "Total: " << totalStudents << " students" << endl;
}

void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        cout << "Cannot add more students. Maximum reached!" << endl;
        return;
    }
    
    int id;
    string name;
    string major;
    double score;
    
    cout << "\n--- ADD STUDENT ---" << endl;
    cout << "Enter student ID: ";
    cin >> id;
    
    // Check for duplicate ID
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].id == id) {
            cout << "Error: Student with ID " << id << " already exists!" << endl;
            return;
        }
    }
    
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student major: ";
    getline(cin, major);
    cout << "Enter student score (0-100): ";
    cin >> score;
    
    if (score < 0 || score > 100) {
        cout << "Error: Score must be between 0 and 100!" << endl;
        return;
    }
    
    studentArray[totalStudents] = Student(id, name, major, score);
    totalStudents++;
    
    history.add(studentArray[totalStudents-1], "ADD");
    cout << "Student added successfully!" << endl;
}

void deleteStudent() {
    if (totalStudents == 0) {
        cout << "No students to delete!" << endl;
        return;
    }
    
    int id;
    cout << "\n--- DELETE STUDENT ---" << endl;
    cout << "Enter student ID to delete: ";
    cin >> id;
    
    int index = -1;
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "Student not found!" << endl;
        return;
    }
    
    // Save for undo
    undoSystem.save(studentArray[index]);
    history.add(studentArray[index], "DELETE");
    
    // Shift elements
    for (int i = index; i < totalStudents - 1; i++) {
        studentArray[i] = studentArray[i + 1];
    }
    totalStudents--;
    
    cout << "Student deleted successfully!" << endl;
}

void searchStudent() {
    if (totalStudents == 0) {
        cout << "No students to search!" << endl;
        return;
    }
    
    int id;
    cout << "\n--- SEARCH STUDENT ---" << endl;
    cout << "Enter student ID: ";
    cin >> id;
    
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].id == id) {
            cout << "Student found at position " << (i + 1) << ":" << endl;
            studentArray[i].display();
            return;
        }
    }
    cout << "Student not found!" << endl;
}

// ============================================================================
// MODULE 2: RECURSIVE REPORT GENERATION (RECURSION)
// ============================================================================
// CONCEPT: RECURSION
// Description: Generate reports of students (e.g., outstanding or failed) 
//              using recursive functions.
// ============================================================================

// Recursive helper function to count and display pass students
int countPassStudentsRecursive(int index) {
    // Base case: if we've reached the end of the array
    if (index >= totalStudents) {
        return 0;
    }
    
    // Recursive case: check current student and recurse for the rest
    int count = 0;
    if (studentArray[index].score >= 60) {
        studentArray[index].display();
        count = 1;
    }
    
    // Recursive call: add count from remaining students
    return count + countPassStudentsRecursive(index + 1);
}

// Recursive helper function to count and display fail students
int countFailStudentsRecursive(int index) {
    // Base case: if we've reached the end of the array
    if (index >= totalStudents) {
        return 0;
    }
    
    // Recursive case: check current student and recurse for the rest
    int count = 0;
    if (studentArray[index].score < 60) {
        studentArray[index].display();
        count = 1;
    }
    
    // Recursive call: add count from remaining students
    return count + countFailStudentsRecursive(index + 1);
}

void showPassStudents() {
    cout << "\n=== PASS STUDENTS (Score >= 60) ===" << endl;
    int count = countPassStudentsRecursive(0);
    cout << "Total pass students: " << count << endl;
}

void showFailStudents() {
    cout << "\n=== FAIL STUDENTS (Score < 60) ===" << endl;
    int count = countFailStudentsRecursive(0);
    cout << "Total fail students: " << count << endl;
}

// ============================================================================
// MODULE 3: POINTER-BASED DATA ACCESS (POINTERS)
// ============================================================================
// Pointer Operations
void swapStudents() {
    if (totalStudents < 2) {
        cout << "Need at least 2 students to swap!" << endl;
        return;
    }
    
    cout << "\n--- SWAP STUDENTS ---" << endl;
    cout << "Current Students List:" << endl;
    for (int i = 0; i < totalStudents; i++) {
        cout << "Position " << (i + 1) << ": ";
        studentArray[i].display();
    }
    
    int pos1, pos2;
    cout << "\nEnter first student position (1-" << totalStudents << "): ";
    cin >> pos1;
    cout << "Enter second student position (1-" << totalStudents << "): ";
    cin >> pos2;
    
    pos1--; pos2--; // Convert to 0-based index
    
    if (pos1 < 0 || pos1 >= totalStudents || pos2 < 0 || pos2 >= totalStudents) {
        cout << "Invalid positions!" << endl;
        return;
    }
    
    // Swap using pointers
    Student* ptr1 = &studentArray[pos1];
    Student* ptr2 = &studentArray[pos2];
    Student temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
    cout << "\nSwap successful!" << endl;
    cout << "Position " << (pos1+1) << ": "; studentArray[pos1].display();
    cout << "Position " << (pos2+1) << ": "; studentArray[pos2].display();
}

void showPointers() {
    cout << "\n=== POINTER ADDRESSES ===" << endl;
    for (int i = 0; i < totalStudents; i++) {
        cout << "Position " << (i+1) << ": Address = " << &studentArray[i] << endl;
    }
}

// ============================================================================
// MODULE 7: SORTING & SEARCHING ENGINE (SORTING ALGORITHMS)
// ============================================================================
// Sorting by Score (Bubble Sort)
void sortByScore() {
    if (totalStudents <= 1) {
        cout << "Need at least 2 students to sort!" << endl;
        return;
    }
    
    for (int i = 0; i < totalStudents - 1; i++) {
        for (int j = 0; j < totalStudents - i - 1; j++) {
            if (studentArray[j].score < studentArray[j + 1].score) {
                Student temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }
    cout << "Students sorted by score (highest to lowest)!" << endl;
}

// Sorting by Name (Bubble Sort)
void sortByName() {
    if (totalStudents <= 1) {
        cout << "Need at least 2 students to sort!" << endl;
        return;
    }
    
    for (int i = 0; i < totalStudents - 1; i++) {
        for (int j = 0; j < totalStudents - i - 1; j++) {
            if (studentArray[j].name > studentArray[j + 1].name) {
                Student temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }
    cout << "Students sorted by name (A to Z)!" << endl;
}

// Legacy function for backward compatibility
void bubbleSort() {
    sortByScore();
}

void linearSearch() {
    if (totalStudents == 0) {
        cout << "No students to search!" << endl;
        return;
    }
    
    int id;
    cout << "\n--- LINEAR SEARCH ---" << endl;
    cout << "Enter student ID: ";
    cin >> id;
    
    for (int i = 0; i < totalStudents; i++) {
        cout << "Checking position " << (i+1) << "...";
        if (studentArray[i].id == id) {
            cout << " FOUND!" << endl;
            studentArray[i].display();
            return;
        }
        cout << " not found" << endl;
    }
    cout << "Student not found!" << endl;
}

// Sample Data
void loadSampleData() {
    cout << "Loading sample data..." << endl;
    
    if (totalStudents > 0) {
        cout << "Sample data already loaded or students exist!" << endl;
        return;
    }
    
    studentArray[0] = Student(101, "Alice", "Computer Science", 85.5);
    studentArray[1] = Student(102, "Bob", "Mathematics", 72.0);
    studentArray[2] = Student(103, "Carol", "Engineering", 95.0);
    studentArray[3] = Student(104, "David", "Biology", 45.5);
    studentArray[4] = Student(105, "Eva", "Physics", 88.0);
    studentArray[5] = Student(106, "Frank", "Chemistry", 67.0);
    studentArray[6] = Student(107, "Grace", "Mathematics", 92.0);
    studentArray[7] = Student(108, "Hannah", "Biology", 78.0);
    studentArray[8] = Student(109, "Ian", "Physics", 85.0);
    studentArray[9] = Student(110, "Jack", "Chemistry", 90.0);
    studentArray[10] = Student(111, "Kathy", "Computer Science", 73.5);
    totalStudents = 11;

    cout << "Sample data loaded: " << totalStudents << " students" << endl;
}