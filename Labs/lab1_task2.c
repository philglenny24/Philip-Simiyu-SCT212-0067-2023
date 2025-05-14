#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 40
typedef struct {
char course_code[10];
char course_name[50];
} Course;
typedef struct {
int mark;
char the_grade;
int is_finalized; // 0 = not finalized, 1 = finalized
} Grade;
typedef struct {
char reg_no[21]; // 20 chars + null terminator
char name[51];   // 50 chars + null terminator
int age;
Course course;
Grade grade;
} Student;
Student students[MAX_STUDENTS];
int student_count = 0;
char calculate_grade(int mark) {
if (mark > 69) return 'A';
else if (mark > 59) return 'B';
else if (mark > 49) return 'C';
else if (mark > 39) return 'D';
else return 'E';
}
void add_student() {
if (student_count >= MAX_STUDENTS) {
printf("Maximum number of students reached.\n");
return;
}
Student s;
printf("Enter registration number: ");
scanf("%20s", s.reg_no);
printf("Enter name: ");
scanf(" %50[^\n]", s.name); // Read until newline
printf("Enter age: ");
scanf("%d", &s.age);
printf("Enter course code: ");
scanf("%9s", s.course.course_code);
printf("Enter course name: ");
scanf(" %49[^\n]", s.course.course_name);
s.grade.mark = -1; // Indicates no mark yet
s.grade.the_grade = 'N'; // N for Not assigned
s.grade.is_finalized = 0;
students[student_count++] = s;
    printf("Student added successfully.\n");
}

void edit_student() {
    char reg_no[21];
    printf("Enter registration number of the student to edit: ");
    scanf("%20s", reg_no);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            printf("Editing details for %s\n", students[i].name);
            printf("Enter new name: ");
            scanf(" %50[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new course code: ");
            scanf("%9s", students[i].course.course_code);
            printf("Enter new course name: ");
            scanf(" %49[^\n]", students[i].course.course_name);
            printf("Details updated successfully.\n");
            return;
        }
    }
    printf("Student with registration number %s not found.\n", reg_no);
}

void add_mark() {
    char reg_no[21];
    printf("Enter registration number of the student to add mark: ");
    scanf("%20s", reg_no);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            if (students[i].grade.is_finalized) {
                printf("Grade already finalized. Cannot modify.\n");
                return;
            }
            int mark;
            printf("Enter mark (0-100): ");
            scanf("%d", &mark);
            if (mark < 0 || mark > 100) {
                printf("Invalid mark. Must be between 0 and 100.\n");
                return;
            }
            students[i].grade.mark = mark;
            students[i].grade.the_grade = calculate_grade(mark);
            students[i].grade.is_finalized = 1;
            printf("Mark and grade added successfully.\n");
            return;
        }
    }
    printf("Student with registration number %s not found.\n", reg_no);
}

void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        Student s = students[i];
        printf("\nStudent %d:\n", i + 1);
        printf("Registration Number: %s\n", s.reg_no);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Course Code: %s\n", s.course.course_code);
        printf("Course Name: %s\n", s.course.course_name);
        if (s.grade.mark != -1) {
            printf("Mark: %d\n", s.grade.mark);
            printf("Grade: %c\n", s.grade.the_grade);
        } else {
            printf("Mark: Not assigned\n");
            printf("Grade: Not assigned\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Add Mark and Calculate Grade\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                edit_student();
                break;
            case 3:
                add_mark();
                break;
            case 4:
                display_students();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

