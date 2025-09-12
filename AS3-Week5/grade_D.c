// 1. Write a program that converts a single day's steps into calories burned.
// 2. Prompt the user to input the number of steps taken in a day.
// 3. Use a fixed conversion rate (any number between 0.04 and 0.06 calories per step).
// 4. Display the total calories burned.
// 5. Provide screenshots of the code and its outputs.
// 6. Use appropriate headings in the Word document to ensure the task is easily identifiable.

#include<stdio.h>

int main(){
    int steps = 0;
    float calories = 0, unitConversion = 0.05;
    printf("\nPlease enter the number of steps from today: ");
    scanf("%d", &steps);
    calories = steps * unitConversion;

    printf("Today you burn %.2f calories.\n", calories);


    return 0;
}