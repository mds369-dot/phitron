"""
int/void name/main(){
    return 0
}

"""
# define

def double_it(num):
    result = num * 2
    print(result)
    return result


double_it(8)
double_it(88)

def sum(num1, num2):
    result = num1 + num2
    return result


total = sum(44, 39)
print(total)

final = double_it(total)
print('final value', final)