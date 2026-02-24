class Student:
    def __init__(self,name,roll,marks):
        self.name=name
        self.roll=roll
        self.marks=marks
    def display(self):
        print("Name: ",self.name)
        print("Roll: " ,self.roll)
        print("Marks: ",self.marks)
    def is_pass(self):
        if self.marks>=40:
            return "Pass"
        else:
            return "Fail"
ob1=Student("Hemant",2534,54)
ob2=Student("Bijaya",2543,40)
ob1.display()
print("Result:",ob1.is_pass())

print()