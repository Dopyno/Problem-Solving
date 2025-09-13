#include<stdio.h>

int main(){
    // declaring the variable
    int monthNumber, startingWeekDay, fixedMonth = 30;
    
     char daysOfTheWeek[7] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
    const char months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
    "September", "October", "November", "December"};

    printf("Please enter the month number you want to display (1 - 12): ");
    scanf("%d", &monthNumber);
    printf("Please enter the starting week day (1 = Monday, 7 = Sunday): ");
    scanf("%d", &startingWeekDay);

    //adjust for zero based index of the enums
    printf("%s", monthNumber[currentMonth]);


    return 0;
}