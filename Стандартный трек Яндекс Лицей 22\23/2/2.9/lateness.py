bus_schedule = {}

# process bus schedule
position = input()
while position != '':
    num = position[:position.index(' ')]

    time = position[position.index(' ') + 1:]
    hours = int(time[:time.index(':')])
    minutes = int(time[time.index(':') + 1:])
    absolute_time = hours * 60 + minutes
    
    if num in bus_schedule:
        bus_schedule[num].append(absolute_time)
    else:
        bus_schedule[num] = [absolute_time]
    position = input()

# process curr time
curr_time = input()
curr_hours = int(curr_time[:curr_time.index(':')])
curr_minutes = int(curr_time[curr_time.index(':') + 1:])
curr_time = curr_hours * 60 + curr_minutes

# process need buses
needful_buses = input().split()

# absolute times of all need voyages
need_voyages = []
for bus in needful_buses:
    need_voyages.extend(bus_schedule[bus])
need_voyages.sort()

# processing all need voyages
flag = None
for value in need_voyages:
    if value - curr_time >= 6:
        flag = value - curr_time - 6
        break
print(flag)
    
