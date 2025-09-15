// 1. Complete all previous steps.2. Add a menu system that allows the user to choose what to track :
// • 1 : Steps
// • 2 : Calories
// • 3 : Distance(of walking; assume 1 step = 0.0008 km)
//  3. Use conditional logic to perform the selected tracking operation.
//  4. Allow the user to return to the menu or exit.
// 5. Display a summary of all entries when the user quits, including total calories burned.#include <stdio.h>
#include<stdio.h>

int main()
{
    int steps = 0, userChoice;
    char userAnswer;
    float calories = 0, unitConversion = 0.05, totalCalories = 0.0, caloriesBurned = 0.0, distanceInKm = 0.0; // declare the variable

    do
    {
        printf("Which of these would you like to add to the record?\n");
        printf("1. Steps\n");
        printf("2. Calories\n");
        printf("3. Distance\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            printf("\nPlease enter the number of steps: "); // use Do/While ensure will run at least once
            scanf("%d", &steps);
            calories = steps * unitConversion;
            totalCalories += calories;
            printf("Calories burned:  %.2f calories.\n", calories);
            break;
        case 2:
            printf("Enter the number of calories burned: ");
            scanf("%f", &caloriesBurned);
            totalCalories += caloriesBurned;
            printf("%.2f calories were added to overall record.\n", caloriesBurned);
            break;
        case 3:
            printf("Enter the distance walked in km: ");
            scanf("%f", &distanceInKm);
            float cal = (distanceInKm / 0.0008) * unitConversion;
            totalCalories += cal;
            printf("Whilst walking %.2fkm, you have likely burned %.2f calories.\n", distanceInKm, cal);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }

        printf("\nDo you want to add another entry? (Y / N): ");
        scanf(" %c", &userAnswer);
    } while (userAnswer == 'y' || userAnswer == 'Y'); // run the code while user enter 'y' or 'Y'

    printf("\nOverall calories burned: %.2f calories", totalCalories);

    return 0;
}