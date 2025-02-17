#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m + 1, vector<int>(n + 1)); // Ma trận A, kích thước m x n, index từ 1

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    queue<tuple<int, int, int>> q; // Queue để BFS: {row, col, steps}
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false)); // Ma trận đánh dấu đã thăm

    q.push({1, 1, 0}); // Bắt đầu từ A[1][1] với 0 bước
    visited[1][1] = true;

    while (!q.empty()) {
        auto [row, col, steps] = q.front();
        q.pop();

        if (row == m && col == n) { // Đến đích A[M][N]
            return steps;
        }

        // Các bước di chuyển có thể
        int next_row_down1 = row + 1;
        int next_row_down_val = row + a[row][col];
        int next_col = col;

        // Di chuyển xuống 1 đơn vị
        if (next_row_down1 <= m && !visited[next_row_down1][next_col]) {
            visited[next_row_down1][next_col] = true;
            q.push({next_row_down1, next_col, steps + 1});
        }

        // Di chuyển xuống theo giá trị A[i][j]
        if (next_row_down_val <= m && !visited[next_row_down_val][next_col]) {
            visited[next_row_down_val][next_col] = true;
            q.push({next_row_down_val, next_col, steps + 1});
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}