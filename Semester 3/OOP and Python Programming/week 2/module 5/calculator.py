class Calculator:
    brand = 'Casio MS990'
    def add(self, num1, num2):
        total = f'Total is (+): {num1 + num2}'
        return total
    def deduct(self, num1, num2):
        total = f'Total is (-): {num1 - num2}'
        return total
    def multiply(self, num1, num2):
        total = f'Total is (*): {num1 * num2}'
        return total
    def divide(self, num1, num2):
        total = f'Total is (/): {num1 / num2}'
        return total

num_1 = int(input('Number 1: '))    
num_2 = int(input('Number 2: '))

cal = Calculator()

adding = cal.add(num_1, num_2)
deducting = cal.deduct(num_1, num_2)
multiplying = cal.multiply(num_1, num_2)
divideing = cal.divide(num_1, num_2)

print(adding)
print(deducting)
print(multiplying)
print(divideing)
