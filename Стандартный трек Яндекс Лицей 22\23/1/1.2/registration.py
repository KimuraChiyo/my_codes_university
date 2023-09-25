login = input()
email = input()
if '@' in login:
    print('Некорректный логин')
elif '@' not in email:
    print('Некорректный адрес')
else:
    print('OK')