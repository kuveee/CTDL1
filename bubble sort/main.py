import time  

def bubble_sort(lst):
    n = len(lst)
    for i in range(n-1):
        check = False
        for j in range(0, n - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j] 
                check = True
        if not check:  
            break

a = [64, 34, 25, 12, 22, 11, 90, 100, 45, 33, 76, 28, 51, 89, 55, 78, 82, 63, 56,64, 34, 25, 12, 22, 11, 90, 100, 45, 33, 76, 28, 51, 89, 55, 78, 82, 63, 56]
print("Before sorting:", a)


start_time = time.time()

bubble_sort(a)


end_time = time.time()

print("After sorting:", a)


elapsed_time = end_time - start_time
print(f"Time taken for sorting: {elapsed_time:.6f} seconds.")
