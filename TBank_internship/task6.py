def min_time(procs, n):
    exec_time = [0 for i in range(n)]
    finish_time = [0 for i in range(n)]
    dependencies = [[] for i in range(n)]

    for i in range(n):
        data = procs[i].split()
        exec_time[i] = int(data[0])
        for dproc in list(map(int, data[1:])): 
            dependencies[dproc - 1].append(i)

    for i in range(n):
        finish_time[i] = exec_time[i]
        for dproc in dependencies[i]:
            finish_time[i] = max(finish_time[i], finish_time[dproc] + exec_time[i])

    return max(finish_time)

n = int(input())
print(min_time([input() for i in range(n)], n))

# 25
'''
5
10 2 3 5
5 4
0
4
15 3
'''

# 22
'''
6
2 2
2 3
15 4
1 5
2 6
0
'''