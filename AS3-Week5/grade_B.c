// 1. Complete all previous steps.2. Add a menu system that allows the user to choose what to track :
// • 1 : Steps
// • 2 : Calories
// • 3 : Distance(of walking; assume 1 step = 0.0008 km)
//  3. Use conditional logic to perform the selected tracking operation.
//  4. Allow the user to return to the menu or exit.
// 5. Display a summary of all entries when the user quits, including total calories burned.#include <stdio.h>

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