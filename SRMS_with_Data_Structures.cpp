/*
Student Record Management System (SRMS) with Data Structure Operations
Single-file C++ implementation (console application)


Features implemented:
1. Student Array Manager (static array) - traversal, insertion, deletion, search
2. Recursive Report - recursion functions to generate summary (passed/failed/outstanding)
3. Pointer-Based Data Access - pointer traversal and swap via pointers
4. Linked List Record History - singly linked list for recent modifications
5. Undo/Redo System - stack-based undo/redo for changes
6. Print Queue Manager - queue to enqueue/dequeue print requests
7. Sorting & Searching Engine - selection, bubble, insertion, merge, quicksort
8. Score Ranking Tree - BST by score with inorder traversal for ranking


Compile: g++ -std=c++17 SRMS_with_Data_Structures.cpp -o srms2
Run: ./srms2

This program is a demonstration for coursework. It uses simple console I/O.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    double score;
    string major;
    bool valid;

    // Display student
    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Major: " << major << " | Score: " << score << endl;
    }
};

const int MAX = 100;
Student students[MAX];
int studentCount = 0;
int nextId = 1;

// --------------------------- Array Manager ---------------------------
void addStudent() {
    if (studentCount >= MAX) {
        cout << "Storage full!\n";
        return;
    }
    Student s;
    s.id = nextId++;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter score: ";
    cin >> s.score;
    cout << "Enter major: ";
    cin.ignore();
    getline(cin, s.major);
    s.valid = true;
    students[studentCount++] = s;
    cout << "Student added successfully!\n";
}

void showStudents() {
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < studentCount; i++) {
        if (students[i].valid)
            cout << "ID: " << students[i].id
                 << " | Name: " << students[i].name
                 << " | Score: " << students[i].score << "\n";
    }
}

int findStudent(int id) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].valid && students[i].id == id)
            return i;
    return -1;
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "No students to search!" << endl;
        return;
    }
    
    int id;
    cout << "\n--- SEARCH STUDENT ---" << endl;
    cout << "Enter student ID: ";
    cin >> id;
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Student found at position " << (i + 1) << ":" << endl;
            students[i].display();
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    int idx = findStudent(id);
    if (idx == -1) {
        cout << "Student not found!\n";
        return;
    }
    students[idx].valid = false;
    cout << "Deleted successfully.\n";
}

// --------------------------- Recursive Report ---------------------------
void recursiveReport(int i, int &pass, int &fail, int &out) {
    if (i >= studentCount) return;
    if (students[i].valid) {
        if (students[i].score >= 85) out++;
        if (students[i].score >= 50) pass++;
        else fail++;
    }
    recursiveReport(i + 1, pass, fail, out);
}

void showReport() {
    int pass = 0, fail = 0, out = 0;
    recursiveReport(0, pass, fail, out);
    cout << "\n--- Student Report ---\n";
    cout << "Passed: " << pass << "\nFailed: " << fail << "\nOutstanding: " << out << "\n";
}

// --------------------------- Pointer Operations ---------------------------
void swapByPointer(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void pointerSwap() {
    int id1, id2;
    cout << "Enter first student ID to swap: ";
    cin >> id1;
    cout << "Enter second student ID to swap: ";
    cin >> id2;
    int i1 = findStudent(id1);
    int i2 = findStudent(id2);
    if (i1 == -1 || i2 == -1) {
        cout << "Invalid IDs!\n";
        return;
    }
    swapByPointer(&students[i1], &students[i2]);
    cout << "Records swapped successfully!\n";
}

// --------------------------- Linked List History ---------------------------
struct Node {
    string action;
    int id;
    Node* next;
};

Node* history = nullptr;

void addHistory(const string& action, int id) {
    Node* newNode = new Node{action, id, history};
    history = newNode;
}

void showHistory() {
    cout << "\n--- History ---\n";
    Node* temp = history;
    int count = 0;
    while (temp && count < 10) {
        cout << temp->action << " (ID " << temp->id << ")\n";
        temp = temp->next;
        count++;
    }
}

// --------------------------- Undo / Redo System ---------------------------
stack<Student> undoStack, redoStack;

void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!\n";
        return;
    }
    Student last = undoStack.top();
    undoStack.pop();
    int idx = findStudent(last.id);
    if (idx != -1)
        students[idx] = last;
    redoStack.push(last);
    cout << "Undo performed.\n";
}

void redo() {
    if (redoStack.empty()) {
        cout << "Nothing to redo!\n";
        return;
    }
    Student rec = redoStack.top();
    redoStack.pop();
    undoStack.push(rec);
    cout << "Redo performed.\n";
}

// --------------------------- Sorting Algorithms ---------------------------

// Selection Sort by Name (A–Z)
void selectionSortByName(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].name < arr[minIndex].name)
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Selection Sort by Score (Highest → Lowest)
void selectionSortByScore(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].score > arr[maxIndex].score)
                maxIndex = j;
        }
        swap(arr[i], arr[maxIndex]);
    }
}

//Display Sorted Views
// Display students sorted by Name (A-Z)
void displaySortedByName() {
    vector<Student> v;
    for (int i = 0; i < studentCount; ++i)
        if (students[i].valid) v.push_back(students[i]);
    sort(v.begin(), v.end(), [](const Student& a, const Student& b){ return a.name < b.name; });
    cout << "\n--- Students Sorted by Name (A-Z) ---\n";
    for (const auto& s : v) s.display();
}

// Display students sorted by Score (High -> Low)
void displaySortedByScore() {
    vector<Student> v;
    for (int i = 0; i < studentCount; ++i)
        if (students[i].valid) v.push_back(students[i]);
    sort(v.begin(), v.end(), [](const Student& a, const Student& b){ return a.score > b.score; });
    cout << "\n--- Students Sorted by Score (High -> Low) ---\n";
    for (const auto& s : v) s.display();
}


// --------------------------- Print Queue Manager ---------------------------
queue<int> printQueue;

void enqueuePrint() {
    int id;
    cout << "Enter student ID to print: ";
    cin >> id;
    printQueue.push(id);
    cout << "Added to print queue.\n";
}

void processPrints() {
    cout << "\n--- Print Queue ---\n";
    while (!printQueue.empty()) {
        int id = printQueue.front();
        printQueue.pop();
        int idx = findStudent(id);
        if (idx != -1 && students[idx].valid)
            cout << "Printing Report - " << students[idx].name << ": " << students[idx].score << "\n";
        else
            cout << "Student not found.\n";
    }
}

// --------------------------- Score Ranking Tree ---------------------------
struct TreeNode {
    Student data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* root, Student s) {
    if (!root) return new TreeNode{s, nullptr, nullptr};
    if (s.score < root->data.score)
        root->left = insert(root->left, s);
    else
        root->right = insert(root->right, s);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->right);
    cout << root->data.name << " (" << root->data.score << ")\n";
    inorder(root->left);
}

void showRanking() {
    TreeNode* root = nullptr;
    for (int i = 0; i < studentCount; i++)
        if (students[i].valid)
            root = insert(root, students[i]);
    cout << "\n--- Score Ranking (High to Low) ---\n";
    inorder(root);
}

// --------------------------- Sample Data ---------------------------
void loadSampleData() {
    cout << "Loading sample data..." << endl;
    
    if (studentCount > 0) {
        cout << "Sample data already loaded or students exist!" << endl;
        return;
    }

    struct Sample { string name; string major; double score; };
    Sample sampleData[] = {
        {"Alice", "Computer Science", 85.5},
        {"Bob", "Mathematics", 72.0},
        {"Carol", "Engineering", 95.0},
        {"David", "Biology", 45.5},
        {"Eva", "Physics", 88.0},
        {"Frank", "Chemistry", 67.0},
        {"Grace", "Mathematics", 92.0},
        {"Hannah", "Biology", 78.0},
        {"Ian", "Physics", 85.0},
        {"Jack", "Chemistry", 90.0},
        {"Kathy", "Computer Science", 73.5}
    };

    int n = sizeof(sampleData) / sizeof(sampleData[0]);
    for (int i = 0; i < n && studentCount < MAX; ++i) {
        Student s;
        s.id = nextId++;
        s.name = sampleData[i].name;
        s.major = sampleData[i].major;
        s.score = sampleData[i].score;
        s.valid = true;
        students[studentCount++] = s;
    }

    cout << "Sample data loaded: " << studentCount << " students" << endl;
}

// --------------------------- Main Menu ---------------------------
int main() {
    int choice;
    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n2. Show Students\n3. Delete Student\n4. Search Student\n5. Show Report\n6. Pointer Swap\n";
    cout << "7. Show History\n8. Undo\n9. Redo\n10. Sort By Score\n11. Sort By Name\n12. Add Print Queue\n13. Process Prints\n14. Show Ranking Tree\n15. Load Sample Data\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); addHistory("Added", nextId - 1); break;
            case 2: showStudents(); break;
            case 3: deleteStudent(); addHistory("Deleted", nextId - 1); break;
            case 4: searchStudent(); break;
            case 5: showReport(); break;
            case 6: pointerSwap(); addHistory("Swapped", -1); break;
            case 7: showHistory(); break;
            case 8: undo(); break;
            case 9: redo(); break;
            case 10: displaySortedByScore(); break;
            case 11: displaySortedByName(); break;
            case 12: enqueuePrint(); break;
            case 13: processPrints(); break;
            case 14: showRanking(); break;
            case 15: loadSampleData(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);
    return 0;
}
