def full_name(first, last):
    name = f'Full Name is: {first} {last}'
    return name

# take parameters in order(serial wise)
# name = full_name('Alu', 'kodu')
name = full_name(last='kodu', first='alu')
print(name)

# def famous(**kargs)
def famous_nam(first, last, **addition):
    name = f'{first} {last}'
    # print(addition['title'])
    for key, value in addition.items():
        print(key, value)
    return name

name = famous_nam(first='Taher', last='Ali', title='Hujur', tital2='',addition='Shayokh')

print(name)

# def function_name(num1, num2, *args, **kargs)

# retun muliple things from an array
def a_lot(num1, num2):
    sum = num1 + num2
    mult = num1 * num2
    remain = num1 - num2
    # return [sum, mult, remain]
    return sum, mult, remain

everything = a_lot(55, 21)

print(everything)