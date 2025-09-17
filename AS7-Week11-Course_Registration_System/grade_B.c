#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the struct with 3 elements id, course code and status
struct Course
{
    int id;
    char courseCode[20];
    char status[10];
};

void welcome();
int addCourse(int id, char courseCode[], char status[]);
void displayCoursesInfo(struct Course student);
void printOption();
int searchCourses();
int updateCourse();

int main()
{
    struct Course student;
    int userOption, result, update, search;

    welcome();
    do
    {
        printOption();
        printf("Please select an option: ");
        scanf("%d", &userOption);
        switch (userOption)
        {
        case 1:
            printf("\nEnter your ID: ");
            scanf("%d", &student.id);
            printf("Enter your course code: ");
            scanf(" %[^\n]", student.courseCode);
            printf("Enter your status: ");
            scanf(" %[^\n]", student.status);
            result = addCourse(student.id, student.courseCode, student.status); // the function will return the status 0 or 1
            if (result == 0)
                printf("Course added to file!\n");
            else
                printf("Course was not added!.\n");
            break;
        case 2:
            displayCoursesInfo(student);
            break;
        case 3:
            search = searchCourses(); // the function will return the status 0 or 1
            if (search == 0)
                printf("Course found!\n");
            else
                printf("Course was not found!\n");
            break;
        case 4:
            update = updateCourse();
            if (update == 0)
                printf("Course update complete!\n");
            else
                printf("Course update failed!\n");
            break;
        }
    } while (userOption != 0);

    return 0;
}

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
void displayCoursesInfo(struct Course student)
{
    FILE *file = fopen("registration.txt", "r");
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n");
        return;
    }
    char line[100];
    printf("\n=======    Student Courses ========\n");
    while (fgets(line, 100, file))
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
void printOption()
{
    printf("\n1. Add a course (ID, Course Code, Status).\n");
    printf("2. Display all courses.\n");
    printf("3. Search courses.\n");
    printf("4. Update existing courses.\n");
    printf("5. Delete courses.\n");
    printf("6. Save courses to a file and read from it for persistence.\n");
    printf("0. Exit\n");
}
int searchCourses()
{
    FILE *file = fopen("registration.txt", "r");
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
    while (fgets(line, 100, file))
    {
        sscanf(line, "%d", &fileId);
        if (fileId == searchId)
        {
            printf("Course info:  %s", line);
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
    fclose(file);
    return 0; // the course is found and the program end successfully
}
int updateCourse()
{
    FILE *file = fopen("registration.txt", "r");
    if (file == NULL)
    {
        printf("Error: No Course registration found!\n");
        return 1; // problem by not finding the file
    }
    int updateId;
    printf("Enter the course ID to update: ");
    scanf("%d", &updateId);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error: Could not create the temporary file!\n");
        fclose(file);
        return 1;
    }

    char line[100];
    int fieldId;
    int found = 0;
    while (fgets(line, 100, file))
    {

        if (sscanf(line, "%d,", &fieldId) == 1 && fieldId == updateId)
        {
            char newCourseCode[20], newStatus[10];
            printf("Please enter the new course code: \n");
            scanf(" %[^\n]", newCourseCode);
            printf("Enter new status: \n");
            scanf(" %[^\n]", newStatus);

            fprintf(tempFile, "%d, %s, %s\n", fieldId, newCourseCode, newStatus);
            found = 1;
        }
        else
        {
            fputs(line, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (!found)
    {
        printf("No course found with Id: %d\n", updateId);
        remove("temp.txt");
        return 1;
    }

    remove("registration.txt");
    rename("temp.txt", "registration.txt");

    printf("Course updated successfully!\n");
    return 0;
}
