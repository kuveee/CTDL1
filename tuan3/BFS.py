from collections import deque

def bfs(graph, start_node):
  """
  Thực hiện tìm kiếm theo chiều rộng (BFS) trên đồ thị.

  Tham số:
    graph: Một dictionary biểu diễn đồ thị, với các khóa là các nút và giá trị là danh sách các nút kề.
    start_node: Nút bắt đầu cho việc tìm kiếm.

  Trả về:
    Một dictionary chứa các nút đã được duyệt, với giá trị là True nếu nút đó đã được thăm.
  """
  visited = {}  # Lưu trữ các nút đã được thăm
  queue = deque([start_node])  # Hàng đợi cho BFS, khởi tạo với nút bắt đầu
  visited[start_node] = True

  while queue:
    current_node = queue.popleft()  # Lấy nút đầu tiên từ hàng đợi

    # Duyệt qua các nút kề của nút hiện tại
    for neighbor in graph[current_node]:
      if neighbor not in visited:
        visited[neighbor] = True
        queue.append(neighbor)  # Thêm nút kề vào hàng đợi

  return visited

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
visited_nodes = bfs(graph, start_node)

print(f"Các nút đã được duyệt từ nút {start_node}:")
for node, visited in visited_nodes.items():
  if visited:
      print(node)

# Kết quả mong đợi:
# Các nút đã được duyệt từ nút A:
# A
# B
# C
# D
# E
# F