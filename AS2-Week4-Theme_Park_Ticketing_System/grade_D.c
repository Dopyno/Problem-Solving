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
    char userChoice, price;

    // Display the tickets and passes
    printf("\n========Ticket and passes=========\n");
    printf("Thrill: £20 for Standard, £30 for Fast Pass\n");
    printf("Water: £18 for Standard, £28 for Fast Pass\n");
    printf("Family: £15 for Standard, £25 for Fast Pass\n");

    // Ask the user to select the  ticket and the type
    printf("\nPlease select you ticket “T” for Thrill,“W” for Water or “F” for Family: ");
    scanf(" %c", &userChoice);
    printf("\nPlease select you ticket type “S” for Standard or “F” for Fast Pass: ");
    scanf(" %c", &price);

    // Use swich to select the user choice
    printf("\n=========   Receipt  =========\n"); // just to print at the end in an receipt format
    switch (toupper(userChoice))
    {
    case 'T':
        printf("Ride Type: Thrill\n");
        if (toupper(price) == 'S') // use If Else statement to select the standard or the fast track
        {
            printf("Ticket Type: Standard\n");
            printf("Total Ticket Price: £20.00\n");
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            printf("Total Ticket Price: £30.00\n");
        }
        break;
    case 'W':
        printf("Ride Type: Water\n");
        if (toupper(price) == 'S') // use If Else statement to select the standard or the fast track
        {
            printf("Ticket Type: Standard\n");
            printf("Total Ticket Price: £18.00\n");
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            printf("Total Ticket Price: £28.00\n");
        }
        break;
    case 'F':
        printf("Ride Type: Family\n");
        if (toupper(price) == 'S')
        {
            printf("Ticket Type: Standard\n");
            printf("Total Ticket Price: £15.00\n");
        }
        else
        {
            printf("Ticket Type: Fast Pass\n");
            printf("Total Ticket Price: £25.00\n");
        }
        break;
    }
    printf("=============================");
    return 0;
}