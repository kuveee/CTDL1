from collections import deque

def bfs(graph, start_node):
  """
  Thực hiện tìm kiếm theo chiều rộng (BFS) trên đồ thị sử dụng hàng đợi.

  Tham số:
    graph: Một dictionary biểu diễn đồ thị, với các khóa là các nút và giá trị là danh sách các nút kề.
    start_node: Nút bắt đầu cho việc tìm kiếm.

  Trả về:
    Một danh sách chứa các nút đã được duyệt theo thứ tự BFS.
  """
  visited = set()  # Tập hợp các nút đã được thăm
  queue = deque([start_node])  # Hàng đợi cho BFS, khởi tạo với nút bắt đầu
  visited_order = [] # Danh sách lưu thứ tự duyệt

  while queue:
    current_node = queue.popleft()  # Lấy nút đầu tiên từ hàng đợi

    if current_node not in visited:
      visited.add(current_node)
      visited_order.append(current_node)

      # Thêm các nút kề chưa được thăm vào hàng đợi
      for neighbor in graph[current_node]:
        if neighbor not in visited:
          queue.append(neighbor)

  return visited_order

# Ví dụ sử dụng
graph = {
  'A': ['B', 'C'],
  'B': ['A', 'D', 'E'],
  'C': ['A', 'F'],
  'D': ['B'],
  'E': ['B', 'F'],
  'F': ['C', 'E']
}

start_node = 'A'
traversal_order = bfs(graph, start_node)

print(f"Thứ tự duyệt BFS từ nút {start_node}: {traversal_order}")

# Kết quả mong đợi:
# Thứ tự duyệt BFS từ nút A: ['A', 'B', 'C', 'D', 'E', 'F']