// 1. Complete all previous steps.
// 2. Extend the program to allow the user to input data for multiple days.
// 3. Use a loop to repeatedly prompt the user for daily steps and calculate calories.
// 4. After each entry, ask the user if they want to enter another day.
// 5. When the user quits, display the total number of days tracked.
// 6. Provide screenshots showing various outputs and cases.

#include <stdio.h>

int main()
{
    int steps = 0, days = 0;
    char userAnswer;
    float calories = 0, unitConversion = 0.05, totalCalories = 0.0; // declare the variable

    do
    {
        printf("\nPlease enter the number of steps: "); // use Do/While ensure will run at least once
        scanf("%d", &steps);
        calories = steps * unitConversion;
        totalCalories += calories;
        days++;
        printf("Calories burned:  %.2f calories.\n", calories);
        printf("Do you want to enter steps for another day? (Y / N): ");
        scanf(" %c", &userAnswer);
    } while (userAnswer == 'y' || userAnswer == 'Y'); // run the code while user enter 'y' or 'Y'

    printf("You calculated calories over %d days, and the total is %.2f calories burned by walking.", days, totalCalories);

    return 0;
}