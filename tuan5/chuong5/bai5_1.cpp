#include <iostream>
#include <stack>
using namespace std;

// Hàm kiểm tra xem biểu thức có dư thừa dấu ngoặc hay không
bool hasRedundantParentheses(string exp) {
    stack<char> s; // Dùng stack để lưu các ký tự của biểu thức

    for (char ch : exp) {
        if (ch == ')') { // Khi gặp dấu đóng ngoặc ')'
            char top = s.top();
            s.pop();
            bool isRedundant = true; // Giả định ban đầu là có dư thừa

            // Kiểm tra bên trong cặp dấu ngoặc có toán tử hay không
            while (!s.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    isRedundant = false; // Nếu có toán tử, không dư thừa
                top = s.top();
                s.pop();
            }

            if (isRedundant)
                return true; // Nếu không có toán tử nào, tức là dấu ngoặc dư thừa
        } else {
            s.push(ch); // Đẩy ký tự vào stack
        }
    }
    return false; // Nếu duyệt hết mà không phát hiện dư thừa thì hợp lệ
}

int main() {
    int T;
    cin >> T; // Nhập số lượng test case
    cin.ignore(); // Loại bỏ ký tự xuống dòng còn lại sau khi nhập số

    while (T--) {
        string exp;
        getline(cin, exp); // Nhập biểu thức
        cout << (hasRedundantParentheses(exp) ? "No" : "Yes") << endl;
    }
    return 0;
}
