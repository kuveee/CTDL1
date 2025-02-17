#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int R, C;
        cin >> R >> C;

        vector<vector<int>> grid(R, vector<int>(C));
        queue<pair<int, int>> seedlingQueue;
        vector<vector<int>> days(R, vector<int>(C, -1)); // Lưu số ngày nảy mầm, -1 là chưa nảy mầm

        // Đọc input và khởi tạo
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 0) {
                    seedlingQueue.push({i, j});
                    days[i][j] = 0; // Cây non ban đầu nảy mầm ngày 0
                }
            }
        }

        int maxDays = 0;
        int dr[] = {-1, 1, 0, 0}; // Các hướng di chuyển: lên, xuống, trái, phải
        int dc[] = {0, 0, -1, 1};

        while (!seedlingQueue.empty()) {
            pair<int, int> currentSeedling = seedlingQueue.front();
            seedlingQueue.pop();

            int row = currentSeedling.first;
            int col = currentSeedling.second;

            maxDays = max(maxDays, days[row][col]); // Cập nhật số ngày tối đa

            // Lan truyền dinh dưỡng cho các hạt mầm xung quanh
            for (int i = 0; i < 4; ++i) {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];

                if (nextRow >= 0 && nextRow < R && nextCol >= 0 && nextCol < C && grid[nextRow][nextCol] == 1 && days[nextRow][nextCol] == -1) {
                    grid[nextRow][nextCol] = 0; // Hạt mầm nảy mầm thành cây non
                    days[nextRow][nextCol] = days[row][col] + 1; // Ghi nhận ngày nảy mầm
                    seedlingQueue.push({nextRow, nextCol}); // Thêm vào queue để tiếp tục lan truyền
                }
            }
        }

        // Kiểm tra xem tất cả các hạt đã nảy mầm chưa
        bool allGerminated = true;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) {
                    allGerminated = false;
                    break;
                }
            }
            if (!allGerminated) break;
        }

        if (allGerminated) {
            cout << maxDays << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}