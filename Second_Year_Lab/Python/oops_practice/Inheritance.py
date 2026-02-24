class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    
    def introduce(self):
        print("Hi,I am",self.name,"and I am",self.age,"years old.")
class Teacher(Person):
    def __init__(self, name, age,subject):
        super().__init__(name, age)
        self.subject=subject
    
    def teach(self):
        print("Teaching subject ",self.subject)

ob1=Teacher("Hemant",20,"CS")
ob1.introduce()
ob1.teach()