/*To achieve Marks (Between 40-49) (Basic Study Hours Tracking)
• Create variables for three subjects: Maths, Programming, Networking.
• Assign values to these variables directly within the code.
• Calculate and print the total weekly study hours.*/

#include <stdio.h>

int main(){
    //* Create variable for three subjects and asign values directly within the code
    int mathsHours = 6, programmingHours = 10, networkingHours = 4, totalHours;

    //* Calculate the total hours
    totalHours = mathsHours + programmingHours + networkingHours;

    //* Print the total into the terminal
    printf("\nYou will need a total weekly study hours of %d, to pass all modules.\n\n", totalHours);

    return 0;
}