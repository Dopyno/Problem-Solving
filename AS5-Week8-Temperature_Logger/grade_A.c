#include <stdio.h>

int main()
{
    const int MAX_DAYS = 50;    // define the maximum readings in our array a constant of 50
    const int SENTINEL = -1;    // define a sentinels to terminate our readings from the user
    int tempReadings[MAX_DAYS]; // create an array with the max size of 50
    int numberOfDays = 0, total = 0, maxTemperature, minTemperature, userOption;
    int averageTemp = 0;
    int threshold, above = 0, below = 0; // the threshold from user, above and below will be calculated
    int weekCount = 0, weekTotal = 0, daysInWeek = 0, weeklyAverage;
    int daysAgo;

    printf("\nWelcome to our Temperature Logger!\n");
    // implement a sentinels to terminate our readings from the user
    printf("Please enter the temperature readings in °C (enter %d to stop): \n", SENTINEL);
    // create a for loop to record the readings
    for (int i = 0; i < MAX_DAYS; i++)
    {
        int temp; // declare a temp variable to capture the Sentinels
        printf("Please enter the value for the Day nr: %d\n", i + 1);
        scanf("%d", &temp);
        if (temp == SENTINEL) // stop reading the input
            break;
        tempReadings[i] = temp;
        total += tempReadings[i]; // capture the total to calculate the average
        numberOfDays++;
    }

    if (numberOfDays == 0) // no entries print a message and terminate the code with "return 0"
    {
        printf("\nNo readings entered. Exiting...\n");
        return 0;
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
        case 3:
            // iterate the array to find the min and the max value
            maxTemperature = tempReadings[0]; // set the max value to be the first element of the array
            minTemperature = tempReadings[0]; // set the min value to be the first element of the array
            for (int i = 0; i < numberOfDays; i++)
            {
                if (tempReadings[i] > maxTemperature)
                    maxTemperature = tempReadings[i];
                if (tempReadings[i] < minTemperature)
                    minTemperature = tempReadings[i];
            }
            printf("\nThe minimum temperature is: %d°C\n", minTemperature);
            printf("The maximum temperature is: %d°C\n", maxTemperature);
            printf("\n");
            break;
        case 4:
            printf("\nEnter threshold temperature in °C: ");
            scanf("%d", &threshold);
            for (int i = 0; i < numberOfDays; i++)
            {
                if (tempReadings[i] > threshold) // capture the days above
                    above++;
                else if (tempReadings[i] < threshold) // capture the days below
                    below++;
            }
            printf("Days above %d°C: %d\n", threshold, above);
            printf("Days below %d°C: %d\n", threshold, below);
            printf("\n");
            break;
        case 5:
            printf("\nWeekly average temperatures:\n");

            for (int i = 0; i < numberOfDays; i++)
            {
                weekTotal += tempReadings[i]; // make the sum of the input for 1 week
                daysInWeek++;

                if (daysInWeek == 7 || i == numberOfDays - 1)
                {
                    weekCount++;
                    weeklyAverage = weekTotal / daysInWeek; // calculate the average for 1 week or 7 days
                    printf("Week %d average : %d°C\n", weekCount, weeklyAverage);
                    weekTotal = 0; // reset the week and the days for the next week
                    daysInWeek = 0;
                }
            }
            printf("\n");
            break;
        case 6:
            printf("\nTemperature in reverse order: \n");
            for (int i = numberOfDays - 1; i >= 0; i--) // iterate in reverse order the array
            {
                daysAgo = (numberOfDays - 1) - i;             // calculate how many days ago each reading was, relative to today
                                                              // numberOfDays - 1 is the index of most recent reading
                if (daysAgo == 0)                             // -i subtracting i to tell us how far back are from today
                    printf("Today: %d°C\n", tempReadings[i]); // 0 print Today
                else if (daysAgo == 1)
                    printf("Yesterday: %d°C\n", tempReadings[i]); // 1 print yesterday
                else
                    printf("%d days ago: %d°C\n", daysAgo, tempReadings[i]); // x days ago
            }
            printf("\n");
            break;
        case 7:
            printf("Thank you for using our platform today!\n");
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