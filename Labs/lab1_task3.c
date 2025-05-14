#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Course {
string course_code;
string course_name;
};
struct Grade {
int mark = -1;
char the_grade = 'N'; // N for Not assigned
bool is_finalized = false;
};
struct Student {
string reg_no;
string name;
int age;
Course course;
Grade grade;
};
vector<Student> students;
char calculate_grade(int mark) {
if (mark > 69) return 'A';
else if (mark > 59) return 'B';
else if (mark > 49) return 'C';
else if (mark > 39) return 'D';
else return 'E';
}
void add_student() {
if (students.size() >= 40) {
cout << "Maximum number of students reached." << endl;
return;
}
Student s;
cout << "Enter registration number: ";
cin >> s.reg_no;
cin.ignore();
cout << "Enter name: ";
getline(cin, s.name);
cout << "Enter age: ";
cin >> s.age;
cin.ignore();
cout << "Enter course code: ";
cin >> s.course.course_code;
cin.ignore();
cout << "Enter course name: ";
getline(cin, s.course.course_name);
students.push_back(s);
cout << "Student added successfully." << endl;
}

void edit_student() {
    string reg_no;
    cout << "Enter registration number of the student to edit: ";
    cin >> reg_no;
    cin.ignore();

    for (auto& s : students) {
        if (s.reg_no == reg_no) {
            cout << "Editing details for " << s.name << endl;
            cout << "Enter new name: ";
            getline(cin, s.name);
            cout << "Enter new age: ";
            cin >> s.age;
            cin.ignore();
            cout << "Enter new course code: ";
            cin >> s.course.course_code;
            cin.ignore();
            cout << "Enter new course name: ";
            getline(cin, s.course.course_name);
            cout << "Details updated successfully." << endl;
            return;
        }
    }
    cout << "Student with registration number " << reg_no << " not found." << endl;
}

void add_mark() {
    string reg_no;
    cout << "Enter registration number of the student to add mark: ";
    cin >> reg_no;

    for (auto& s : students) {
        if (s.reg_no == reg_no) {
            if (s.grade.is_finalized) {
                cout << "Grade already finalized. Cannot modify." << endl;
                return;
            }
            int mark;
            cout << "Enter mark (0-100): ";
            cin >> mark;
            if (mark < 0 || mark > 100) {
                cout << "Invalid mark. Must be between 0 and 100." << endl;
                return;
            }
            s.grade.mark = mark;
            s.grade.the_grade = calculate_grade(mark);
            s.grade.is_finalized = true;
            cout << "Mark and grade added successfully." << endl;
            return;
        }
    }
    cout << "Student with registration number " << reg_no << " not found." << endl;
}

void display_students() {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        Student& s = students[i];
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Registration Number: " << s.reg_no << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course Code: " << s.course.course_code << endl;
        cout << "Course Name: " << s.course.course_name << endl;
        if (s.grade.mark != -1) {
            cout << "Mark: " << s.grade.mark << endl;
            cout << "Grade: " << s.grade.the_grade << endl;
        } else {
            cout << "Mark: Not assigned\n";
            cout << "Grade: Not assigned\n";
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3;
::contentReference[oaicite:0]{index=0};

