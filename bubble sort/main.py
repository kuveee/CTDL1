def bubble_sort(lst):
    n = len(lst)
    for i in range(n-1):
        check = False
        for j in range(0,n - i -1):
            if (lst[j] > lst[j+1]):
                temp  = lst[j]
                lst[j] = lst[j+1]
                lst[j+1] = temp
                check = True
        if check == False:
            break

a = [64, 34, 25, 12, 22, 11, 90]
print("before: ",a)
                
bubble_sort(a)
print("after sorted: ",a)
                