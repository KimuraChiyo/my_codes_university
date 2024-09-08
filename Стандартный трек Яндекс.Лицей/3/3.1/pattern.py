def template(a, b, c):
    if a + b > c and a + c > b and b + c > a:
        print(f"Периметр: {a + b + c}")
        p = (a + b + c) / 2
        print(f"Площадь: {(p * (p - a) * (p - b) * (p - c)) ** 0.5}")
        print(f'Равнобедренный: {"да" if a == b or b == c or c == a else "нет"}')
        print(f'Равносторонний: {"да" if (a + b + c) // 3 == a else "нет"}')
    else:
        print(None)

# template(5, 4, 5)