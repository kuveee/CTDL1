from collections import deque

def max_sliding_window(num_list, k):
    if not num_list or k == 0:
        return []
    
    result = []
    dq = deque()
    
    for i in range(len(num_list)):

        if dq and dq[0] < i - k + 1:
            dq.popleft()
        
        
        while dq and num_list[dq[-1]] < num_list[i]:
            dq.pop()
        
        dq.append(i)
        
   
        if i >= k - 1:
            result.append(num_list[dq[0]])
    
    return result


num_list = list(map(int, input("Nhập danh sách số nguyên: ").split()))
k = int(input("Nhập kích thước cửa sổ trượt k: "))
print(max_sliding_window(num_list, k))


# way 2
# def max_sliding_window_blocks(num_list, k):
#     if not num_list or k == 0:
#         return []

#     n = len(num_list)
#     left_max = [0] * n
#     right_max = [0] * n

#     for i in range(n):
#         if i % k == 0:
#             left_max[i] = num_list[i]
#         else:
#             left_max[i] = max(left_max[i - 1], num_list[i])

#     for i in range(n - 1, -1, -1):
#         if i == n - 1 or (i + 1) % k == 0:
#             right_max[i] = num_list[i]
#         else:
#             right_max[i] = max(right_max[i + 1], num_list[i])

#     result = []
#     for i in range(n - k + 1):
#         result.append(max(right_max[i], left_max[i + k - 1]))

#     return result


# num_list = list(map(int, input("Nhập danh sách số nguyên: ").split()))
# k = int(input("Nhập kích thước cửa sổ: "))
# print(max_sliding_window_blocks(num_list, k))

