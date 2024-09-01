from sys import set_int_max_str_digits

set_int_max_str_digits(5_000_000)

a = int(input())
b = int(input())
print(a*b)