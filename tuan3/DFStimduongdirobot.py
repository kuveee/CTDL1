from collections import deque

def dfs_find_path(grid, start, end):
    """
    Tìm đường đi trong lưới sử dụng DFS.

    Tham số:
        grid: Lưới 2D, 0 là ô trống, 1 là chướng ngại vật.
        start: Tuple (x, y) là vị trí bắt đầu.
        end: Tuple (x, y) là vị trí đích.

    Trả về:
        Danh sách các vị trí trong đường đi từ start đến end, hoặc None nếu không tìm thấy.
    """
    rows = len(grid)
    cols = len(grid[0])
    stack = deque([([start], start)])  # Ngăn xếp lưu trữ (đường đi hiện tại, vị trí hiện tại)
    visited = set()  # Tập hợp các vị trí đã thăm

    while stack:
        path, current = stack.pop()
        x, y = current

        if current == end:
            return path  # Tìm thấy đường đi

        if (x, y) not in visited:
            visited.add((x, y))

            # Duyệt các vị trí lân cận (lên, xuống, trái, phải)
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy

                # Kiểm tra vị trí mới có hợp lệ không
                if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 0 and (nx, ny) not in visited:
                    stack.append((path + [(nx, ny)], (nx, ny)))

    return None  # Không tìm thấy đường đi


# Ví dụ sử dụng
grid = [
    [0, 0, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0]
]
start = (0, 0)
end = (4, 4)

path = dfs_find_path(grid, start, end)

if path:
    print("Đường đi từ", start, "đến", end, "là:")
    for x, y in path:
        print(f"({x}, {y})")

    # In ra grid với đường đi
    grid_with_path = [row[:] for row in grid]  # Tạo bản sao của grid
    for x, y in path:
        if (x,y) != start and (x,y) != end:
            grid_with_path[x][y] = 'P'  # Đánh dấu đường đi
    print("Lưới với đường đi:")
    for row in grid_with_path:
        print(row)


else:
    print("Không tìm thấy đường đi từ", start, "đến", end)