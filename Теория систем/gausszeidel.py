import math
from numpy import array, zeros, diag, diagflat, dot

def gauss(par_arr, eq_arr):
    for k in range(0, len(eq_arr) - 1):
        for i in range(k + 1, len(eq_arr)):
            c = par_arr[i][k] / par_arr[k][k]
            for j in range(k, len(eq_arr)):
                par_arr[i][j] = par_arr[i][j] - c * par_arr[k][j]
            eq_arr[i] = eq_arr[i] - c * eq_arr[k]

    x = [0] * (len(par_arr) - 1) + [eq_arr[len(eq_arr) - 1] / par_arr[len(par_arr) - 1][len(par_arr) - 1]]
    for i in range(len(x) - 2, -1, -1):
        c = 0
        for j in range(i + 1, len(x)):
            c = c + par_arr[i][j] * x[i]
        x[i] = (eq_arr[i] - c) / par_arr[i][i]
    return x

def zeidel(par_arr, eq_arr):
    x = [0] * len(eq_arr)
    for i in range(1):
        for j in range(len(eq_arr)):
            c = eq_arr[j]
            for i in range(len(eq_arr)):
                if (i != j):
                    c -= par_arr[j][i] * x[i]
            x[j] = c / par_arr[j][j]
    return x

def jacobi(par_arr, eq_arr, max_iterations=100):
    x = [0] * len(eq_arr)
    D = diag(par_arr)
    R = par_arr - diagflat(D)
    for i in range(max_iterations):
        x = (eq_arr - dot(R, x)) / D
    return x

a = [[4.503, 0.219, 0.527, 0.396],
     [0.259, 5.121, 0.423, 0.206],
     [0.413, 0.531, 4.317, 0.264],
     [0.327, 0.412, 0.203, 4.851]]
b = [0.553, 0.358, 0.565, 0.536]
print('Гаусс: ', *[round(i, 2) for i in gauss(a, b)])

a = [[4.503, 0.219, 0.527, 0.396],
     [0.259, 5.121, 0.423, 0.206],
     [0.413, 0.531, 4.317, 0.264],
     [0.327, 0.412, 0.203, 4.851]]
b = [0.553, 0.358, 0.565, 0.536]
print('Зейдель: ', *[round(i, 2) for i in zeidel(a, b)])

a = [[4.503, 0.219, 0.527, 0.396],
     [0.259, 5.121, 0.423, 0.206],
     [0.413, 0.531, 4.317, 0.264],
     [0.327, 0.412, 0.203, 4.851]]
b = [0.553, 0.358, 0.565, 0.536]
print('Якоби: ', *[round(i, 2) for i in jacobi(array(a), array(b))])