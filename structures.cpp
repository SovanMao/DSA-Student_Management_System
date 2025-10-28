#include "srms.h"
#include <iostream>

// ============================================================================
// MODULE 4: DYNAMIC DATA TRACKING (LINKED LISTS)
// ============================================================================
// History (Linked List)
History::History() : head(nullptr) {}

History::~History() {
    while (head != nullptr) {
        HistoryNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void History::add(const Student& s, const string& op) {
    HistoryNode* newNode = new HistoryNode;
    newNode->student = s;
    newNode->operation = op;
    newNode->next = head;
    head = newNode;
}

void History::display() {
    cout << "\n=== HISTORY ===" << endl;
    if (head == nullptr) {
        cout << "No history records." << endl;
        return;
    }
    
    HistoryNode* current = head;
    int count = 1;
    while (current != nullptr && count <= 5) { // Show last 5 records
        cout << count << ". " << current->operation << ": ";
        current->student.display();
        current = current->next;
        count++;
    }
}

// ============================================================================
// MODULE 5: UNDO OPERATION SYSTEM (STACKS)
// ============================================================================
// Undo System (Stack)
void UndoSystem::save(const Student& s) {
    undoStack.push(s);
}

Student UndoSystem::undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!" << endl;
        return Student();
    }
    
    Student s = undoStack.top();
    undoStack.pop();
    return s;
}

bool UndoSystem::canUndo() {
    return !undoStack.empty();
}

// ============================================================================
// MODULE 6: PRINT REQUEST MANAGEMENT (QUEUES)
// ============================================================================
// Print Queue
void PrintQueue::addRequest(int id) {
    // Check if student exists
    bool found = false;
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].id == id) {
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Student with ID " << id << " not found!" << endl;
        return;
    }
    
    requests.push(id);
    cout << "Print request added for student ID: " << id << endl;
}

void PrintQueue::processRequest() {
    if (requests.empty()) {
        cout << "No print requests!" << endl;
        return;
    }
    
    int id = requests.front();
    requests.pop();
    
    cout << "\n--- PROCESSING PRINT REQUEST ---" << endl;
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].id == id) {
            cout << "Printing report for: ";
            studentArray[i].display();
            cout << "Print completed!" << endl;
            return;
        }
    }
    cout << "Student not found for printing!" << endl;
}

void PrintQueue::showQueue() {
    cout << "\n=== PRINT QUEUE ===" << endl;
    if (requests.empty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    
    cout << "Requests in queue: " << requests.size() << endl;
    cout << "\nStudents in queue (in order):" << endl;
    
    // Create a temporary queue to display without modifying original
    queue<int> tempQueue = requests;
    int position = 1;
    
    while (!tempQueue.empty()) {
        int studentId = tempQueue.front();
        tempQueue.pop();
        
        // Find and display the student with this ID
        bool found = false;
        for (int i = 0; i < totalStudents; i++) {
            if (studentArray[i].id == studentId) {
                cout << position << ". ";
                studentArray[i].display();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << position << ". ID: " << studentId << " (Student not found in system)" << endl;
        }
        
        position++;
    }
}

bool PrintQueue::isEmpty() {
    return requests.empty();
}

// ============================================================================
// MODULE 8: HIERARCHICAL DATA ORGANIZATION (BINARY SEARCH TREES)
// ============================================================================
// BST
BST::BST() : root(nullptr) {}

BST::~BST() {
    cleanup(root);
}

void BST::cleanup(TreeNode* node) {
    if (node != nullptr) {
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }
}

void BST::insert(TreeNode*& node, const Student& s) {
    if (node == nullptr) {
        node = new TreeNode;
        node->student = s;
        node->left = nullptr;
        node->right = nullptr;
        return;
    }
    
    if (s.score < node->student.score) {
        insert(node->left, s);
    } else {
        insert(node->right, s);
    }
}

void BST::insertStudent(const Student& s) {
    insert(root, s);
}

void BST::display(TreeNode* node) {
    if (node != nullptr) {
        display(node->left);
        node->student.display();
        display(node->right);
    }
}

void BST::showRankings() {
    cout << "\n=== STUDENT RANKINGS (Low to High Score) ===" << endl;
    if (root == nullptr) {
        cout << "No students in ranking tree." << endl;
        return;
    }
    display(root);
}

void BST::buildFromArray() {
    cout << "\n--- BUILDING BST ---" << endl;
    
    // Clear existing tree
    cleanup(root);
    root = nullptr;
    
    // Add all students to BST
    for (int i = 0; i < totalStudents; i++) {
        insertStudent(studentArray[i]);
    }
    
    cout << "BST built with " << totalStudents << " students." << endl;
}