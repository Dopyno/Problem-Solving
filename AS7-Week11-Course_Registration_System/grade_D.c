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

// create and write a file
void addCourse();
void displayCourseInfo();
int getId(char line[]);
int searchCourse(int id);

int main()
{
    struct Course student;

    FILE *file = fopen("registration.txt", "w");
    printf("Enter your ID: ");
    scanf("%d", &student.id);
    printf("Enter your course code: ");
    scanf(" %[^\n]", student.courseCode);
    printf("Enter your status: ");
    scanf(" %[^\n]", student.status);

    addCourse();
    displayCourseInfo();
    return 0;
}

void addCourse(struct Course e)
{
    FILE *file = fopen("registration.txt", "r");
    char line[100];
    while (fgets(line, 100, file))
    {
        if (getId(line) == e.id)
        {
            printf("Error: the file already exist!");
            return 1;
        }
    }
    fclose(file);

    FILE *file1 = fopen("registration.txt", "a");
    fprintf(file1, "%d, %s, %s\n", e.id, e.courseCode, e.status);
    fclose(file1);
}
void displayCourseInfo()
{
    int choice, tempId;
    FILE *file = fopen("registration.txt", "r");
    char line[100];
    printf("=======    Student Courses ========\n");
    while (fgets(line, 100, file))
    {
        printf("* %s", line);
        printf("%d", getId(line) * 100);
    }
    printf("===================================\n");
    fclose(file);
}
int getId(char line[])
{
    char idStr[10];
    int i = 0;
    while (line[i] != "," && line[i] != '\0')
    {
        idStr[i] = line[i];
        i++;
    }
    idStr[i] = '\0';
    return atoi(idStr); // cast the string into an integer
}
int searchCourse(int id)
{
    FILE *file = fopen("registration.txt", "r");
    char line[100];
    while (fgets(line, 100, file))
    {
        if (getId(line) == id)
        {
            printf("* %s", line);
            fclose(file);
            return 0;
        }
    }
    printf("Course not found!");
    fclose(file);
    return 1;
}