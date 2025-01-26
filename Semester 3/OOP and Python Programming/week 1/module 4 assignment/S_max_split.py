def split(s):
    balance = 0
    max_balanced = 0
    current_string = ""
    results = []

    for char in s:
        current_string += char
        balance += 1 if char == 'L' else -1

        if balance == 0:
            max_balanced += 1
            results.append(current_string)
            current_string = ""

    print(max_balanced)
    print("\n".join(results))
s = input().strip()
split(s)
