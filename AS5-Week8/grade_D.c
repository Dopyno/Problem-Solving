#include <stdio.h>

int main()
{
    int numberOfDays, userOption, total = 0;
    int averageTemp = 0.0;

    // ask the user for how many days want to create the record
    printf("\nPlease enter the number of days you want to record temperature readings: ");
    scanf("%d", &numberOfDays);
    int tempReadings[numberOfDays]; // create an array with the size based on nr of days chosen by the user

    printf("Please input the temperature readings in °C: \n");
    // create a for loop to record the readings
    for (int i = 0; i < numberOfDays; i++)
    {
        printf("Please enter the value nr: %d\n", i + 1);
        scanf("%d", &tempReadings[i]);
        total += tempReadings[i]; // capture the total to calculate the average
    }
    printf("All the readings stored successfully!\n\n");

    do
    { // display the menu
        printf("1. Display all temperature readings.\n");
        printf("2. Calculate and display the average temperature overall.\n");
        printf("3. Find and display the highest and lowest temperature.\n");
        printf("4. Count the number of days above and below a user-defined threshold.\n");
        printf("5. Calculate and display the weekly average temperature.\n");
        printf("6. Reverse the order of temperature readings and display them.\n");
        printf("7. Exit the program.\n");
        printf("Please chose an option: \n");
        scanf("%d", &userOption);

        switch (userOption) // use switch to access the menu 
        {
        case 1:
            printf("\nFull list of you recordings: \n"); // print a list of all recordings
            for (int i = 0; i < numberOfDays; i++)
            {
                printf("The temperature for day %d: %d°C\n", i + 1, tempReadings[i]);
            }
            printf("\n");
            break;
        case 2:
            averageTemp = total / numberOfDays; // calculate the average temp
            printf("\nThe average temperature of %d days is: %d°C\n", numberOfDays, averageTemp);
            printf("\n");
            break;
        case 7:
            printf("Good bye!\n");
            printf("\n");
            break;
        default:
            printf("Error: Invalid option, please try again!\n");
            printf("\n");
            break;
        }
    } while (userOption != 7);

    return 0;
}