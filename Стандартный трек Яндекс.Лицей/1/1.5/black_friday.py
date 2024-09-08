discount = int(input())

if discount == 0:
    discount = 50
elif discount <= 30:
    discount = int(1.5 * discount)
elif discount <= 70:
    discount = int(1.1 * discount)

print(discount)