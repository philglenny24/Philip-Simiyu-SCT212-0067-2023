#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct { 
char course_code[10]; 
char course_name[50]; 
} Course; 
typedef struct { 
int mark; 
char the_grade; 
} Grade; 
typedef struct Student { 
char reg_no[21]; 
char name[51]; 
int age; 
Course course; 
Grade grade; 
struct Student* next; 
} Student; 
typedef struct { 
int size; 
Student* head; 
} StudentList; 
StudentList create_empty_list() { 
    StudentList list; 
    list.size = 0; 
    list.head = NULL; 
    return list; 
} 
 
StudentList create_list_with_one(Student s) { 
    StudentList list = create_empty_list(); 
    Student* new_node = (Student*)malloc(sizeof(Student)); 
    *new_node = s; 
    new_node->next = NULL; 
    list.head = new_node; 
    list.size = 1; 
    return list; 
} 
 
StudentList copy_list(StudentList* src) { 
    StudentList copy = create_empty_list(); 
    Student* current = src->head; 
    while (current != NULL) { 
        Student* new_node = (Student*)malloc(sizeof(Student)); 
        *new_node = *current; 
        new_node->next = NULL; 
        add_student(&copy, *new_node); 
        current = current->next; 
    } 
    return copy; 
} 
 
void add_student(StudentList* list, Student s) { 
    Student* new_node = (Student*)malloc(sizeof(Student)); 
    *new_node = s; 
    new_node->next = NULL; 
 
    if (list->head == NULL) { 
        list->head = new_node; 
    } else { 
        Student* temp = list->head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = new_node; 
    } 
    list->size++; 
} 
 
void insert_student_at(StudentList* list, Student s, int pos) { 
    if (pos < 0 || pos > list->size) return; 
    Student* new_node = (Student*)malloc(sizeof(Student)); 
    *new_node = s; 
 
    if (pos == 0) { 
        new_node->next = list->head; 
        list->head = new_node; 
    } else { 
        Student* temp = list->head; 
        for (int i = 0; i < pos - 1; i++) { 
            temp = temp->next; 
        } 
        new_node->next = temp->next; 
        temp->next = new_node; 
    } 
    list->size++; 
} 
 
void remove_student(StudentList* list, Student s) { 
    Student* temp = list->head; 
    Student* prev = NULL; 
    while (temp != NULL) { 
        if (strcmp(temp->reg_no, s.reg_no) == 0) { 
            if (prev == NULL) { 
                list->head = temp->next; 
            } else { 
                prev->next = temp->next; 
            } 
            free(temp); 
            list->size--; 
            return; 
        } 
        prev = temp; 
        temp = temp->next; 
    } 
} 
 
void remove_student_at(StudentList* list, int pos) { 
    if (pos < 0 || pos >= list->size) return; 
    Student* temp = list->head; 
    Student* prev = NULL; 
    for (int i = 0; i < pos; i++) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (prev == NULL) { 
        list->head = temp->next; 
    } else { 
        prev->next = temp->next; 
    } 
    free(temp); 
    list->size--; 
} 
 
int get_size(StudentList* list) { 
    return list->size; 
} 
 
void destroy_list(StudentList* list) { 
    Student* current = list->head; 
    while (current != NULL) { 
        Student* to_delete = current; 
        current = current->next; 
        free(to_delete); 
    } 
    list->head = NULL; 
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
 
        set_marks(&s, 35 + i * 4); 
        calculate_grade(&s); 
 
        add_student(&list, s); 
    } 
 
    Student* current = list.head; 
    while (current != NULL) { 
        printf("%s - %s - Age: %d - Mark: %d - Grade: %c\n", 
            get_regNo(current), get_name(current), get_age(current), get_marks(current), 
get_grade(current).the_grade); 
current = current->next; 
} 
destroy_list(&list); 
return 0; 
} 
