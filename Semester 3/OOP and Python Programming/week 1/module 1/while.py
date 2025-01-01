#break, continue
num = 1

# while num <= 10:
#     print(num)
#     num = num + 1
#     if num == 5:
#         break

# while num <= 10:
#     if num == 5:
#         continue
#     print(num)
#     num = num + 1


while num <= 10:
    num = num + 1
    if num % 2 == 1:
        continue
    print(num)
    