class Employee:
    company="TechCorp"
    def __init__(self,name,salary):
        self.name=name
        self.salary=salary
    def display(self):
        print("Name: ",self.name)
        print("Salary: ",self.salary)
        print("Company: ",self.company)
emp1=Employee("Swikar",60000)
emp2=Employee("Anwar",45000)

emp1.company="Google"
emp1.display()
print()
emp2.display()
