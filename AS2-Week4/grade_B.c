#include <stdio.h>
#include <ctype.h> // used to use the function toupper() or tolower() to capture user user choice

int main()
{
    // Create variable  for rideType
    char thrill = 'T';
    char water = 'W';
    char family = 'F';
    // Create variable for ticketPrice
    char standard = 'S';
    char fastPass = 'F';
    char userChoice, type;          // create variable to store the user selection
    int numberOfTickets = 0, price; // to store the number of tickets and the price
    float total = 0.0;

    // Display the tickets, passes, meal package and discount for more then 5 tickets
    printf("\n========   Ticket and passes  s=========\n");
    printf("Thrill: £20 for Standard, £30 for Fast Pass.\n");
    printf("Water: £18 for Standard, £28 for Fast Pass.\n");
    printf("Family: £15 for Standard, £25 for Fast Pass.\n");
    printf("Meal package just £6.50 per ticket!\n");
    printf("15%% discount for more the 5 tickets!\n"); // add double % as an escape sequence for %

    // Ask the user to select the the ticket and the type
    printf("\nPlease select you ticket “T” for Thrill,“W” for Water or “F” for Family: ");
    scanf(" %c", &userChoice);
    printf("\nPlease select you ticket type “S” for Standard or “F” for Fast Pass: ");
    scanf(" %c", &type);
    printf("\nPlease select the number of tickets: : ");
    scanf("%d", &numberOfTickets);

    // Use swich to select the user choice
    printf("\n========   Receipt  ========\n"); // just to print at the end in an receipt format
    switch (toupper(userChoice))
    {
    case 'T':
        printf("Ride Type: Thrill\n");
        if (toupper(type) == 'S') // use If Else statement to select the standard or the fast track
        {
            printf("Ticket Type: Standard\n");
            price = 20;                      // Set the price for each sselection
            total = price * numberOfTickets; // calculate the total based on the number of tickets
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            price = 30;
            total = price * numberOfTickets;
        }
        break;
    case 'W':
        printf("Ride Type: Water\n");
        if (toupper(type) == 'S') // use If Else statement to select the standard or the fast track
        {
            printf("Ticket Type: Standard\n");
            price = 18;
            total = price * numberOfTickets;
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            price = 28;
            total = price * numberOfTickets;
        }
        break;
    case 'F':
        printf("Ride Type: Family\n");
        if (toupper(type) == 'S')
        {
            printf("Ticket Type: Standard\n");
            price = 15;
            total = price * numberOfTickets;
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            price = 25;
            total = price * numberOfTickets;
        }
        break;
    } // print the number of tickets and the total cost
    printf("Number of tickets: %d\n", numberOfTickets);
    printf("Total cost: £%.2f\n", total);
    printf("===========================");
    return 0;
}