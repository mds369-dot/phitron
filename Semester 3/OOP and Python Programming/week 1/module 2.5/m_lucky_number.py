inputs = input()
a = int(inputs[:inputs.find(' ')])
b = int(inputs[inputs.find(' ') + 1:])

lucky_number = []

for num in range(a, b+1):
    is_lucky = True
    for digit in str(num):
        if digit != '4' and digit != '7':
            is_lucky = False
            break
    if is_lucky:
        lucky_number.append(num)

if lucky_number:
    print(*lucky_number)
else:
    print(-1)