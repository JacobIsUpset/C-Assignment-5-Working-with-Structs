#include <stdio.h>
#include <string.h>
#include "helperFunctions.h"

#define MaxNumOfStudents 100
// welcome to jacobs kino coding tutorial

int main() {
    // arrays
    struct Student students[MaxNumOfStudents];

    // size of
    int numOfStudents = 0;

    // The program should start by welcoming the user
    // and then continuously display the menu after each operation, until the user chooses to exit.
    printf("welcome!\n");

    while (1)
    {
        // value for selecting the menu
        int menuValue = 0;

        //menu
        printf("----- menu -----\n");
        printf("print all students - 1\n");
        printf("add new student - 2\n");
        printf("remove student by id - 3\n");
        printf("grade statistics - 4\n");
        printf("quit - 5\n");
        scanf("%d", &menuValue);


        if (menuValue == 1) {
            // Display the details (ID, Name, Age, and Grade) of all the students currently in the system.
            printStudents(numOfStudents, students);

        }else if (menuValue == 2){
            // Allow the user to enter details for a new student, making sure the ID is unique.
            // Ensure that the student’s name is no longer than 40 characters
            // and the age and grade are within reasonable ranges. If the list is full (100 students),
            // the program should inform the user that no more students can be added.

            //maxed out check
            if (numOfStudents >= MaxNumOfStudents) {
                printf("Too many students!, max amount reached!\n");
                continue;
            }

            //id input and validation
            idInput(numOfStudents, students);

            //name input and "validation"
            nameInput(numOfStudents, students);

            //age input and validation // DONE
            ageInput(numOfStudents, students);

            // Grade input and validation // DONE
            gradeInput(numOfStudents, students);

            numOfStudents++;

        } else if (menuValue == 3){
            // The user should be able to remove a student by entering their ID. If the ID does not exist, prompt the user to try again.
            removeStudent(numOfStudents, students);
        } else if (menuValue == 4){   // DONE
            gradeCalculations(numOfStudents,students);

        } else if (menuValue == 5){   // DONE
            // End the program when this option is selected.
            printf("goodbye!");
            break;
        }
        }
    }