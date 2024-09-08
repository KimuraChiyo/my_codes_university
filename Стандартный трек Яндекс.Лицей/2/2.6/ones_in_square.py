n = input()
print(', '.join([str(int(i * '1') ** 2) for i in range(1,
                                                       (len(n) 
                                                        if int(n) % 10 >= 1 
                                                        else len(n) - 1) + 1)]))
