/*To achieve Marks (Between 40-49) (Basic Study Hours Tracking)
• Create variables for three subjects: Maths, Programming, Networking.
• Assign values to these variables directly within the code.
• Calculate and print the total weekly study hours.*/

#include <stdio.h>

int main(){
    //* Create variable for three subjects and another one for total
    int mathsHours, programmingHours, networkingHours, totalHours;

    //* asign values within the code
    mathsHours = 15;
    programmingHours = 20;
    networkingHours = 10;

    //* Calculate the total hours
    totalHours = mathsHours + programmingHours + networkingHours;

    //* Print the total into the terminal
    printf("\nYou will need a total weekly study hours of %d to pass all modules, as following: \n", totalHours);
    printf("%-12s %2d\n", "Maths:", mathsHours);
    printf("%-12s %2d\n", "Programming:", programmingHours);
    printf("%-12s %2d\n", "Networking:", networkingHours);

    return 0;
}