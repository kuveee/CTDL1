#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> // ADD THIS LINE

using namespace std;

// Hàm tìm số nhỏ nhất thỏa mãn chuỗi 'I' và 'D'
string findSmallestNumber(string s) {
    int n = s.length() + 1; // Số lượng chữ số cần dùng là chiều dài chuỗi + 1
    string result = "";
    vector<bool> used(10, false); // Mảng đánh dấu số nào đã được sử dụng (từ 1 đến 9)

    function<bool(int)> solve = [&](int current_digit_index) {
        if (current_digit_index == n) {
            return true; // Đã tạo thành số có đủ chữ số
        }

        for (int digit = 1; digit <= 9; ++digit) {
            if (!used[digit]) { // Nếu số này chưa được dùng
                if (current_digit_index > 0) {
                    // Kiểm tra điều kiện 'I' hoặc 'D' với chữ số trước đó
                    if (s[current_digit_index - 1] == 'I' && result[current_digit_index - 1] - '0' >= digit) {
                        continue; // Không thỏa mãn 'I' - số hiện tại phải lớn hơn số trước
                    }
                    if (s[current_digit_index - 1] == 'D' && result[current_digit_index - 1] - '0' <= digit) {
                        continue; // Không thỏa mãn 'D' - số hiện tại phải nhỏ hơn số trước
                    }
                }

                used[digit] = true; // Đánh dấu là đã dùng
                result += to_string(digit); // Thêm chữ số vào kết quả

                if (solve(current_digit_index + 1)) { // Gọi đệ quy để tìm chữ số tiếp theo
                    return true; // Tìm thấy một số thỏa mãn
                }

                // Backtracking: Nếu không thành công, bỏ chọn số hiện tại và thử số khác
                used[digit] = false;
                result.pop_back();
            }
        }
        return false; // Không tìm được chữ số nào thỏa mãn ở vị trí hiện tại
    };

    solve(0); // Bắt đầu tìm kiếm từ chữ số đầu tiên

    return result; // Trả về số nhỏ nhất tìm được
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << findSmallestNumber(s) << endl;
    }
    return 0;
}