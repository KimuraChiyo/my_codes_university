count = int(input())
percent = float(input())
years = float(input())

while years >= 1:
    count = count * (1 + percent / 100)
    years -= 1

if years:
    count += (count * years) * 0.01

print(count)