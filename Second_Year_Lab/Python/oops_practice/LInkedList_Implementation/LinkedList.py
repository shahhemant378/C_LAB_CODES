class Node:
    def __init__(self,x):
        self.x=x
        self.next=None



class LinkedList:
    def __init__(self):
        self.head=None

    #Add at end
    def add(self,data):
        newNode=Node(data)

        if self.head is None:
            self.head=newNode
            return
        
        temp=self.head
        while temp.next:
            temp=temp.next
        temp.next=newNode