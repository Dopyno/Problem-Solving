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
void welcome();                                          // Display a welcome message
int addCourse(int id, char courseCode[], char status[]); // adds a new course to a file
void displayCoursesInfo(struct Course student);          // display all registered courses
void printOption();                                      // display the menu
int searchCourses();                                     // search function by id
int updateCourse();                                      // update function

int main()
{
    struct Course student; // create a Course struct to hold the input
    int userOption, result, update, search;

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
            scanf(" %[^\n]", student.status);                                   // read full line including spaces until press Enter
            result = addCourse(student.id, student.courseCode, student.status); // the function will return the status 0 or 1
            if (result == 0)
                printf("Course added to file!\n");
            else
                printf("Course was not added!.\n");
            break;
        case 2:
            displayCoursesInfo(student); // call display function
            break;
        case 3:
            search = searchCourses(); // the function will return the status 0 or 1
            if (search == 0)
                printf("Course found!\n");
            else
                printf("Course was not found!\n");
            break;
        case 4:
            update = updateCourse(); // call update function and capture the result 0 to complete and 1 to fail
            if (update == 0)
                printf("Course update complete!\n");
            else
                printf("Course update failed!\n");
            break;
        }
    } while (userOption != 0);

    return 0;
}
// adds new course to the registration file
int addCourse(int id, char courseCode[], char status[])
{
    FILE *file = fopen("registration.txt", "r");
    if (file != NULL)
    {
        char line[100];
        int fieldId;
        while (fgets(line, 100, file))
        {
            sscanf(line, "%d,", &fieldId);
            if (fieldId == id)
            {
                printf("Error: Course Id %d already exists! Cannot add duplicate. \n", id);
                fclose(file);
                return 1; // the program indicate a problem and return 1
            }
        }
        fclose(file);
    }
    FILE *file1 = fopen("registration.txt", "a");
    if (file1 == NULL)
    {
        printf("Error: File cannot be opened!\n");
        return 1; // the program indicate a problem and return 1
    }
    fprintf(file1, "%d, %s, %s\n", id, courseCode, status);
    fclose(file1);
    printf("Course added successfully!\n\n");
    return 0;
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
int searchCourses() // search a course by ID an display the result
{
    FILE *file = fopen("registration.txt", "r"); // open the file in read mode
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n");
        return 1; // problem by not finding the file
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
        fclose(file);
        return 1; // the course is not found
    }
    printf("-------------------------------------\n");
    fclose(file); // close the file
    return 0;     // the course is found and the program end successfully
}
int updateCourse() // function to update the course by id
{
    FILE *file = fopen("registration.txt", "r"); // open the file in read mode
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n"); // if the file not exist print a message
        return 1;                                         // problem by not finding the file
    }
    int updateId; // variable to store the id to be updated
    printf("Enter the course ID to update: ");
    scanf("%d", &updateId);

    FILE *tempFile = fopen("temp.txt", "w"); // create a temporary to store updated data
    if (tempFile == NULL)
    { // if the file cannot be created clean and exit
        printf("Error: Could not create the temporary file!\n");
        fclose(file);
        return 1; // indicate a problem by not creating the file
    }

    char line[100];                // buffer to read each file from the file
    int fieldId;                   // variable to store the id extracted from each line
    int found = 0;                 // flag to track whether the course was found
    while (fgets(line, 100, file)) // read each line from the original file
    {
        // extract the id from the line using scanf()
        if (sscanf(line, "%d,", &fieldId) == 1 && fieldId == updateId)
        { // if the id match, prompt the user for new course details
            char newCourseCode[20], newStatus[10];
            printf("Please enter the new course code: \n");
            scanf(" %[^\n]", newCourseCode);
            printf("Enter new status: \n");
            scanf(" %[^\n]", newStatus);
            // write the updated course info to the temporary file
            fprintf(tempFile, "%d, %s, %s\n", fieldId, newCourseCode, newStatus);
            found = 1;
        }
        else
        { // if the id not match, copy the line as it is to the temp file
            fputs(line, tempFile);
        }
    }
    fclose(file);     // close the file
    fclose(tempFile); // close the temp file
    if (!found)       // is the file is not found, delete the temp file and notify the user
    {
        printf("No course found with Id: %d\n", updateId);
        remove("temp.txt");
        return 1; // terminate uy indicate a problem
    }
    // replace the original file with the updated temp file
    remove("registration.txt");
    rename("temp.txt", "registration.txt");
    // confirm successful update
    printf("Course updated successfully!\n");
    return 0;
}
