num = input()

reversed_num = num[::-1]

reversed_num_no_leading_zero = ""
leading_zero = True
for char in reversed_num:
    if leading_zero and char == '0':
        continue
    leading_zero = False
    reversed_num_no_leading_zero += char

if num == num[::-1]:
    print(reversed_num_no_leading_zero)
    print('YES')
else:
    print(reversed_num_no_leading_zero)
    print('NO')