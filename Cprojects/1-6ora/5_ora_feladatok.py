# def switch_num(a, b):
#     temp = a
#     a = b
#     b = temp
#     return (a, b)
#
#
# a, b = 6, 89
# a, b = switch_num(a, b)
# print(f"a={a} b={b}")
# a, b = b, a
#
# x = 897
# print(id(x))
# x += 1
# print(id(x))
#
# my_list = [1, 2, 3]
# print(id(my_list))
# my_list.append(8)
# print(id(my_list))
#
# my_list_2 = my_list
# print(id(my_list_2))

a, b = 5, 5
x, y = 5000, 5000
print(a is b)
print(x is y)


def mod_var(x):
    print("Inside, ", x, " id:", id(x))
    x = 42
    print("Inside, ", x, " id:", id(x))


def mod_list(list):
    print("Inside, ", list, " id:", id(list))
    list.append(100)
    print("Inside, ", list, " id:", id(list))
    list = [100, 101, 102]
    print("Inside, ", list, " id:", id(list))


my_list = [1, 2, 3]
my_var = 10

print("Before, ", my_var, " id:", id(my_var))
mod_var(my_var)
print("After, ", my_var, " id:", id(my_var))
print("========================================")
print("Before, ", my_list, " id:", id(my_list))
mod_list(my_list)
print("After, ", my_list, " id:", id(my_list))
