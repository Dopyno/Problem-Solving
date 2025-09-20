#include <stdio.h>

int main()
{ // declare the variable
    int steps = 0, userChoice;
    char userAnswer;
    float calories = 0, cal = 0.0, unitConversion = 0.05, totalCalories = 0.0,
          caloriesBurned = 0.0, distanceInKm = 0.0;
    // use do while for user to add entries for multiple days
    do
    { // print the menu at least once
        printf("Which of these would you like to add to the record?\n");
        printf("1. Steps\n");
        printf("2. Calories\n");
        printf("3. Distance\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        // swich use to run each version the user choose
        switch (userChoice)
        {
        case 1:
            printf("\nPlease enter the number of steps: ");
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
            cal = (distanceInKm / 0.0008) * unitConversion;
            totalCalories += cal;
            printf("Whilst walking %.2fkm, you have likely burned %.2f calories.\n", distanceInKm, cal);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
        // ask the user if he want to add entries for another day
        printf("\nDo you want to add another entry? (Y / N): ");
        scanf(" %c", &userAnswer);
    } while (userAnswer == 'y' || userAnswer == 'Y'); // run the code while user enter 'y' or 'Y'
    // print a detail version of his entries
    printf("\nYou have entered in total: \n");
    printf("%d steps (%.2f calories)\n", steps, calories);
    printf("%.2f calories\n", caloriesBurned);
    printf("%.2f km of distance walked (%.2f calories)\n", distanceInKm, cal);
    printf("\nOverall calories burned: %.2f calories\n", totalCalories);

    return 0;
}