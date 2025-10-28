#ifndef SRMS_H
#define SRMS_H

#include "student.h"
#include <stack>
#include <queue>

// Global data
extern Student studentArray[MAX_STUDENTS];
extern int totalStudents;

// Basic Functions
void displayAllStudents();
void addStudent();
void deleteStudent();
void searchStudent();

// Reports (Recursive Functions)
int countPassStudentsRecursive(int index);
int countFailStudentsRecursive(int index);
void showPassStudents();
void showFailStudents();

// Pointer Operations
void swapStudents();
void showPointers();

// History (Linked List)
struct HistoryNode {
    Student student;
    string operation;
    HistoryNode* next;
};

class History {
private:
    HistoryNode* head;
public:
    History();
    ~History();
    void add(const Student& s, const string& op);
    void display();
};

// Stack (Undo)
class UndoSystem {
private:
    stack<Student> undoStack;
public:
    void save(const Student& s);
    Student undo();
    bool canUndo();
};

// Queue (Print)
class PrintQueue {
private:
    queue<int> requests;
public:
    void addRequest(int id);
    void processRequest();
    void showQueue();
    bool isEmpty();
};

// Sorting
void sortByScore();
void sortByName();
void bubbleSort();  // Legacy function
void linearSearch();

// BST
struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;
    void insert(TreeNode*& node, const Student& s);
    void display(TreeNode* node);
    void cleanup(TreeNode* node);
public:
    BST();
    ~BST();
    void insertStudent(const Student& s);
    void showRankings();
    void buildFromArray();
};

// Menu Functions
void displayMainMenu();
void handleMenuChoice(int choice);
void loadSampleData();

// Global instances
extern History history;
extern UndoSystem undoSystem;
extern PrintQueue printQueue;
extern BST bst;

#endif