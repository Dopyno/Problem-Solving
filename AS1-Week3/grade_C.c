/*To achieve Marks (Between 50-59) (User Input and Study Goal Check)
    Complete all previous steps, then:
    • Retrieve study hours for Maths, Programming, and Networking from the user.
    • Add a weekly study goal and compare it with the total study hours.
    • Print whether the user has met the goal or needs to study more.*/
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