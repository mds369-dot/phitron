def max_op(n, ar):
    option = 0

    while all(x % 2 == 0 for x in ar):
        ar = [x // 2 for x in ar]
        option += 1
    

    print(option)

n = int(input().strip())
ar = list(map(int, input().strip().split()))

max_op(n, ar)