#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây dùng `isalnum`

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử (+, -, *, /, ^) hay không
bool isOperator(char c) {
    // Trả về true nếu c là một trong các toán tử, ngược lại trả về false
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); // Có thể mở rộng thêm các toán tử khác nếu cần
}

// Hàm chuyển đổi biểu thức hậu tố (postfix) sang biểu thức tiền tố (prefix)
string postfixToPrefix(string postfix) {
    stack<string> operands; // Khai báo một stack có tên là 'operands' để lưu trữ các toán hạng.
                             // Stack này sẽ chứa các chuỗi string, vì trong quá trình chuyển đổi, các toán hạng có thể là các biểu thức con.

    // **Quan trọng:** Xử lý biểu thức hậu tố bằng cách duyệt từ trái sang phải (thứ tự thông thường).
    // Không cần đảo ngược chuỗi hậu tố như trong chuyển đổi tiền tố sang hậu tố.

    // Duyệt qua từng ký tự 'c' trong chuỗi 'postfix'
    for (char c : postfix) {
        if (isalnum(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ cái hoặc chữ số (toán hạng) hay không bằng hàm `isalnum`
            string operand(1, c); // Tạo một chuỗi string có độ dài 1 từ ký tự 'c'.
                                 // Cần chuyển thành string vì stack 'operands' là stack of strings.
            operands.push(operand); // Đẩy toán hạng (dạng string) vào stack 'operands'
        } else if (isOperator(c)) { // Nếu ký tự 'c' là một toán tử (kiểm tra bằng hàm `isOperator`)
            // **Lấy toán hạng từ stack:** Để thực hiện phép toán, cần ít nhất 2 toán hạng.
            if (operands.size() < 2) {
                // **Xử lý lỗi:** Nếu không đủ toán hạng trong stack, biểu thức hậu tố không hợp lệ.
                return "Invalid Expression"; // Trả về chuỗi báo lỗi (có thể thay bằng cách xử lý lỗi khác tùy yêu cầu)
            }
            string operand1 = operands.top(); // Lấy phần tử trên đỉnh stack (toán hạng thứ nhất được pop ra, tương ứng toán hạng bên phải trong biểu thức hậu tố)
            operands.pop();                   // Loại bỏ toán hạng thứ nhất khỏi stack
            string operand2 = operands.top(); // Lấy phần tử tiếp theo trên đỉnh stack (toán hạng thứ hai được pop ra, tương ứng toán hạng bên trái trong biểu thức hậu tố)
            operands.pop();                   // Loại bỏ toán hạng thứ hai khỏi stack

            // **Tạo biểu thức tiền tố:** Ghép toán tử, toán hạng 2, toán hạng 1 theo thứ tự tiền tố: operator operand2 operand1.
            string prefixExpression = c + operand2 + operand1; // Nối chuỗi để tạo biểu thức tiền tố: toán tử, toán hạng 2, sau đó là toán hạng 1.
            operands.push(prefixExpression); // Đẩy biểu thức tiền tố vừa tạo thành một toán hạng mới lên stack 'operands'
        }
    }

    // **Kiểm tra kết quả:** Sau khi duyệt hết biểu thức hậu tố, nếu biểu thức hợp lệ thì stack 'operands' phải chứa đúng 1 phần tử, là biểu thức tiền tố cuối cùng.
    if (operands.size() == 1) {
        return operands.top(); // Trả về biểu thức tiền tố cuối cùng (lấy từ đỉnh stack)
    } else {
        // **Xử lý lỗi:** Nếu stack không chứa đúng 1 phần tử, biểu thức hậu tố không hợp lệ.
        return "Invalid Expression"; // Trả về chuỗi báo lỗi (có thể thay bằng cách xử lý lỗi khác tùy yêu cầu)
    }
}

int main() {
    int t; // Biến 't' để lưu số lượng bộ test (test cases)
    cin >> t; // Đọc số lượng bộ test từ dòng đầu tiên của input
    cin.ignore(); // Đọc và bỏ qua ký tự dòng mới (newline) còn sót lại sau khi đọc số 't', tránh ảnh hưởng đến việc đọc dòng tiếp theo

    while (t--) { // Vòng lặp 'while' chạy 't' lần, xử lý từng bộ test
        string postfixExpression; // Biến 'postfixExpression' để lưu biểu thức hậu tố đầu vào cho mỗi bộ test
        getline(cin, postfixExpression); // Đọc cả dòng chứa biểu thức hậu tố từ input (ví dụ: "AB+CD-*")

        string prefixExpression = postfixToPrefix(postfixExpression); // Gọi hàm 'postfixToPrefix' để chuyển đổi biểu thức hậu tố sang tiền tố
        cout << prefixExpression << endl; // In biểu thức tiền tố kết quả ra output, sau đó xuống dòng cho bộ test tiếp theo
    }

    return 0; // Chương trình kết thúc thành công, trả về giá trị 0 cho hệ điều hành
}