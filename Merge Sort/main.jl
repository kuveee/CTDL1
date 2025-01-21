function merge(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid

    leftArr = arr[left:left + n1 - 1]
    rightArr = arr[mid + 1:mid + n2]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
        if leftArr[i] <= rightArr[j]
            arr[k] = leftArr[i]
            i += 1
        else
            arr[k] = rightArr[j]
            j += 1
        end
        k += 1
    end

    while i <= n1
        arr[k] = leftArr[i]
        i += 1
        k += 1
    end

    while j <= n2
        arr[k] = rightArr[j]
        j += 1
        k += 1
    end
end

function mergeSort(arr, left, right)
    if left < right
        mid = div(left + right, 2)  

        mergeSort(arr, left, mid) 
        mergeSort(arr, mid + 1, right) 

        merge(arr, left, mid, right) 
    end
end

function printArray(arr)
    println(join(arr, " "))
end


arr = [12, 11, 13, 5, 6, 7]

println("Mảng ban đầu:")
printArray(arr)


start_time = time()


mergeSort(arr, 1, length(arr))


end_time = time()

println("Mảng đã được sắp xếp:")
printArray(arr)


elapsed_time = end_time - start_time
println("Time taken for sorting: ", elapsed_time, " seconds.")
