string = input()
all_digits = {i: string.count(i) for i in string if i != ' '}
mx = max(all_digits.values())
need = [key for key in all_digits.keys() if all_digits[key] == mx]
print(*sorted(need))
