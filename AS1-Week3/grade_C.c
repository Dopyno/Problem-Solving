#include <stdio.h>

int main()
{
    char daysOfTheWeek[7] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
    int num;
    printf("On which day you want you week to start? \n");
    scanf("%d", &num);

    printf("***   July   ***\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%c  ", daysOfTheWeek[i]);
    }
    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("  ");
    }

    for (int i = 1; i <= 30; i++)
    {
        printf("%2d", i);
        if (i % 7 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    return 0;
}