from collections import deque

def rotate_left(s):
    next_s = list(s)  # Chuyển chuỗi thành list để dễ thay đổi
    temp = next_s[0]
    next_s[0] = next_s[3]
    next_s[3] = next_s[4]
    next_s[4] = next_s[1]
    next_s[1] = temp
    return "".join(next_s)  # Chuyển list trở lại thành chuỗi

def rotate_right(s):
    next_s = list(s)
    temp = next_s[1]
    next_s[1] = next_s[4]
    next_s[4] = next_s[5]
    next_s[5] = next_s[2]
    next_s[2] = temp
    return "".join(next_s)

def solve():
    initial_state = input()
    target_state = input()

    if initial_state == target_state:
        return 0

    q = deque()
    visited = set()

    q.append((initial_state, 0))
    visited.add(initial_state)

    while q:
        current_state, current_steps = q.popleft()

        if current_state == target_state:
            return current_steps

        next_state_left = rotate_left(current_state)
        if next_state_left not in visited:
            visited.add(next_state_left)
            q.append((next_state_left, current_steps + 1))

        next_state_right = rotate_right(current_state)
        if next_state_right not in visited:
            visited.add(next_state_right)
            q.append((next_state_right, current_steps + 1))

    return -1  # Không nên xảy ra

t = int(input())
for _ in range(t):
    print(solve())