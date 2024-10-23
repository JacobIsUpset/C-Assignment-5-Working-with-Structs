//
// Created by Jacob on 2024-10-23.
//

#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
    double grade;
};

int scanInt(const char *format,void *address)
{
    int i;
    int numOfTokensRead = scanf(format, &i);

    if (numOfTokensRead == 1) {
        // either there is only a newline left -> just pop off with getchar()
        // or there are a whole bunch of junk in addition to a newline left -> keep poppoing off until EOF or \n reached
        char x = getchar();
        while (x != EOF && x != '\n') {
            x = getchar();
        }
    } else {
        // we failed to read an integer, inform the user
        // we need to empty the buffer if necessary we failed to read
        printf("ERROR!,failed to read! clearing the buffer...\n");
        char x = getchar();
        while (x != EOF && x != '\n')
        {
            x = getchar();
        }
    }

    return numOfTokensRead;
}

void gradeCalculations(int numOfStudents, struct Student students[]) {
    // Calculate and display the average, minimum, and maximum grades of all students.
    int valueOfGrade = 0;
    // vars for grade calculation
    int highistGrade = 0;
    int lowestGrade = 100;
    int averageGrade = 0;
    int sumOfGrades = 0;

    for (int i = 0; i < numOfStudents ;i++)
    {
        valueOfGrade = students[i].grade;
        sumOfGrades += valueOfGrade;
        if (valueOfGrade > highistGrade){highistGrade = valueOfGrade;}
        if (valueOfGrade < lowestGrade){lowestGrade = valueOfGrade;}
        sumOfGrades += valueOfGrade;
    }

    averageGrade = sumOfGrades / numOfStudents;
    printf("Highest Grade: %d\n" ,highistGrade);
    printf("Lowest Grade: %d\n" ,lowestGrade);
    printf("Average Grade: %d\n" ,averageGrade);
}

void printStudents(int numOfStudents, struct Student students[]) {
    for (int i = 0; i < numOfStudents; i++) {
        {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Grade: %.2f\n", students[i].grade); // note to self: %.2f is the amount of decimal spaces you want it to print
        }
    }
}

void idInput(int numOfStudents, struct Student students[]) {
    while (1)
    {
        int idInput = 0;
        printf("enter the id of the student!\n");
        scanInt("%d", &idInput);
        if (idInput >= 0 && idInput <= 100)
        {
            students[numOfStudents].id = idInput;
            break;
        }
        printf("Error!, please try again\n");
    }
}

void nameInput(int numOfStudents, struct Student students[]) {
    while (1)
    {
        char nameInput[41];
        printf("enter the name of the student!");
        fgets(nameInput, sizeof(nameInput), stdin);
        strcpy(students[numOfStudents].name, nameInput);
        printf("\n");
        break;
    }
}

void ageInput(int numOfStudents, struct Student students[]) {
    while (1)
    {
        int ageInput = 0;
        printf("enter the age of the student!\n");
        scanInt("%d", &ageInput);
        if (ageInput >= 0 && ageInput <= 100)
        {
            students[numOfStudents].age = ageInput;
            break;
        }
        printf("Error!, please try again\n");
    }
}

void gradeInput(int numOfStudents, struct Student students[]) {
    while (1)
    {
        int gradeInput = 0;
        printf("Enter the grade of the student!\n");
        scanInt("%lf", &gradeInput);

        if (gradeInput >= 0 && gradeInput <= 100)
        {
            students[numOfStudents].grade = gradeInput;
            break;
        }
        printf("Error! Please enter a valid grade between 0 and 100.\n");
    }
}


void removeStudent(int numOfStudents, struct Student students[]) {
    int idInput = 0;

    while (1)
    {
        printf("please enter the id of the student you would like to remove!");
        scanInt("%d", &idInput);
        for (int i = 0; i < numOfStudents; i++) {
            if (students[i].id == idInput) {
                students[i].id = 0;
                strcpy(students[i].name, " ");
                students[i].age = 0;
                students[i].grade = 0;
                break;
            }
        }
        printf("ERROR!, no student is assigned to this id");
    }
}