list = [1, 2, ["ASD", "nested"]]
tuple = ("apple", )

meret = 20
toltendo = []
for i in range(meret):
    toltendo.append(0)

print(toltendo)
tolt2 = [0] * 20
print(tolt2)

lista3 = [i**2 for i in range(10)]
sum = 0
max = lista3[0]
min = lista3[0]
for i in lista3:
    if i > max:
        max = i
    if i < min:
        min = i
    sum += i

min_diff = 0
second_min = 0
for num in lista3:
    if min_diff == 0 and num != min:
        min_diff = num - min
        second_min = num
    if num != min and num - min < min_diff:
        second_min = num
print(sum)
print(max)
print(second_min)

names = {"Robin", "Galahad", "Lancelot", "Lancelot"}
for name in names:
    print(name)
questions = ['neved', 'küldetésed', 'kedvenc színed']
answers = ['Sir Lancelot', 'A szent kehely', 'Kék']

for q, a in zip(questions, answers):
    print(f"Q: Mi a {q}?")
    print(f"A: {a}")
