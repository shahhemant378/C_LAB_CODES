class Queue:
    def __init__(self):
        self.q=[]
    
    def push(self,ele):
        self.q.append(ele)
    
    def pop(self):
        if self.isEmpty():
            print("Queue is Empty")
        else:
            return self.q.pop(0)
    
    def isEmpty(self):
        if(len(self.q)==0):
            return True
        else:
            return False
        
    def display(self):
        for i in self.q:
            print(i)
        
q1=Queue()
q1.push(1)
q1.push(2)
q1.pop()
q1.pop()
q1.pop()

q1.display()


