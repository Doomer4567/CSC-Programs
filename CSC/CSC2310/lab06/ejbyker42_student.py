import json

class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def get_attendance_rate(self, days_present, total_days):
        try:
            return int(days_present) / int(total_days)
        except ValueError:
            print("Error: Please enter a intger for days")
            return 0
        except ZeroDivisionError:
            print("Error: Total days can't be zero")
            return 0

class School:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def get_student_name(self, index):
        try:
            return self.students[index].name
        except IndexError:
            print("Error: Student index out of range")
            return None
    def get_student_age(self, index):
        try:
            return self.students[index].age
        except IndexError:
            print("Error: Student index out of range")
            return None

def main():
    school = School()

    try:
        with open('students.json') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("Error: Not found in file")
        return
    for x in data:
        school.add_student(Student(x['Name'], x['Age']))

    while True:
        try:
            index = int(input("Enter the index of the student: "))
            name = school.get_student_name(index)
            age = school.get_student_age(index)
            #This code below checks if both name and age are no not none 
            if name is not None and age is not None:
                print(name, age, '\n')
                total_days = input('How many days has school been in session this year? ')
                days_present = input('How many days has the student attended school this year?')
                print(name, "'s attendence rate is", school.students[index].get_attendance_rate(days_present, total_days))
        except ValueError:
            print("Error: Please enter a intger for index")
        except KeyboardInterrupt:
            return

if __name__ == "__main__":
    main()
