//
// Created by Jacob on 2024-10-23.
//

#include <stdio.h>


int jScanInt(const char *format,void *address)
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

int JAverage(int totalNum, int numArray) {
    // Calculate and display the average, minimum, and maximum grades of all values in numArray.
    int valueOfGrade = 0;
    // vars for grade calculation
    int highestNum = 0;
    int lowestNum = 100;
    int averageNum = 0;
    int sumOfNum = 0;

    for (int i = 0; i < totalNum ;i++)
    {
        valueOfGrade = numArray[i];
        sumOfNum += valueOfGrade;
        if (valueOfGrade > highestNum){highestNum = valueOfGrade;}
        if (valueOfGrade < lowestNum){lowestNum = valueOfGrade;}
        sumOfNum += valueOfGrade;
    }

    averageNum = sumOfNum / totalNum;
    printf("\nHighest Grade: %d" ,highestNum);
    printf("\nLowest Grade: %d" ,lowestNum);
    printf("\nAverage Grade: %d" ,averageNum);
}