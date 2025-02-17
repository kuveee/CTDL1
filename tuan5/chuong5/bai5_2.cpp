#include <bits/stdc++.h>
using namespace std;

// Hàm đếm số lần đổi chiều cần thiết
int countBracketReversals(string s) {
    int open = 0, close = 0; // Biến đếm số lượng dấu ngoặc mở và đóng cần sửa

    for (char c : s) {
        if (c == '(') {
            open++; // Nếu là dấu mở, tăng biến đếm
        } else {
            if (open > 0) {
                open--; // Ghép với dấu '(' trước đó
            } else {
                close++; // Dấu ')' không có cặp, cần sửa
            }
        }
    }
    return (open + 1) / 2 + (close + 1) / 2; // Công thức tính số lần đổi
}

int main() {
    int T;
    cin >> T; // Nhập số test case

    while (T--) {
        string s;
        cin >> s;
        cout << countBracketReversals(s) << endl;
    }
    return 0;
}
