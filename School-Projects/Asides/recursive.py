# This is recursively called function
# If you have a number greater than 10, the value returned will be number - 10
# If you have a number less than 10, the function will recursively call itself and increment the value till it reaches 11
# It returns the number 1 for numbers <= 10

def fun(num):
    if num > 10:
        return num - 10
    return fun(fun(num + 11))
number = int(input("Enter a number : "))
print(fun(number))