#include <stdio.h>

int main()
{
    int numberOfSubjects;

    printf("\n===    Study Hours Monitor    ===\n\n");
    // ask the user for the number of subjects to store
    printf("Enter the number of subjects: ");
    scanf("%d", &numberOfSubjects);
    printf("\n");

    char subjects[numberOfSubjects][25];
    int week1Hours[numberOfSubjects];
    int week2Hours[numberOfSubjects];
    int goalWeek1, goalWeek2, totalWeek1 = 0, totalWeek2 = 0;



    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("Enter the name of the subject %d: ", i + 1);
        scanf(" %[^\n]", subjects[i]);
    }
    printf("\n");
    printf("Enter your study goal for week 1: \n");
    scanf("%d", &goalWeek1);
    printf("Enter your study goal for week 2: \n");
    scanf("%d", &goalWeek2);

    printf("\nPlease enter the hours studied for week 1: \n");
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("Hours studied for %s: ", subjects[i]);
        scanf("%d", &week1Hours[i]);
        totalWeek1 += week1Hours[i];
    }

    printf("\nPlease enter the hours studied for week 2: \n");
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("Hours studied for %s: ", subjects[i]);
        scanf("%d", &week2Hours[i]);
        totalWeek2 += week2Hours[i];
    }
    printf("\n");
    // print detail breakdown for week 1
    printf("Week 1: Goal = %d, Total = %d\n", goalWeek1, totalWeek1);
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("%s : %d hours\n", subjects[i], week1Hours[i]);
    }
    printf("\n");
    // print detail breakdown for week 1
    printf("Week 1: Goal = %d, Total = %d\n", goalWeek2, totalWeek2);
    for (int i = 0; i < numberOfSubjects; i++)
    {
        printf("%s : %d hours\n", subjects[i], week1Hours[i]);
    }
    printf("\n");
    printf("Week 1 and Week 2 - comparison: \n");
    if (totalWeek2 > totalWeek1)
        printf("Increase in study hours, well done!\n");
    else if (totalWeek2 < totalWeek1)
        printf("Decrease in study hours, you need some improvement!\n");
    else
        printf("No change in study hours.\n");

    return 0;
}