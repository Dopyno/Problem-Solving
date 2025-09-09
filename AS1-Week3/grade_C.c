/*To achieve Marks (Between 50-59) (User Input and Study Goal Check)
Complete all previous steps, then:
    • Retrieve study hours for Maths, Programming, and Networking from the user.
    • Add a weekly study goal and compare it with the total study hours.
    • Print whether the user has met the goal or needs to study more.*/

#include <stdio.h>

int main()
{
    // Create variable
    int mathsHours, programmingHours, networkingHours, totalHours, goal;

    // Ask user to set the weekly goal
    printf("\n\nPlease set a learning goal for this week: ");
    scanf("%d", &goal);

    // Retrieve study hours for Maths, Programming, and Networking from the user.
    printf("\nHow many hours did you study this week for Math: ");
    scanf("%d", &mathsHours);
    printf("How many hours did you study this week for Programming: ");
    scanf("%d", &programmingHours);
    printf("How many hours did you study this week for Networking: ");
    scanf("%d", &networkingHours);

    // Calculate the total hours
    totalHours = mathsHours + programmingHours + networkingHours;

    // Print the goal and total into the terminal
    printf("\nYor goal for this week is %d hours of study.\nYou achieve a total of %d hours of study, as following: \n", goal, totalHours);
    printf("Maths:       %d\n", mathsHours);
    printf("Programming: %d\n", programmingHours);
    printf("Networking:  %d\n", networkingHours);

    // Compare the goal with the total hours
    // Print whether the user has met the goal or needs to study more.
    if (goal <= totalHours)
    {
        if (totalHours > goal)
        {
            printf("Amazing! You went beyond your study goal. Keep it up!");
        }
        else
        {
            printf("Great job! You have met your study goal.\n");
        }
    }
    else
    {
        if (goal - totalHours < 3)
        {
            printf(" You're almost there! Just a little more effort to reach your goal.");
        }
        else
        {
            printf("Keep going! You need to study more to meet your goal.\n");
        }
    }
    return 0;
}