# global variable
balance = 3000

def buy_thing(items, price):
    # local scope variable
    # you can access global variable without using the global keyword
    dream_phone = 'xphone'
    # if you wnat to modify a global variable, you have to use the global keyword
    global balance
    # balance = 600
    print(f'previous balance value', balance)
    balance = balance - price
    print( f'balance after buying {items}', balance)

# print(dream_phone)
buy_thing('sunglass', 1000)
print('global balance after buy', balance)