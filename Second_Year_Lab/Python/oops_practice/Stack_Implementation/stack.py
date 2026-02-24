class Node:
    def __init__(self,age,name):
        self.age=age
        self.name=name

class Stack:
    def __init__(self):
        self.s=[]

    def push(self,Node):
        self.s.append(Node)
    
    def pop(self):
        if not self.isEmpty():
            return self.s.pop()
        else:
            print("Stack is empty")

    def isEmpty(self):
        if len(self.s)==0:
            return True
        else:
            return False
        
    def display(self):
        for i in self.s:
            print("Name: ",i.name)
            print("Age: ",i.age)

s1=Stack()
n1=Node(19,"Hemant")
n2=Node(20,"Bijaya")
n3=Node(30,"Swikar")
s1.push(n1)
s1.push(n2)
s1.push(n3)

s1.display()

