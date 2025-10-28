#include "srms.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\n=========================================" << endl;
    cout << "    STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "=========================================" << endl;
    
    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;
        }
        
        handleMenuChoice(choice);
        
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    cout << "Thank you for using SRMS!" << endl;
    return 0;
}