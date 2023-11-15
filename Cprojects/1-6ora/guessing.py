import random
num = 6
if num > 5:
    print("Hello World")

rand = random.randint(0, 100)
print("Adj meg egy tippet ", end="")
input_num = int(input())
hibak_szama = 0

while input_num != rand:
    if input_num > rand:
        print("A tipped túl nagy")
    else:
        print("A tipped túl kicsi")
    hibak_szama += 1
    print("Adj meg egy tippet ", end="")
    input_num = int(input())

print("Kitaláltad!")
print(f"{hibak_szama} hibával")

if 5 < 6 < 9:
    print("Az operator chaining működik")
# def get_target():
#     return random.randint(0, 100)
