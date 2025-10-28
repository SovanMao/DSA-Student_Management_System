#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string major;
    double score;
    
    // Default constructor
    Student() : id(0), name(""), major(""), score(0.0) {}
    
    // Constructor
    Student(int studentId, string studentName, string studentMajor, double studentScore) 
        : id(studentId), name(studentName), major(studentMajor), score(studentScore) {}
    
    // Display student
    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Major: " << major << " | Score: " << score << endl;
    }
};

const int MAX_STUDENTS = 50;

#endif