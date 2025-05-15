#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_STUDENTS 100 
typedef struct { 
char course_code[10]; 
char course_name[50]; 
} Course; 
typedef struct { 
int mark; 
char the_grade; 
} Grade; 
typedef struct { 
char reg_no[21]; 
char name[51]; 
int age; 
Course course; 
Grade grade; 
} Student; 
typedef struct { 
int size; 
Student students[MAX_STUDENTS]; 
} StudentList; 
StudentList create_empty_list() { 
StudentList list; 
list.size = 0; 
return list; 
} 
StudentList create_list_with_one(Student s) { 
StudentList list; 
list.size = 1; 
list.students[0] = s; 
return list; 
} 
StudentList copy_list(StudentList* src) { 
StudentList copy; 
copy.size = src->size; 
for (int i = 0; i < src->size; i++) { 
copy.students[i] = src->students[i]; 
} 
return copy; 
} 
void add_student(StudentList* list, Student s) { 
if (list->size < MAX_STUDENTS) { 
list->students[list->size++] = s; 
} 
} 
void insert_student_at(StudentList* list, Student s, int pos) { 
    if (pos < 0 || pos > list->size || list->size >= MAX_STUDENTS) return; 
    for (int i = list->size; i > pos; i--) { 
        list->students[i] = list->students[i - 1]; 
    } 
    list->students[pos] = s; 
    list->size++; 
} 
 
void remove_student(StudentList* list, Student s) { 
    for (int i = 0; i < list->size; i++) { 
        if (strcmp(list->students[i].reg_no, s.reg_no) == 0) { 
            remove_student_at(list, i); 
            break; 
        } 
    } 
} 
 
void remove_student_at(StudentList* list, int pos) { 
    if (pos < 0 || pos >= list->size) return; 
    for (int i = pos; i < list->size - 1; i++) { 
        list->students[i] = list->students[i + 1]; 
    } 
    list->size--; 
} 
 
int get_size(StudentList* list) { 
    return list->size; 
} 
 
void destroy_list(StudentList* list) { 
list->size = 0; 
} 
void set_regNo(Student* s, const char* reg_no) { strncpy(s->reg_no, reg_no, 20); } 
char* get_regNo(Student* s) { return s->reg_no; } 
void set_name(Student* s, const char* name) { strncpy(s->name, name, 50); } 
char* get_name(Student* s) { return s->name; } 
void set_age(Student* s, int age) { s->age = age; } 
int get_age(Student* s) { return s->age; } 
void set_course(Student* s, Course c) { s->course = c; } 
Course get_course(Student* s) { return s->course; } 
void set_marks(Student* s, int mark) { s->grade.mark = mark; } 
int get_marks(Student* s) { return s->grade.mark; } 
void set_grade(Student* s, Grade g) { s->grade = g; } 
Grade get_grade(Student* s) { return s->grade; } 
void calculate_grade(Student* s) { 
int mark = s->grade.mark; 
char grade; 
if (mark > 69) grade = 'A'; 
else if (mark > 59) grade = 'B'; 
else if (mark > 49) grade = 'C'; 
else if (mark > 39) grade = 'D'; 
    else grade = 'E'; 
    s->grade.the_grade = grade; 
} 
 
//Driver Code  
 
int main() { 
    StudentList list = create_empty_list(); 
 
    for (int i = 0; i < 15; i++) { 
        Student s; 
        char reg[21]; 
        sprintf(reg, "S%03d", i + 1); 
        set_regNo(&s, reg); 
 
        char name[51]; 
        sprintf(name, "Student_%d", i + 1); 
        set_name(&s, name); 
 
        set_age(&s, 18 + (i % 5)); 
 
        Course c = {"C101", "Intro to Programming"}; 
        set_course(&s, c); 
 
        set_marks(&s, 35 + i*4); 
        calculate_grade(&s); 
 
        add_student(&list, s); 
    } 
for (int i = 0; i < get_size(&list); i++) { 
Student* s = &list.students[i]; 
printf("%s - %s - Age: %d - Mark: %d - Grade: %c\n", 
get_regNo(s), get_name(s), get_age(s), get_marks(s), get_grade(s).the_grade); 
} 
return 0; 
}
