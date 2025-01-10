def insertion_sort(lst):
    n = len(lst)
    for i in range(1,n):
        key = lst[i]
        j = i - 1
        while(j>=0 and lst[j] > key):
            lst[j+1] = lst[j]
            j=j-1
        lst[j+1] = key

lst = [5,6,9,1,2,3,25,62,78,90]
print(f'before sort: {lst}')
insertion_sort(lst)
print(f'after sorted: {lst}')
            
        