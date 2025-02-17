#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

// Hàm tìm số bước di chuyển ít nhất từ điểm bắt đầu đến điểm đích trên bảng
int diChuyenTranhVatCan(int n, vector<vector<char>>& board, int start_x, int start_y, int end_x, int end_y) {
    if (board[start_x][start_y] == 'X' || board[end_x][end_y] == 'X') {
        return -1; // Nếu điểm bắt đầu hoặc điểm đích là vật cản, không có đường đi
    }

    queue<pair<pair<int, int>, int>> q; // Queue để thực hiện tìm kiếm theo chiều rộng (BFS)
    set<pair<int, int>> visited; // Set để theo dõi các ô đã посещённые

    q.push({{start_x, start_y}, 0}); // Bắt đầu BFS từ điểm xuất phát với số bước là 0
    visited.insert({start_x, start_y}); // Đánh dấu điểm xuất phát là đã посещённые

    int dx[] = {0, 0, 1, -1}; // Mảng dx cho 4 hướng di chuyển (ngang, dọc)
    int dy[] = {1, -1, 0, 0}; // Mảng dy cho 4 hướng di chuyển (ngang, dọc)

    while (!q.empty()) { // Vòng lặp BFS cho đến khi queue rỗng
        pair<pair<int, int>, int> current = q.front(); // Lấy trạng thái hiện tại từ đầu queue
        q.pop(); // Loại bỏ trạng thái hiện tại khỏi queue

        pair<int, int> point = current.first; // Lấy tọa độ điểm hiện tại
        int steps = current.second; // Lấy số bước đã đi đến điểm hiện tại

        int x = point.first; // Tọa độ x của điểm hiện tại
        int y = point.second; // Tọa độ y của điểm hiện tại

        if (x == end_x && y == end_y) { // Nếu đã đến điểm đích, trả về số bước
            return steps;
        }

        // Duyệt qua 4 hướng di chuyển (lên, xuống, trái, phải)
        for (int i = 0; i < 4; ++i) {
            int next_x = x; // Khởi tạo tọa độ x mới
            int next_y = y; // Khởi tạo tọa độ y mới

            while (true) { // Di chuyển theo hướng i cho đến khi gặp vật cản hoặc biên bảng
                next_x += dx[i]; // Cập nhật tọa độ x theo hướng i
                next_y += dy[i]; // Cập nhật tọa độ y theo hướng i

                // Kiểm tra xem ô mới có hợp lệ không: nằm trong bảng và không phải vật cản
                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_x][next_y] != 'X') {
                    if (visited.find({next_x, next_y}) == visited.end()) { // Nếu ô mới chưa được посещённые
                        visited.insert({next_x, next_y}); // Đánh dấu ô mới là đã посещённые
                        q.push({{next_x, next_y}, steps + 1}); // Thêm ô mới vào queue với số bước tăng lên 1
                    }
                } else {
                    break; // Dừng di chuyển theo hướng này nếu gặp vật cản, biên bảng hoặc đã посещённые
                }
            }
        }
    }

    return -1; // Nếu không tìm thấy đường đi (trường hợp này, theo đề bài thì sẽ luôn tìm thấy nếu điểm đích không phải vật cản)
}

int main() {
    int t;
    cin >> t; // Đọc số bộ test

    while (t--) { // Vòng lặp cho từng bộ test
        int n;
        cin >> n; // Đọc kích thước bảng N x N
        vector<vector<char>> board(n, vector<char>(n)); // Khởi tạo bảng kích thước N x N

        // **Đọc bảng theo dòng (đã chỉnh sửa):**
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row; // Đọc cả dòng vào string 'row'
            for (int j = 0; j < n; ++j) {
                board[i][j] = row[j]; // Gán từng ký tự từ string 'row' vào board
            }
        }

        // **In bảng vừa đọc (THÊM ĐOẠN CODE NÀY):**
        cout << "Bang da doc:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "Ket thuc in bang\n";


        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y; // Đọc tọa độ điểm xuất phát và điểm đích
        start_x--; start_y--; end_x--; end_y--; // Chuyển tọa độ về 0-based index

        cout << diChuyenTranhVatCan(n, board, start_x, start_y, end_x, end_y) << endl; // Gọi hàm và in kết quả
    }

    return 0; // Chương trình kết thúc thành công
}