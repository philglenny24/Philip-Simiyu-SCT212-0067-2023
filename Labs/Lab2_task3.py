class Course: 
    def __init__(self, code="", name=""): 
        self.course_code = code 
        self.course_name = name 
 
class Grade: 
    def __init__(self, mark=-1): 
        self.mark = mark 
        self.the_grade = 'N' 
 
class Student: 
    def __init__(self): 
        self.reg_no = "" 
        self.name = "" 
        self.age = 0 
        self.course = Course() 
        self.grade = Grade() 
        self.next = None 
 
    def set_reg_no(self, reg): 
        self.reg_no = reg 
 
    def get_reg_no(self): 
        return self.reg_no 
 
    def set_name(self, name): 
        self.name = name 
 
    def get_name(self): 
        return self.name 
 
    def set_age(self, age): 
        self.age = age 
 
    def get_age(self): 
        return self.age 
 
    def set_course(self, course): 
        self.course = course 
 
    def get_course(self): 
        return self.course 
 
    def set_marks(self, mark): 
        self.grade.mark = mark 
 
    def get_marks(self): 
        return self.grade.mark 
 
    def set_grade(self, grade): 
        self.grade = grade 
 
    def get_grade(self): 
        return self.grade 
 
    def calculate_grade(self): 
        mark = self.grade.mark 
        if mark > 69: 
            self.grade.the_grade = 'A' 
        elif mark > 59: 
            self.grade.the_grade = 'B' 
        elif mark > 49: 
            self.grade.the_grade = 'C' 
        elif mark > 39: 
            self.grade.the_grade = 'D' 
        else: 
            self.grade.the_grade = 'E' 
 
class StudentList: 
    def __init__(self): 
        self.head = None 
        self.size = 0 
 
    def add_student(self, student): 
        if not self.head: 
            self.head = student 
        else: 
            current = self.head 
            while current.next: 
                current = current.next 
            current.next = student 
        self.size += 1 
 
    def insert_student_at(self, student, position): 
        if position < 0 or position > self.size: 
            return 
        if position == 0: 
            student.next = self.head 
            self.head = student 
        else: 
            prev = self.head 
            for _ in range(position - 1): 
                prev = prev.next 
            student.next = prev.next 
            prev.next = student 
        self.size += 1 
 
    def remove_student(self, target): 
        prev = None 
        current = self.head 
        while current: 
            if current.reg_no == target.reg_no: 
                if prev: 
                    prev.next = current.next 
                else: 
                    self.head = current.next 
                self.size -= 1 
                return 
            prev = current 
            current = current.next 
 
    def remove_student_at(self, position): 
        if position < 0 or position >= self.size: 
            return 
        prev = None 
        current = self.head 
        for _ in range(position): 
            prev = current 
            current = current.next 
        if prev: 
            prev.next = current.next 
        else: 
            self.head = current.next 
        self.size -= 1 
 
    def get_size(self): 
        return self.size 
 
    def destroy_list(self): 
        self.head = None 
        self.size = 0 
 
# --------- Driver Code --------- 
if __name__ == "__main__": 
    slist = StudentList() 
 
    for i in range(15): 
        s = Student() 
        s.set_reg_no(f"S{str(i+1).zfill(3)}") 
        s.set_name(f"Student_{i+1}") 
        s.set_age(18 + i % 5) 
        s.set_course(Course("C101", "Intro to Programming")) 
        s.set_marks(35 + i * 4) 
        s.calculate_grade() 
        slist.add_student(s) 
current = slist.head 
while current: 
print(f"{current.get_reg_no()} - {current 
