n = int(input())
m = int(input())
for i in range(m // 25 + 1):
    for j in range((m - i * 25) // 10 + 1):
        if i + j > n or i * 25 + j * 10 > m:
            break
        for k in range(((m - i * 25) - j * 10) // 7 + 1):
            if i + j + k > n or i * 25 + j * 10 + 7 * k > m:
                break
            if i * 25 + j * 10 + k * 7 == m and i + j + k == n:
                print(i, j, k)