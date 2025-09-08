/*To achieve Marks (Between 40-49) (Basic Study Hours Tracking)
• Create variables for three subjects: Maths, Programming, Networking.
• Assign values to these variables directly within the code.
• Calculate and print the total weekly study hours.*/

#include <stdio.h>

int main()
{
    //* Create variable for three subjects
    int mathsHours, programmingHours, networkingHours;

    //* asign values within the code
    mathsHours = 15;
    programmingHours = 20;
    networkingHours = 10;

    //* Print the total into the terminal
    printf("\nYou will need a total weekly study hours of %d to pass all modules, as following: \n", mathsHours + programmingHours + networkingHours);
    printf("Maths:       %d\n", mathsHours);
    printf("Programming: %d\n", programmingHours);
    printf("Networking:  %d\n", networkingHours);

    return 0;
}