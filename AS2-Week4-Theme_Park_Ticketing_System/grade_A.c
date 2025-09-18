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
    char userChoice, repeatMenu, type, mealChoice; // create variable to store the user selection
    int numberOfTickets = 0, price, userOption, results;    // to store the number of tickets and the price
    float total = 0.0, mealPackage = 6.50, mealPackageTotal = 0.0, discount = 0.0;

    do
    {
        printf("\n========   Theme Park Ticketing System   =========\n\n");
        printf("1. Book Tickets.\n");
        printf("2. View ticket prices.\n");
        printf("3. Exit.\n");
        printf("Please select an option: ");
        scanf("%d", &userOption);

        switch (userOption)
        {
        case 1:
            // Display the tickets, passes, meal package and discount for more then 5 tickets
            printf("\n========   Ticket and passes  s=========\n");
            printf("Thrill: £20 for Standard, £30 for Fast Pass.\n");
            printf("Water:  £18 for Standard, £28 for Fast Pass.\n");
            printf("Family: £15 for Standard, £25 for Fast Pass.\n");
            printf("Meal package just £6.50 per ticket!\n");
            printf("15%% discount for more the 5 tickets!\n\n"); // add double % as an escape sequence for %

            // Ask the user to select the the ticket and the type
            printf("\nPlease select you ticket “T” for Thrill,“W” for Water or “F” for Family: ");
            scanf(" %c", &userChoice);
            printf("Please select you ticket type “S” for Standard or “F” for Fast Pass: ");
            scanf(" %c", &type);
           //validate the number of tickets
            do
            {
                printf("Please select the number of tickets: : ");
                results = scanf("%d", &numberOfTickets);
                if (results != 1){
                    printf("Invalid input, Please try again!\n");
                    while (getchar() != '\n');// clear input buffer
                   numberOfTickets = -1; //force the loop to repeat 
                }
                else if(numberOfTickets <= 0){
                    printf("Invalid input, please enter a number grater then 0!\n");
                }
            } while (numberOfTickets <= 0);
            printf("Do you want a meal package? Please type (Y / N) ");
            scanf(" %c", &mealChoice);

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
            }
            if (toupper(mealChoice) == 'Y') // verify if the user want meal or not
            {
                printf("Meal Package: Yes\n");
                mealPackageTotal = mealPackage * numberOfTickets; // if yes calculate the meal package total
            }
            else
            {
                printf("Meal Package: No\n");
            }
            // print the number of tickets and the total cost
            printf("Number of tickets: %d\n", numberOfTickets);
            printf("Total cost before discount: £%.2f\n", total);
            if (numberOfTickets >= 5)
            {
                discount = total * 0.15; // Calculate the 15% means: discount = total * 15 / 100
                printf("Bulk Discount: £%.2f\n", discount);
            }
            else
            {
                printf("Bulk Discount: £0\n");
            }
            printf("Meal Package Cost: £%.2f\n", mealPackageTotal);
            printf("Final Total Cost: £%.2f\n", total - discount + mealPackageTotal);
            printf("===========================\n");
            break;
        case 2:
            // Display the tickets, passes, meal package and discount for more then 5 tickets
            printf("\n========   Ticket and passes  s=========\n");
            printf("Thrill: £20 for Standard, £30 for Fast Pass.\n");
            printf("Water:  £18 for Standard, £28 for Fast Pass.\n");
            printf("Family: £15 for Standard, £25 for Fast Pass.\n");
            printf("Meal package just £6.50 per ticket!\n");
            printf("15%% discount for more the 5 tickets!\n\n"); // add double % as an escape sequence for %
            break;
        case 3:
            printf("Thank you for your purchase, enjoy the rides!\n");
            return 0; // use to terminate the execution
            break;
        }
        printf("Would you like to see the menu again (Y / N)?\n");
        scanf(" %c", &repeatMenu);
        if (tolower(repeatMenu) == 'n')
        {
            break;
        }

    } while (userOption != 3);

    return 0;
}