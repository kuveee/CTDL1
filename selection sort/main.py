def insertion_sort(lst):
    n = len(lst)
    for i in range(n-1): #check tu 0 den n-1
        min = i
        for j in range(i+1,n):
            if(lst[min] > lst[j]):  # compare min tu min+1 -> n
                min = j   #update 
        # lst[i], lst[min] = lst[min], lst[i]
        temp = lst[i]
        lst[i] = min
        lst[min] = temp
        
def print_lst(lst):
    print(' '.join(map(str,lst)))
    
lst = [1,7,8,2,3,6,9,123,321,312,74]
print(f'before sorted: ')
print_lst(lst)

insertion_sort(lst)

print(f'after sorted: ')
print_lst(lst)