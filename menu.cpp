#include "srms.h"
#include <iostream>

void displayMainMenu() {
    cout << "\n================================" << endl;
    cout << "    STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "================================" << endl;
    cout << "1. Basic Functions" << endl;
    cout << "2. Generate Reports" << endl;
    cout << "3. Pointer Operations" << endl;
    cout << "4. View History" << endl;
    cout << "5. Undo System" << endl;
    cout << "6. Print Queue" << endl;
    cout << "7. Sorting & Search" << endl;
    cout << "8. Student Rankings (BST)" << endl;
    cout << "9. Load Sample Data" << endl;
    cout << "0. Exit" << endl;
    cout << "================================" << endl;
    cout << "Enter choice: ";
}

// ============================================================================
// MODULE 1 MENU: STUDENT ARRAY MANAGER (STATIC ARRAYS)
// ============================================================================
void handleBasicFunctions() {
    int choice;
    do {
        cout << "\n--- BASIC FUNCTIONS ---" << endl;
        cout << "1. Display All Students" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: 
                displayAllStudents(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 2: 
                addStudent(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3: 
                deleteStudent(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 4: 
                searchStudent(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 0: 
                cout << "Returning to main menu..." << endl;
                return;
            default: 
                cout << "Invalid choice! Please select 1-5." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
        }
    } while (choice != 0);
}

// ============================================================================
// MODULE 2 MENU: RECURSIVE REPORT GENERATION (RECURSION)    
// ============================================================================
void handleReports() {
    int choice;
    do {
        cout << "\n--- REPORTS ---" << endl;
        cout << "1. Pass Students" << endl;
        cout << "2. Fail Students" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: 
                showPassStudents(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 2: 
                showFailStudents(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3: 
                cout << "Returning to main menu..." << endl;
                return;
            default: 
                cout << "Invalid choice! Please select 1-3." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
        }
    } while (choice != 3);
}

// ============================================================================
// MODULE 3 MENU: POINTER-BASED DATA ACCESS (POINTERS)
// ============================================================================
void handlePointerOps() {
    swapStudents();
}

// ============================================================================
// MODULE 5 MENU: UNDO OPERATION SYSTEM (STACKS)
// ============================================================================
void handleUndo() {
    if (undoSystem.canUndo()) {
        Student restored = undoSystem.undo();
        if (restored.id != 0) {
            cout << "Restored student: ";
            restored.display();
            // Add back to array if there's space
            if (totalStudents < MAX_STUDENTS) {
                studentArray[totalStudents] = restored;
                totalStudents++;
                cout << "Student restored to system!" << endl;
            }
        }
    } else {
        cout << "Nothing to undo!" << endl;
    }
}

// ============================================================================
// MODULE 6 MENU: PRINT REQUEST MANAGEMENT (QUEUES)
// ============================================================================
void handlePrintQueue() {
    int choice;
    do {
        cout << "\n--- PRINT QUEUE ---" << endl;
        cout << "1. Add Print Request" << endl;
        cout << "2. Process Request" << endl;
        cout << "3. Show Queue Status" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                printQueue.addRequest(id);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 2: 
                printQueue.processRequest(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3: 
                printQueue.showQueue(); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 0: 
                cout << "Returning to main menu..." << endl;
                return;
            default: 
                cout << "Invalid choice! Please select 0-3." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
        }
    } while (choice != 0);
}

// ============================================================================
// MODULE 7 MENU: SORTING & SEARCHING ENGINE (SORTING ALGORITHMS)
// ============================================================================
void handleSorting() {
    int choice;
    do {
        cout << "\n=== SORTING ALGORITHMS ===" << endl;
        cout << "1. Sort Students by Score" << endl;
        cout << "2. Sort Students by Name" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: 
                sortByScore(); 
                cout << "\nSorted Results:" << endl;
                displayAllStudents();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 2: 
                sortByName(); 
                cout << "\nSorted Results:" << endl;
                displayAllStudents();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 0: 
                cout << "Returning to main menu..." << endl;
                return;
            default: 
                cout << "Invalid choice! Please select 0-2." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
        }
    } while (choice != 0);
}

// ============================================================================
// MODULE 8 MENU: HIERARCHICAL DATA ORGANIZATION (BINARY SEARCH TREES)
// ============================================================================
void handleBST() {
    int choice;
    cout << "\n--- BST RANKINGS ---" << endl;
    cout << "1. Build BST from Students" << endl;
    cout << "2. Show Rankings" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: bst.buildFromArray(); break;
        case 2: bst.showRankings(); break;
        default: cout << "Invalid choice!" << endl;
    }
}

void handleMenuChoice(int choice) {
    switch (choice) {
        case 1: handleBasicFunctions(); break;
        case 2: handleReports(); break;
        case 3: handlePointerOps(); break;
        case 4: history.display(); break;
        case 5: handleUndo(); break;
        case 6: handlePrintQueue(); break;
        case 7: handleSorting(); break;
        case 8: handleBST(); break;
        case 9: loadSampleData(); break;
        case 0: cout << "Goodbye!" << endl; break;
        default: cout << "Invalid choice!" << endl;
    }
}