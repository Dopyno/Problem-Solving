// Requirements:
// • Prompt the user to enter the number of days
// • Based on that number, create an array to store temperature readings for each day
// • Allow the user to input temperatures one by one
// • Implement a menu with the following options:

// To achieve Marks (Between 40-49):
// • Ask the user for how many days they wish to record temperature readings for.
// • Allow user input to store all temperature readings in an array of appropriate size.
// • Implement menu options 1 and 2 only.
// • Demonstrate user using both options to display all entered temperatures and to
// calculate the average.
// • Submit screenshots of code and outputs.

#include <stdio.h>

int main()
{
    int numberOfDays, userOption;
    
    // ask the user for how many days want to create the record
    printf("\nPlease enter the number of days you want to record temperature readings: ");
    scanf("%d", &numberOfDays);
    
    int tempReadings[numberOfDays]; // create an array with the size based on nr of days chosen by the user

    printf("Please input the temperature readings: \n");
    // create a for loop to record the readings
    for (int i = 0; i < numberOfDays; i++)
    {
        printf("Please enter the value nr: %d\n", i + 1);
        scanf("%d", &tempReadings[i]);
    }
    printf("All the readings stored successfully!\n\n");

    do
    {
        printf("1. Display all temperature readings.\n");
        printf("2. Calculate and display the average temperature overall.\n");
        printf("3. Find and display the highest and lowest temperature.\n");
        printf("4. Count the number of days above and below a user-defined threshold.\n");
        printf("5. Calculate and display the weekly average temperature.\n");
        printf("6. Reverse the order of temperature readings and display them.\n");
        printf("7. Exit the program.\n");
        printf("Please chose an option: \n");
        scanf("%d", &userOption);
        
        switch (userOption)
        {
            case 1:
            /* code */
            break;
            case 7:
            printf("Good bye!\n");
            break;
        }
    } while (userOption != 7);

    return 0;
}