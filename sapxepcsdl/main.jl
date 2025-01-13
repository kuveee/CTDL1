
struct Record
    id::Int
    login_date::String
end


function partition(arr, low, high)
    pivot = arr[high].login_date  
    i = low - 1
    for j in low:high-1
        if arr[j].login_date > pivot  
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1
end


function quick_sort(arr, low, high)
    if low < high
        pivot_index = partition(arr, low, high)
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)
    end
end


function print_records(arr)
    for record in arr
        println("$(record.id): $(record.login_date)")
    end
end


records = [
    Record(1, "2025-01-10"),
    Record(2, "2025-01-15"),
    Record(3, "2025-01-12"),
    Record(4, "2025-01-08"),
    Record(5, "2025-01-18"),
    Record(6, "2025-01-05")
]

println("Danh sách bản ghi ban đầu:")
print_records(records)


quick_sort(records, 1, length(records))

println("\nDanh sách bản ghi sau khi sắp xếp:")
print_records(records)
