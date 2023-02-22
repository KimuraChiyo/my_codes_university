from random import choice

def qsort(arr):
    if len(arr) < 2:
        return arr
    else:
        supp_elem = choice(arr)
        less_arr = [i for i in arr[:len(arr)//2] + arr[len(arr)//2+1:] if i < supp_elem]
        greater_arr = [i for i in arr[:len(arr)//2] + arr[len(arr)//2+1:] if i >= supp_elem]
        return qsort(less_arr) + [supp_elem] + qsort(greater_arr)

print(qsort([100,123,1,23,4,15,16,2,3,1,23,4,5123,1423,3234,12345,100000]))