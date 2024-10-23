//
// Created by Jacob on 2024-10-23.
//

#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#endif //HELPERFUNCTIONS_H

struct Student {
    int id;
    char name[100];
    int age;
    double grade;
};

int scanInt(const char *format,void *address);

void gradeCalculations(int numOfStudents, struct Student students[]);

void printStudents(int numOfStudents, struct Student students[]);


//inputs
void idInput(int numOfStudents, struct Student students[]);

void nameInput(int numOfStudents, struct Student students[]);

void ageInput(int numOfStudents, struct Student students[]);

void gradeInput(int numOfStudents, struct Student students[]);

//menu 3
void removeStudent(int numOfStudents, struct Student students[]);