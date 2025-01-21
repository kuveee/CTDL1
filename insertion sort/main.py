import time  

def insertion_sort(lst):
    n = len(lst)
    for i in range(1, n):
        key = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > key:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = key

lst = [5, 6, 9, 1, 2, 3, 25, 62, 78, 90]
print(f'Before sort: {lst}')


start_time = time.time()

insertion_sort(lst)


end_time = time.time()

print(f'After sorted: {lst}')


elapsed_time = end_time - start_time
print(f"Time taken for sorting: {elapsed_time:.6f} seconds.")
