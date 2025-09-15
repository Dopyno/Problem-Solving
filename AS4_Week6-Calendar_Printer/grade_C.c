#include <stdio.h>

int main()
{
    // declaring the variable
    int monthNumber, startingWeekDay, currentDay, fixedMonth = 30;
    int saturday = 0, sunday = 0;
    // creating arrays for days of the weeks and months 2D array
    char daysOfTheWeek[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fry", "Sat", "Sun"};
    char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August",
                           "September", "October", "November", "December"};

    // ask the user to select a month and a starting day
    printf("Please enter the month number you want to display (1 - 12): ");
    scanf("%d", &monthNumber);
    // add validation for user input
    if (monthNumber < 1 || monthNumber > 12)
    {
        printf("Error: Invalid month number! Please enter a number between 1 and 12.\n");
        return 1; // alert that the program terminate with an error or abnormal condition
    }
    printf("Please enter the starting week day (1 = Monday, 7 = Sunday): ");
    scanf("%d", &startingWeekDay);

    if (startingWeekDay < 1 || startingWeekDay > 7)
    {
        printf("Error: Invalid week number! Please enter a number between 1 and 7.\n");
        return 1; // alert that the program terminate with an error or abnormal condition
    }

    // determine number of days in selected month for year 2025
    switch (monthNumber)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        fixedMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        fixedMonth = 30;
        break;
    case 2:
        fixedMonth = 28;
        break;
    }

    // print the month that user selected
    if (monthNumber >= 1 && monthNumber <= 12)
        printf("Calendar for: %s 2025\n", months[monthNumber - 1]);

    // print hte day of the week header and calculate the number of rows
    for (int i = 0; i < sizeof(daysOfTheWeek) / sizeof(daysOfTheWeek[0]); i++)
        printf("%4s", daysOfTheWeek[i]); // %4s format the results to use 4 spaces for width alignment
    printf("\n");

    // adjusting the starting position ensure current day stay in range 0-6, 7n means Sunday
    currentDay = startingWeekDay % 7;
    if (currentDay == 0)
        currentDay = 7;

    for (int i = 1; i < currentDay; i++)
        printf("    "); // print 4 empty spaces for each empty day to align the first day correctly

    for (int i = 1; i <= fixedMonth; i++)
    {
        printf("%4d", i);    // %4d format and print day number in 4 spaces to align to the week days %4s
        if (currentDay == 6) // if the day is Saturday count it
            saturday++;
        if (currentDay == 7) // if the day is Saturday count it
            sunday++;

        if ((currentDay % 7) == 0)
        {
            printf("\n"); // move to the next row after Saturday
        }
        currentDay++;
        if (currentDay > 7)
            currentDay = 1;
    }
    // print the number of Saturday and Sundays
    printf("\nNumber of Saturdays: %d", saturday);
    printf("\nNumber of Sundays: %d", sunday);
    return 0;
}