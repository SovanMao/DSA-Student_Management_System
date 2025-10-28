# Student Record Management System (SRMS)
**Data Structures & Algorithms Mini-Final Project**

## 🎯 Project Overview

The Student Record Management System is a comprehensive C++ application designed to demonstrate various data structure and algorithm concepts through practical implementation. This educational project showcases 8 core computer science concepts integrated into a unified student management system.

## 📚 Data Structure Concepts Demonstrated

| Module | Concept | Implementation | Key Features |
|--------|---------|----------------|--------------|
| 1 | **Array** | Static array management | CRUD operations, traversal, search |
| 2 | **Recursion** | Recursive report generation | Outstanding/failed student reports |
| 3 | **Pointers** | Pointer-based operations | Array traversal, record swapping |
| 4 | **Linked List** | Singly linked list | Operation history tracking |
| 5 | **Stack** | Stack-based operations | Undo/Redo functionality |
| 6 | **Queue** | Queue management | Print request processing |
| 7 | **Sorting** | Multiple algorithms | Bubble, Selection, Insertion, Merge, Quick |
| 8 | **Binary Tree** | Binary Search Tree | Score-based student rankings |

## 🏗️ Project Structure

```
SRMS/
├── student.h              # Student class definition
├── srms.h                 # Main header with function prototypes
├── main.cpp               # Program entry point
├── array_manager.cpp      # Module 1-3: Array, Recursion, Pointers
├── data_structures.cpp    # Module 4-6: Linked List, Stack, Queue
├── sorting_searching.cpp  # Module 7: Sorting & Searching algorithms
├── bst.cpp                # Module 8: Binary Search Tree
├── menu_system.cpp        # User interface and navigation
├── Makefile               # Build configuration
└── README.md              # Project documentation
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Make utility (optional but recommended)
- Windows/Linux/macOS

### Compilation Options

#### Option 1: Using Makefile (Recommended)
```bash
# Build the project
make

# Build and run
make run

# Clean build files
make clean
```

#### Option 2: Manual Compilation
```bash
# Windows (PowerShell/CMD)
g++ -std=c++11 -Wall -o srms.exe main.cpp array_manager.cpp data_structures.cpp sorting_searching.cpp bst.cpp menu_system.cpp

# Linux/macOS
g++ -std=c++11 -Wall -o srms main.cpp array_manager.cpp data_structures.cpp sorting_searching.cpp bst.cpp menu_system.cpp
```

### Running the Program
```bash
# Windows
./srms.exe

# Linux/macOS
./srms
```

## 📋 Features & Usage

### 1. Array Manager
- **Display All Students**: View complete student records
- **Add New Student**: Insert student with ID, name, score, course
- **Delete Student**: Remove student by ID
- **Search Student**: Find student by ID
- **Traverse Array**: Index-based array iteration

### 2. Recursive Reports
- **Outstanding Students**: Score ≥ 85 (recursive filtering)
- **Failed Students**: Score < 60 (recursive counting)

### 3. Pointer Operations
- **Pointer Traversal**: Navigate array using pointer arithmetic
- **Student Swapping**: Exchange records using pointer manipulation

### 4. Record History (Linked List)
- **Operation Tracking**: Maintain chronological operation history
- **History Display**: View recent modifications (LIFO order)

### 5. Undo/Redo System (Stack)
- **Undo Operations**: Reverse last action
- **Redo Operations**: Restore undone action
- **State Management**: Stack-based operation tracking

### 6. Print Queue Manager
- **Add Print Requests**: Queue student reports for printing
- **Process Requests**: FIFO-based request handling
- **Queue Status**: View pending print jobs

### 7. Sorting Algorithms
- **Bubble Sort**: Score-based (with step visualization)
- **Selection Sort**: Name-based alphabetical ordering
- **Insertion Sort**: ID-based ascending order
- **Merge Sort**: Divide-and-conquer approach
- **Quick Sort**: Partition-based sorting

### 8. Binary Search Tree
- **BST Construction**: Build tree from student array
- **In-Order Traversal**: Display score-based rankings
- **Score Search**: Find students by specific score
- **Tree Visualization**: Display tree structure

## 🎓 Educational Value

### Algorithm Complexity Analysis
- **Array Operations**: O(1) access, O(n) search
- **Linked List**: O(1) insertion, O(n) traversal
- **Stack/Queue**: O(1) push/pop, enqueue/dequeue
- **Sorting**: O(n²) to O(n log n) depending on algorithm
- **BST Operations**: O(log n) average, O(n) worst case

### Programming Concepts Demonstrated
- **Object-Oriented Programming**: Classes, encapsulation
- **Memory Management**: Dynamic allocation, pointers
- **Algorithm Design**: Recursive and iterative approaches
- **Data Structure Implementation**: From scratch implementations
- **Error Handling**: Input validation, boundary checks

## 📊 Sample Data

The system includes pre-loaded sample data for testing:
- 8 diverse student records
- Various scores (45-95.5 range)
- Multiple courses (CS, Math, Physics, Chemistry)
- Different student statuses

## 🔧 Customization

### Adding New Features
1. **New Data Fields**: Modify `Student` struct in `student.h`
2. **Additional Operations**: Extend respective module files
3. **Menu Integration**: Update `menu_system.cpp`

### Performance Optimization
- Implement balanced BST (AVL/Red-Black)
- Add hash table for O(1) lookups
- Optimize sorting with hybrid algorithms

## 📝 Class Presentation Guide

### Recommended Demo Flow
1. **Introduction** (2 min): Project overview and objectives
2. **Data Structure Tour** (10 min): Demonstrate each module
3. **Algorithm Analysis** (5 min): Complexity discussion
4. **Integration Demo** (5 min): Show module interaction
5. **Q&A** (3 min): Address technical questions

### Key Talking Points
- **Practical Application**: Real-world relevance
- **Algorithm Trade-offs**: Time vs. space complexity
- **Design Decisions**: Why specific data structures were chosen
- **Scalability**: How the system could be extended

## 🐛 Troubleshooting

### Common Issues
- **Compilation Errors**: Ensure all files are in same directory
- **Linking Problems**: Verify all .cpp files are included
- **Runtime Errors**: Check for proper input validation

### Debug Mode
Compile with debug flags for detailed error information:
```bash
g++ -g -DDEBUG -std=c++11 -Wall -o srms_debug *.cpp
```

## 📖 Further Reading

### Related Topics
- Advanced Data Structures (B-trees, Heaps)
- Graph Algorithms (Dijkstra, BFS/DFS)
- Database Management Systems
- Software Design Patterns

### Recommended Extensions
- File I/O for persistent storage
- GUI implementation (Qt/GTK)
- Network integration for multi-user access
- Database backend integration

## 👥 Contributing

This is an educational project. For improvements:
1. Fork the repository
2. Create feature branch
3. Implement changes with documentation
4. Submit pull request

## 📄 License

Educational use only. Feel free to use as reference for learning purposes.

---

**Developed for Data Structures & Algorithms Course**  
*Demonstrating practical application of core CS concepts*