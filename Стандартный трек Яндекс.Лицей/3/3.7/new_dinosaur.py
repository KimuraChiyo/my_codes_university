dinosaurs = filter(lambda x: len(x) in [2, 3], map(str.upper, input().split()))
dino_dct = {}
for name in dinosaurs:
    dino_dct[name] = dino_dct.get(name, 0) + 1
print(dino_dct)
