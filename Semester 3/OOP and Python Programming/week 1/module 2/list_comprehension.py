numbers = [45, 87, 96, 65, 43, 85, 14, 26, 61, 70]

odd = []

for num in numbers:
    if num % 2 == 1 and num % 5 == 0:
        odd.append(num)


print(odd)

# odd_num = [num for num in numbers if num % 2 == 1 and num % 5 == 0]
odd_num = [num for num in numbers if num % 2 == 1 and num % 5 == 0]

print(odd_num)

players = ['sakib', 'musfik', 'mustafiz']
ages = [38, 38, 32]

age_comb = []
for player in players:
    print('player: ', player)
    for age in ages:
        print(player, age)
        age_comb.append([player, age])

print(age_comb)
