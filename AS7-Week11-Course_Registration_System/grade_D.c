#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the struct with 3 elements id, course code and status
struct Course
{
    int id;              // Course ID
    char courseCode[20]; // course code
    char status[10];     // course status
};
// prototype function declaration
void welcome();            // Display a welcome message
void addCourse();          // adds a new course to a file
void displayCoursesInfo(); // display all registered courses
void printOption();

int main()
{
    int userOption; // store user menu selection

    welcome();
    do
    {

        printOption(); // Call print option function to display the menu
        printf("Please select an option: ");
        scanf("%d", &userOption);
        switch (userOption)
        {
        case 1:
            addCourse(); // add new courses
            break;
        case 2:
            displayCoursesInfo(); // display all courses
            break;
        }
    } while (userOption != 0);

    return 0;
}

void addCourse()
{
    struct Course student; // create a Course struct to hold the input
                           // prompt user for course details
    printf("Enter your ID: ");
    scanf("%d", &student.id);
    printf("Enter your course code: ");
    scanf(" %[^\n]", student.courseCode); // read full line including spaces until press Enter
    printf("Enter your status: ");
    scanf(" %[^\n]", student.status); // read full line including spaces until press Enter
                                      // open the file in append mode to add a new entry
    FILE *file1 = fopen("registration.txt", "a");
    if (file1 == NULL)
    {
        printf("Error: File cannot be opened!\n"); // print a message if the file not exist
        return;
    } // write the course details to a file
    fprintf(file1, "%d, %s, %s\n", student.id, student.courseCode, student.status);
    fclose(file1); // close the file
    printf("Course added successfully!\n\n");
}
void displayCoursesInfo()
{
    FILE *file = fopen("registration.txt", "r"); // open the file in read mode
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n"); // print a message if the file not exist
        return;
    }
    char line[100]; // buffer to hold each line from the file
    printf("\n=======    Student Courses ========\n");
    while (fgets(line, 100, file)) // read and print each line from the file
    {
        printf("* %s", line);
    }
    printf("===================================\n");
    fclose(file); // Close the file
}
void welcome()
{
    printf("\n===  Courses Registration System!  ===\n");
    printf("\n");
}
void printOption() // function to print the menu option
{
    printf("\n1. Add a course (ID, Course Code, Status).\n");
    printf("2. Display all courses.\n");
    printf("3. Update existing courses.\n");
    printf("4. Delete courses.\n");
    printf("5. Save courses to a file and read from it for persistence.\n");
    printf("0. Exit\n");
}