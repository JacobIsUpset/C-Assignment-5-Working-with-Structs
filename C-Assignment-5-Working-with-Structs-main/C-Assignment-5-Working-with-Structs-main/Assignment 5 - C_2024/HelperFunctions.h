//
// Created by Jacob on 2024-10-23.
//

#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#define MAX_NAME_LENGTH 100

struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    double grade;
};

int scanInt(const char *format,void *address);

void gradeCalculations(int numOfStudents, struct Student students[]);

void printStudents(int numOfStudents, struct Student students[]);


//inputs
void addNewStudent(int numOfStudents, struct Student students[]);

void (int numOfStudents, struct Student students[]);

//menu 3
void removeStudent(int numOfStudents, struct Student students[]);

#endif //HELPERFUNCTIONS_H