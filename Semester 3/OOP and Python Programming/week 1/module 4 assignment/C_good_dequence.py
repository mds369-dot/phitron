# def good_seq(n, a):
#     freq = {}
#     for num in a:
#         if num in freq:
#             freq[num] += 1
#         else:
#             freq[num] = 1
    
#     remove = 0
#     for num, count in freq.items():
#         if count > num:
#             remove += count - num
#         else:
#             remove += count
        
    
#     print(remove)

# n = int(input().split())
# a = list(map(int, input().strip().split()))

# good_seq(n, a)

from collections import Counter

def good_seq(n, a):
    freq = Counter(a)
    removals = 0

    for x, count in freq.items():
        if count > x:
            removals += count - x  
        else:
            removals += count
    print(removals)

n = int(input().strip())
a = list(map(int, input().strip().split()))
good_seq(n, a)
