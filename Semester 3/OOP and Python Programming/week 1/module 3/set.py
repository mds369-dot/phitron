# list --> []
# tuple --> ()
# set --> {}
# set: unique items collection. No duplicate
number = [12, 56, 98, 78, 56, 12, 6, 8]
print(number)
number_set = set(number)
print(number_set)
number_set.add(55)
print(number_set)
# number_set[1] = 5
number_set.remove(6)
print(number_set)

for item in number_set:
    print(item)

if 9 in number_set:
    print('9 exists')
elif 98 in number_set:
    print('98 exists')

A = {1, 3, 5}
B = {1, 2, 3, 4, 5}

print(A & B)
print(A | B) #A U B
