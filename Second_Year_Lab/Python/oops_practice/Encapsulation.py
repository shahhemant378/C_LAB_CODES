class BankAccount:
    def __init__(self,balance):
        self.__balance=balance
    
    def deposit(self,amount):
        self.__balance+=amount
    
    def withdraw(self,amount):
        if(self.__balance-amount >0):
            self.__balance-=amount
        else:
            print("You doesnot have enough balance")
    
    def getBalance(self):
        return self.__balance
    
acc=BankAccount(1000)


acc.deposit(500)
acc.withdraw(200)
print("Balance : ",acc.getBalance())

