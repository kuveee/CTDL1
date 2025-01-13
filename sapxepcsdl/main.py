
def partition(arr, low, high):
    pivot = arr[high].login_date  
    i = low - 1
    for j in range(low, high):
        if arr[j].login_date > pivot: 
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    if low < high:
        pivot_index = partition(arr, low, high)
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)


class Record:
    def __init__(self, id, login_date):
        self.id = id
        self.login_date = login_date 

    def __str__(self):
        return f"{self.id}: {self.login_date}"

records = [
    Record(1, "2025-01-10"),
    Record(2, "2025-01-15"),
    Record(3, "2025-01-12"),
    Record(4, "2025-01-08"),
    Record(5, "2025-01-18"),
    Record(6, "2025-01-05")
]

print("Danh sách bản ghi ban đầu:")
for record in records:
    print(record)


quick_sort(records, 0, len(records) - 1)

print("\nDanh sách bản ghi sau khi sắp xếp:")
for record in records:
    print(record)
