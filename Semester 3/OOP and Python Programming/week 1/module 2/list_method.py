numbers = [71, 12, 45, 98, 68]
numbers.append(56)
numbers.append(71)

print(numbers)

# numbers.insert(0, 71)
numbers.insert(2, 81)
print(numbers)
if 98 in numbers:
    numbers.remove(98)
# numbers.remove(98)
print(numbers)

list = numbers.pop()
print(list, numbers)

index = numbers.index(71)
print(index)

sorted = numbers.sort()
print(sorted)

numbers.reverse()
print(numbers)

