import pandas as pd

adresses = open('addresses.txt', 'r').readlines()
peoples = open('people.txt', 'r').readlines()

ids = []
names = []
ages = []
citys = []
streets = []
houses = []
for i in range(1, len(adresses)):
    array_person = peoples[i][:-1].split(',')
    array_address = adresses[i][:-1].split(',')
    ids.append(int(array_person[0]))
    names.append(array_person[1])
    ages.append(int(array_person[2]))
    citys.append(array_address[1])
    streets.append(array_address[2])
    houses.append(int(array_address[3]))
dict = {
    'id': ids,
    'name': names,
    'возраст': ages,
    'город': citys,
    'улица': streets,
    'дом': houses
}
persons = pd.DataFrame(dict)

city_avg = persons.groupby('город').agg({'возраст': 'mean'})
street_avg = persons.groupby('улица').agg({'возраст': 'mean'})
house_avg = persons.groupby('дом').agg({'возраст': 'mean'})
print(city_avg)
print(street_avg)
print(house_avg)