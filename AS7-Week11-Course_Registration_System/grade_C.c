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
void addCourse(int id, char courseCode[], char status[]);
void displayCoursesInfo(struct Course student);
void printOption();
void searchCourses();

int main()
{
    struct Course student;
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
            printf("\nEnter your ID: ");
            scanf("%d", &student.id);
            printf("Enter your course code: ");
            scanf(" %[^\n]", student.courseCode);
            printf("Enter your status: ");
            scanf(" %[^\n]", student.status);
            addCourse(student.id, student.courseCode, student.status);
            break;
        case 2:
            displayCoursesInfo(student);
            break;
        case 3:
            searchCourses();
            break;
        }
    } while (userOption != 0);

    return 0;
}

void addCourse(int id, char courseCode[], char status[])
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
                return;
            }
        }
        fclose(file);
    }
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
void searchCourses()
{
    FILE *file = fopen("registration.txt", "r");
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
    }
    printf("-------------------------------------\n");
    fclose(file);
}

// create and write a file

// int getId(char line[]);
// int searchCourse(int id);

// int choice, tempId;

// FILE *file = fopen("registration.txt", "r");
// if (file != NULL)
// {
//     char line[100];
//     while (fgets(line, 100, file))
//     {
//         if (getId(line) == e.id)
//         {
//             printf("Error: the file already exist!");
//             return 1;
//         }
//     }
// }
// fclose(file);

// printf("%d", getId(line) * 100);
// int getId(char line[])
// {
//     char idStr[10];
//     int i = 0;
//     while (line[i] != "," && line[i] != '\0')
//     {
//         idStr[i] = line[i];
//         i++;
//     }
//     idStr[i] = '\0';
//     return atoi(idStr); // cast the string into an integer
// }
// int searchCourse(int id)
// {
//     FILE *file = fopen("registration.txt", "r");
//     char line[100];
//     while (fgets(line, 100, file))
//     {
//         if (getId(line) == id)
//         {
//             printf("* %s", line);
//             fclose(file);
//             return 0;
//         }
//     }
//     printf("Course not found!");
//     fclose(file);
//     return 1;
// }