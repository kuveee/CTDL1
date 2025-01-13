
struct Student
    name::String
    score::Int
end


function merge(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid

   
    leftArr = arr[left:left + n1 - 1]
    rightArr = arr[mid + 1:mid + n2]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
        if leftArr[i].score < rightArr[j].score
            arr[k] = leftArr[i]
            i += 1
        elseif leftArr[i].score > rightArr[j].score
            arr[k] = rightArr[j]
            j += 1
        else
          
            if leftArr[i].name <= rightArr[j].name
                arr[k] = leftArr[i]
                i += 1
            else
                arr[k] = rightArr[j]
                j += 1
            end
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


function merge_sort(arr, left, right)
    if left < right
        mid = floor(Int, (left + right) / 2)

     
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

 
        merge(arr, left, mid, right)
    end
end


function print_students(arr)
    for student in arr
        println("$(student.name): $(student.score)")
    end
end

students = [
    Student("Alice", 90),
    Student("Bob", 90),
    Student("Charlie", 85),
    Student("David", 85),
    Student("Eve", 95),
    Student("Frank", 80)
]

println("Danh sách học sinh ban đầu:")
print_students(students)


merge_sort(students, 1, length(students))

println("\nDanh sách học sinh sau khi sắp xếp:")
print_students(students)
