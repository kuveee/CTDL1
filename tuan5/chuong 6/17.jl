using DataStructures

function knight_min_moves(start::String, end::String)
    directions = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    
    # Chuyển đổi tọa độ chữ cái thành số và parse số hàng
    start_x, start_y = start[1] - 'a' + 1, parse(Int, start[2])
    end_x, end_y = end[1] - 'a' + 1, parse(Int, end[2])

    queue = Deque()  # Sử dụng Deque thay vì Queue
    enqueue!(queue, ((start_x, start_y), 0))  # Tọa độ và số bước
    visited = Set()

    while !isempty(queue)
        (x, y), steps = dequeue!(queue)

        if (x, y) == (end_x, end_y)
            return steps
        end

        visited += ((x, y))  # Cập nhật điểm đã thăm

        for (dx, dy) in directions
            nx, ny = x + dx, y + dy
            if nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && !(nx, ny in visited)
                enqueue!(queue, ((nx, ny), steps + 1))
            end
        end
    end
    return -1
end

# Ví dụ sử dụng:
println(knight_min_moves("e2", "e4"))  # Output: 2
