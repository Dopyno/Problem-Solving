#include <stdio.h>

int main()
{
    int numberOfSubjects;

    printf("\n===    Study Hours Monitor    ===\n\n");
    // ask the user for the number of subjects to store
    printf("Enter the number of subjects: ");
    scanf("%d", &numberOfSubjects);
    printf("\n");

    //create 2D array to store the subjects with user input length 
    // create arrays with same length to store weekly hours
    // create variable to store the weekly goal and the total
    char subjects[numberOfSubjects][25];
    int week1Hours[numberOfSubjects];
    int week2Hours[numberOfSubjects];
    int goalWeek1, goalWeek2, totalWeek1 = 0, totalWeek2 = 0; // total need to be 0, or can read old values from memory

    for (int i = 0; i < numberOfSubjects; i++)
    { // for loop to receive the subjects name and populate the 2D array
        printf("Enter the name of the subject %d: ", i + 1);
        scanf(" %[^\n]", subjects[i]);
    }
    printf("\n");
    // user to set the goal for both weeks
    printf("Enter your study goal for week 1: \n");
    scanf("%d", &goalWeek1);
    printf("Enter your study goal for week 2: \n");
    scanf("%d", &goalWeek2);
// ask user to input the study hours for each subjects - week 1
    printf("\nPlease enter the hours studied for week 1: \n");
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("Hours studied for %s: ", subjects[i]);
        scanf("%d", &week1Hours[i]);
        totalWeek1 += week1Hours[i]; // total capture each entry from the user with +=
    }
    // ask user to input the study hours for each subjects - week 2
    printf("\nPlease enter the hours studied for week 2: \n");
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("Hours studied for %s: ", subjects[i]);
        scanf("%d", &week2Hours[i]);
        totalWeek2 += week2Hours[i];
    }
    printf("\n");
    // print detail breakdown for week 1 by iterating both arrays subjects and week1
    printf("Week 1: Goal = %d, Total = %d\n", goalWeek1, totalWeek1);
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("%s : %d hours\n", subjects[i], week1Hours[i]);
    }
    printf("\n");
    // print detail breakdown for week 1 by iterating both arrays subjects and week2
    printf("Week 1: Goal = %d, Total = %d\n", goalWeek2, totalWeek2);
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("%s : %d hours\n", subjects[i], week2Hours[i]);
    }
    printf("\n");
    //compare both weeks to see if the user increase, decrease or maintain same level of learning
    printf("Week 1 and Week 2 - comparison: \n");
    if (totalWeek2 > totalWeek1)
        printf("Increase in study hours, well done!\n");
    else if (totalWeek2 < totalWeek1)
        printf("Decrease in study hours, you need some improvement!\n");
    else
        printf("No change in study hours.\n");

    return 0;
}