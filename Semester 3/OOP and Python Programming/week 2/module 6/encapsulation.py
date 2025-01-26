class Bank:
    def __init__(self, holder_name, initial_deposite) -> None:
        self.holder_name = holder_name #public attribute
        self._branch = 'bannai 11' # protected
        self.__balance = initial_deposite # private
    
    def deposite(self, amount):
        self.__balance += amount
    
    def get_balance(self):
        return self.__balance
    
    def withdraw(self, amount):
        if amount < self.__balance:
            self.__balance = self.__balance - amount
            return amount
        else:
            return f'Forkia taka nai' 

rafsun = Bank('Choooto bro', 10000)

print(rafsun.holder_name)
rafsun.holder_name = 'boro vai'
rafsun.deposite(40000)
print(rafsun.get_balance())
print(rafsun.holder_name)
# print(rafsun._branch)