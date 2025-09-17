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
void addCourse();
void displayCoursesInfo();
void printOption();

int main()
{
    int userOption;

    welcome();
    do
    {

        printOption();
        printf("Please select an option: ");
        scanf("%d", &userOption);
        switch (userOption)
        {
        case 1:
            addCourse();
            break;
        case 2:
            displayCoursesInfo();
            break;
        }
    } while (userOption != 0);


    return 0;
}

void addCourse()
{
    struct Course student;

    printf("Enter your ID: ");
    scanf("%d", &student.id);
    printf("Enter your course code: ");
    scanf(" %[^\n]", student.courseCode);
    printf("Enter your status: ");
    scanf(" %[^\n]", student.status);

    FILE *file1 = fopen("registration.txt", "a");
    if (file1 == NULL)
    {
        printf("Error: File cannot be opened!\n");
        return;
    }
    fprintf(file1, "%d, %s, %s\n", student.id, student.courseCode, student.status);
    fclose(file1);
    printf("Course added successfully!\n\n");
}
void displayCoursesInfo()
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
    printf("3. Update existing courses.\n");
    printf("4. Delete courses.\n");
    printf("5. Save courses to a file and read from it for persistence.\n");
    printf("0. Exit\n");
}