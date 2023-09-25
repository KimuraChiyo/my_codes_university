inputs = input().split()
print(', '.join(list(filter(lambda x: len(set(x.lower()) & set(inputs[1].lower())) >= 6, inputs))))
