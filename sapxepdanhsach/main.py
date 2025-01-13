
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

  
    leftArr = arr[left:left + n1]
    rightArr = arr[mid + 1:mid + 1 + n2]


    i, j, k = 0, 0, left
    while i < n1 and j < n2:
     
        if leftArr[i][1] < rightArr[j][1]:
            arr[k] = leftArr[i]
            i += 1
        elif leftArr[i][1] > rightArr[j][1]:
            arr[k] = rightArr[j]
            j += 1
        else:
            if leftArr[i][0] <= rightArr[j][0]:
                arr[k] = leftArr[i]
                i += 1
            else:
                arr[k] = rightArr[j]
                j += 1
        k += 1

   
    while i < n1:
        arr[k] = leftArr[i]
        i += 1
        k += 1

  
    while j < n2:
        arr[k] = rightArr[j]
        j += 1
        k += 1


def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2

      
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

       
        merge(arr, left, mid, right)


def print_students(arr):
    for student in arr:
        print(f"{student[0]}: {student[1]}")


students = [
    ("Alice", 90),
    ("Bob", 90),
    ("Charlie", 85),
    ("David", 85),
    ("Eve", 95),
    ("Frank", 80)
]

print("Danh sách học sinh ban đầu:")
print_students(students)


merge_sort(students, 0, len(students) - 1)

print("\nDanh sách học sinh sau khi sắp xếp:")
print_students(students)
