class BankAccount:
    def __init__(self, account_number, balance=0):
        self.account_number = account_number
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited {amount} into account {self.account_number}. New balance: {self.balance}")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            print(f"Withdrew {amount} from account {self.account_number}. New balance: {self.balance}")
        else:
            print(f"Not enough funds in account {self.account_number}. Current balance: {self.balance}")

account1 = BankAccount("123456", 1000)
account2 = BankAccount("789012", 500)

account1.deposit(500)
account1.withdraw(200)
account2.deposit(1000)
account2.withdraw(800)
