print("Hány karakter fogsz beírni: ", end="")
num_of_chars = int(input())
chars = []

while len(chars) < num_of_chars:
    print("Karakter: ", end="")
    char = input()
    if '0' <= char <= '9' or 'a' <= char <= 'f' and len(char) == 1:
        chars.append(char)

hex_num = ''.join(chars)
print(f"{''.join(chars)} -> {int(''.join(chars), 16)}")

# decimal_value = 0
# for idx, val in enumerate(chars):
#     if '0' <= val <= '9':
#         decimal_value += 16 ** (len(chars) - 1 - idx) * (ord(val) - 48)
#     else:
#         decimal_value += 16 ** (len(chars) - 1 - idx) * (ord(val) - 87)
#
# print(f"{''.join(chars)} -> {decimal_value}")
