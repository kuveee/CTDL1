import time

def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid


    leftArr = arr[left:left + n1]
    rightArr = arr[mid + 1:mid + 1 + n2]

    i = j = k = left
    while i < n1 and j < n2:
        if leftArr[i] <= rightArr[j]:
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


def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2 

        mergeSort(arr, left, mid)  
        mergeSort(arr, mid + 1, right) 

        merge(arr, left, mid, right)  


def printArray(arr):
    print(" ".join(map(str, arr)))


if __name__ == "__main__":

    arr = [12, 11, 13, 5, 6, 7]

    print("Mảng ban đầu:")
    printArray(arr)

   
    start_time = time.time()

   
    mergeSort(arr, 0, len(arr) - 1)


    end_time = time.time()

    print("Mảng đã được sắp xếp:")
    printArray(arr)

 
    elapsed_time = end_time - start_time
    print(f"Time taken for sorting: {elapsed_time:.6f} seconds.")
