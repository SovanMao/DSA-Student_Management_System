# Student Record Management System (SRMS)
**Data Structures & Algorithms Educational Project**

## 🎯 Project Overview

The Student Record Management System is a comprehensive C++ console application that demonstrates 8 fundamental data structure and algorithm concepts through a practical student management system. This educational project integrates multiple computer science principles into a cohesive, interactive program designed for learning and demonstration purposes.

## 📚 Data Structure Concepts Demonstrated

| Module | Concept | Implementation | Key Features |
|--------|---------|----------------|--------------|
| 1 | **Arrays** | Static array management | Student storage, CRUD operations, traversal |
| 2 | **Recursion** | Recursive report generation | Pass/fail student reports using recursive functions |
| 3 | **Pointers** | Pointer-based data access | Student swapping using pointer arithmetic |
| 4 | **Linked Lists** | Singly linked list | Dynamic operation history tracking |
| 5 | **Stacks** | LIFO operations | Undo system for deleted students |
| 6 | **Queues** | FIFO operations | Print request management system |
| 7 | **Sorting Algorithms** | Bubble sort implementation | Sort by name/score with real-time execution |
| 8 | **Binary Search Trees** | BST for hierarchical data | Score-based student rankings and search |

## 🏗️ Project Files

```
SRMS/
├── student.h              # Student struct definition
├── srms.h                 # Function prototypes
├── main.cpp               # Program entry point
├── functions.cpp          # Arrays, Recursion, Pointers, Sorting
├── structures.cpp         # Linked List, Stack, Queue, BST
├── menu.cpp               # User interface system
└── README.md              # Documentation
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Windows PowerShell, Command Prompt, or Terminal

### Compilation
```bash
# Windows
g++ -o srms.exe main.cpp functions.cpp structures.cpp menu.cpp

# Linux/macOS  
g++ -o srms main.cpp functions.cpp structures.cpp menu.cpp
```

### Running the Program
```bash
# Windows
srms.exe

# Linux/macOS
./srms
```

## 📋 Main Features

### 1. Basic Functions (Arrays)
- Display, add, delete, and search students
- Static array operations with validation

### 2. Generate Reports (Recursion)
- Pass/fail student reports using recursive functions
- Score-based filtering (≥60 pass, <60 fail)

### 3. Pointer Operations
- Swap two students using pointer manipulation
- Shows memory address operations

### 4. View History (Linked Lists)
- Track all ADD/DELETE operations
- Shows last 5 operations performed

### 5. Undo System (Stacks)
- Restore deleted students
- LIFO (Last-In-First-Out) behavior

### 6. Print Queue (Queues)
- Manage print requests for student reports
- FIFO (First-In-First-Out) processing

### 7. Sorting & Search
- Sort students by name or score
- Uses bubble sort algorithm

### 8. Student Rankings (Binary Search Trees)
- Organize students by score in tree structure
- Shows hierarchical data organization

### 9. Load Sample Data
- 5 pre-loaded students for testing
- Various majors and score ranges

## 🎓 Educational Value

### Data Structures Demonstrated
- **Arrays**: Student storage and management
- **Linked Lists**: Operation history tracking
- **Stacks**: Undo functionality  
- **Queues**: Print job management
- **Binary Trees**: Score-based rankings
- **Recursion**: Report generation
- **Pointers**: Memory manipulation
- **Sorting**: Bubble sort algorithm

## 📊 Sample Data

5 pre-loaded students for testing:
- Alice (Computer Science, 85.5)
- Bob (Mathematics, 72.0)  
- Carol (Engineering, 95.0)
- David (Biology, 45.5)
- Eva (Physics, 88.0)

## 🔧 Student Data Structure

```cpp
struct Student {
    int id;           // Student ID
    string name;      // Student name
    string major;     // Academic major
    double score;     // Score (0-100)
};
```

## 🎯 Quick Demo

1. Load sample data (Option 9)
2. Display all students (Option 1)
3. Add a new student 
4. Generate pass/fail reports (Option 2)
5. Swap students (Option 3)
6. View operation history (Option 4)
7. Delete and undo (Options 1, 5)
8. Use print queue (Option 6)
9. Sort students (Option 7)
10. Show BST rankings (Option 8)

## 🐛 Troubleshooting

**If compilation fails:**
- Check all 4 .cpp files are in same folder
- Use correct file names: `main.cpp`, `functions.cpp`, `structures.cpp`, `menu.cpp`

**Program limits:**
- Maximum 50 students
- Handles invalid input automatically

## 📄 Project Info

**Course**: Data Structures & Algorithms  
**Language**: C++  
**Purpose**: Educational demonstration

---

*Demonstrates 8 fundamental data structures and algorithms in a practical student management system.*