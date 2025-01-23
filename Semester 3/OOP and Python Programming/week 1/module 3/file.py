# .csv comma separated value
# .txt text file

# with open('messatge.txt', 'w') as file:
#     file.write('I love you, Python!')

# with open('messatge.txt', 'a') as file:
#     file.write('I love you, Python!')

with open('messatge.txt', 'r') as file:
    text = file.read()
    print(text)