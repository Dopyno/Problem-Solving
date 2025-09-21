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
void welcome();                                           // Display a welcome message
void addCourse(int id, char courseCode[], char status[]); // adds a new course to a file
void displayCoursesInfo(struct Course student);           // display all registered courses
void printOption();                                       // display the menu
void searchCourses();                                     // search courses by id

int main()
{
    struct Course student; // create a Course struct to hold the input
    int userOption;        // store user menu selection
    welcome();
    do
    {
        printOption(); // Call print option function to display the menu
        printf("Please select an option: ");
        scanf("%d", &userOption);
        switch (userOption)
        {
        case 1: // prompt user for course details
            printf("\nEnter your ID: ");
            scanf("%d", &student.id);
            printf("Enter your course code: ");
            scanf(" %[^\n]", student.courseCode); // read full line including spaces until press Enter
            printf("Enter your status: ");
            scanf(" %[^\n]", student.status); // read full line including spaces until press Enter
            addCourse(student.id, student.courseCode, student.status);
            break;
        case 2:
            displayCoursesInfo(student); // display the course info
            break;
        case 3:
            searchCourses();
            break;
        }
    } while (userOption != 0);

    return 0;
}
// adds new course to the registration file
void addCourse(int id, char courseCode[], char status[])
{
    FILE *file = fopen("registration.txt", "r"); // open the file in read mode to check for duplicate id
    if (file != NULL)                            // if the file exist(not null)
    {
        char line[100];
        int fieldId;
        while (fgets(line, 100, file)) // read each line and extract the id
        {
            sscanf(line, "%d,", &fieldId);
            if (fieldId == id)
            {
                printf("Error: Course Id %d already exists! Cannot add duplicate. \n", id);
                fclose(file);
                return;
            }
        }
        fclose(file);
    } // append new course to a file
    FILE *file1 = fopen("registration.txt", "a");
    if (file1 == NULL)
    {
        printf("Error: File cannot be opened!\n");
        return;
    }
    fprintf(file1, "%d, %s, %s\n", id, courseCode, status);
    fclose(file1);
    printf("Course added successfully!\n\n");
}
void displayCoursesInfo(struct Course student) // display all courses stored in the file
{
    FILE *file = fopen("registration.txt", "r");
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n");
        return;
    }
    char line[100];
    printf("\n=======    Student Courses ========\n");
    while (fgets(line, 100, file)) // read and print each line
    {
        printf("* %s", line);
    }
    printf("===================================\n");
    fclose(file);
}
void welcome()
{
    printf("\n===  Courses Registration System!  ===\n");
    printf("\n");
}
void printOption() // display the menu for user interaction
{
    printf("\n1. Add a course (ID, Course Code, Status).\n");
    printf("2. Display all courses.\n");
    printf("3. Search courses.\n");
    printf("4. Update existing courses.\n");
    printf("5. Delete courses.\n");
    printf("6. Save courses to a file and read from it for persistence.\n");
    printf("0. Exit\n");
}
void searchCourses() // search a course by ID an display the result
{
    FILE *file = fopen("registration.txt", "r"); // open the file in read mode
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n");
        return;
    }
    int searchId;
    printf("Enter the course ID to search: ");
    scanf("%d", &searchId);

    char line[100];
    int fileId;
    int found = 0;

    printf("\n---------   Search Result   ---------\n");
    while (fgets(line, 100, file)) // read each line and compare the id
    {
        sscanf(line, "%d", &fileId);
        if (fileId == searchId) // if the id is found
        {
            printf("Course info:  %s", line); // print the course info
            found = 1;
        }
    }
    if (!found)
    {
        printf("No course found for this ID: %d\n", searchId);
    }
    printf("-------------------------------------\n");
    fclose(file); // close the file
}
