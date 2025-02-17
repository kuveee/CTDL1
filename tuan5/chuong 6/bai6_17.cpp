#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int solve() {
    string start_pos, end_pos;
    cin >> start_pos >> end_pos;

    // Chuyển đổi ký hiệu cờ vua sang tọa độ (row, col) 0-based
    int start_col = start_pos[0] - 'a';
    int start_row = start_pos[1] - '1';
    int end_col = end_pos[0] - 'a';
    int end_row = end_pos[1] - '1';

    if (start_col == end_col && start_row == end_row) {
        return 0; // Nếu vị trí bắt đầu và kết thúc giống nhau, số bước là 0
    }

    // Các bước di chuyển của quân mã (8 hướng)
    int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

    queue<pair<int, int>> q; // Queue cho BFS: {col, row}
    vector<vector<int>> dist(8, vector<int>(8, -1)); // Ma trận khoảng cách, -1 là chưa thăm

    q.push({start_col, start_row});
    dist[start_row][start_col] = 0; // Khoảng cách từ điểm bắt đầu đến chính nó là 0

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int col = current.first;
        int row = current.second;

        if (col == end_col && row == end_row) {
            return dist[end_row][end_col]; // Đã đến đích, trả về khoảng cách
        }

        for (int i = 0; i < 8; ++i) {
            int next_col = col + dx[i];
            int next_row = row + dy[i];

            // Kiểm tra xem vị trí mới có hợp lệ và chưa được thăm
            if (next_col >= 0 && next_col < 8 && next_row >= 0 && next_row < 8 && dist[next_row][next_col] == -1) {
                dist[next_row][next_col] = dist[row][col] + 1; // Cập nhật khoảng cách
                q.push({next_col, next_row}); // Thêm vào queue để duyệt tiếp
            }
        }
    }

    return -1; // Không tìm thấy đường đi (trên lý thuyết không xảy ra với quân mã trên bàn cờ)
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}