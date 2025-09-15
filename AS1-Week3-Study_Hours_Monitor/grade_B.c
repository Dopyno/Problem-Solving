// To achieve Marks (Between 60-69) (Multi-Week Tracking)
// Complete all previous steps, then:
// • Allow the user to input study hours for two consecutive weeks.
// • Calculate and print the total study hours for each week.
// • Print whether the user has met the goal or needs to study more (for each week)
// • Compare study hours between the two weeks and print whether study time
//   increased, decreased, or remained the same.

#include <stdio.h>

int main()
{
    // Create variable for week 1 and week 2
    int mathsHours, programmingHours, networkingHours, totalHours, goal;
    int mathsHoursWeek2, programmingHoursWeek2, networkingHoursWeek2, totalHoursWeek2, goalWeek2;

    // Ask user to enter the goal for week 1
    // Retrieve study hours for Maths, Programming, and Networking from the user for week 1
    printf("\nPlease set a learning goal for week 1: ");
    scanf("%d", &goal);
    printf("\nHow many hours did you study in week 1 for Math: ");
    scanf("%d", &mathsHours);
    printf("How many hours did you study in week 1 for Programming: ");
    scanf("%d", &programmingHours);
    printf("How many hours did you study in week 1 for Networking: ");
    scanf("%d", &networkingHours);

    // Ask user to enter the goal for week 2
    // Retrieve study hours for Maths, Programming, and Networking from the user for week 2
    printf("\nPlease set a learning goal for week 2: ");
    scanf("%d", &goalWeek2);
    printf("\nHow many hours did you study in week 2 for Math: ");
    scanf("%d", &mathsHoursWeek2);
    printf("How many hours did you study in week 2 for Programming: ");
    scanf("%d", &programmingHoursWeek2);
    printf("How many hours did you study in week 2 for Networking: ");
    scanf("%d", &networkingHoursWeek2);

    // Calculate the total hours for each week
    totalHours = mathsHours + programmingHours + networkingHours;
    totalHoursWeek2 = mathsHoursWeek2 + programmingHoursWeek2 + networkingHoursWeek2;

    // Print the goal and total into the terminal
    printf("\nYor goal for week 1 was %d hours of study and you achieve a total of %d hours of study, as following: \n", goal, totalHours);
    printf("Maths:       %d\n", mathsHours);
    printf("Programming: %d\n", programmingHours);
    printf("Networking:  %d\n", networkingHours);
    printf("\nYor goal for week 2 was %d hours of study and you achieve a total of %d hours of study, as following: \n", goalWeek2, totalHoursWeek2);
    printf("Maths:       %d\n", mathsHoursWeek2);
    printf("Programming: %d\n", programmingHoursWeek2);
    printf("Networking:  %d\n", networkingHoursWeek2);

    // Print whether the user has met the goal or needs to study more on week 1
    if (goal <= totalHours)
    {
        if (totalHours > goal)
        {
            printf("Amazing! You went beyond your study goal in week 1. Keep it up!\n");
        }
        else
        {
            printf("Great job! You have met your study goal in week 1.\n");
        }
    }
    else
    {
        if (goal - totalHours < 3)
        {
            printf(" You're almost there! Just a little more effort to reach your goal in week 1.\n");
        }
        else
        {
            printf("Keep going! You need to study more to meet your goal in week 1.\n");
        }
    }
    // Print whether the user has met the goal or needs to study more on week 2
    if (goalWeek2 <= totalHoursWeek2)
    {
        if (totalHoursWeek2 > goalWeek2)
        {
            printf("Amazing! You went beyond your study goal in week 2. Keep it up!\n");
        }
        else
        {
            printf("Great job! You have met your study goal in week 2.\n");
        }
    }
    else
    {
        if (goalWeek2 - totalHoursWeek2 < 3)
        {
            printf(" You're almost there! Just a little more effort to reach your goal in week 2.\n");
        }
        else
        {
            printf("Keep going! You need to study more to meet your goal in week 2.\n");
        }
    }

    // Compare study hours between the two weeks and print whether study time
    //   increased, decreased, or remained the same.
    if (totalHours == totalHoursWeek2)
    {
        printf("No improvement, the student maintain same level of study!");
    }
    else if (totalHours < totalHoursWeek2)
    {
        printf("Great, this week is more productive, significant improvement!");
    }
    else
    {
        printf("Decreased, student require more work this week!");
    }

    return 0;
}