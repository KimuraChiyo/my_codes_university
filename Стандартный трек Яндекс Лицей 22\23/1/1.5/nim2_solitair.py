first_heap = int(input())
second_heap = int(input())

while first_heap + second_heap:
    heap = int(input())
    step = int(input())
    if heap % 2:
        first_heap -= step
    else:
        second_heap -= step
    print(first_heap, second_heap)