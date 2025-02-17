#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây dùng `reverse` để đảo ngược chuỗi và `isalnum`

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử (+, -, *, /, ^) hay không
bool isOperator(char c) {
    // Trả về true nếu c là một trong các toán tử, ngược lại trả về false
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); // Có thể mở rộng thêm các toán tử khác nếu cần
}

// Hàm chuyển đổi biểu thức tiền tố (prefix) sang biểu thức hậu tố (postfix)
string prefixToPostfix(string prefix) {
    stack<string> operands; // Khai báo một stack có tên là 'operands' để lưu trữ các toán hạng (operand).
                             // Stack này sẽ chứa các chuỗi string, vì trong quá trình chuyển đổi, các toán hạng có thể là các biểu thức con.

    // **Quan trọng:** Xử lý biểu thức tiền tố bằng cách duyệt từ phải sang trái.
    reverse(prefix.begin(), prefix.end()); // Đảo ngược chuỗi 'prefix' để duyệt từ ký tự cuối về đầu

    // Duyệt qua từng ký tự 'c' trong chuỗi 'prefix' đã được đảo ngược
    for (char c : prefix) {
        if (isalnum(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ cái hoặc chữ số (toán hạng) hay không bằng hàm `isalnum`
            string operand(1, c); // Tạo một chuỗi string có độ dài 1 từ ký tự 'c'.
                                 // Cần chuyển thành string vì stack 'operands' là stack of strings.
            operands.push(operand); // Đẩy toán hạng (dạng string) vào stack 'operands'
        } else if (isOperator(c)) { // Nếu ký tự 'c' là một toán tử (kiểm tra bằng hàm `isOperator`)
            // **Lấy toán hạng từ stack:** Để thực hiện phép toán, cần ít nhất 2 toán hạng.
            if (operands.size() < 2) {
                // **Xử lý lỗi:** Nếu không đủ toán hạng trong stack, biểu thức tiền tố không hợp lệ.
                return "Invalid Expression"; // Trả về chuỗi báo lỗi (có thể thay bằng cách xử lý lỗi khác tùy yêu cầu)
            }
            string operand1 = operands.top(); // Lấy phần tử trên đỉnh stack (toán hạng thứ nhất được pop ra, tương ứng toán hạng bên phải trong biểu thức tiền tố)
            operands.pop();                   // Loại bỏ toán hạng thứ nhất khỏi stack
            string operand2 = operands.top(); // Lấy phần tử tiếp theo trên đỉnh stack (toán hạng thứ hai được pop ra, tương ứng toán hạng bên trái trong biểu thức tiền tố)
            operands.pop();                   // Loại bỏ toán hạng thứ hai khỏi stack

            // **Tạo biểu thức hậu tố:** Ghép các toán hạng và toán tử theo thứ tự hậu tố: operand1 operand2 operator.
            string postfixExpression = operand1 + operand2 + c; // Nối chuỗi để tạo biểu thức hậu tố: toán hạng 1, toán hạng 2, sau đó là toán tử.
            operands.push(postfixExpression); // Đẩy biểu thức hậu tố vừa tạo thành một toán hạng mới lên stack 'operands'
        }
    }

    // **Kiểm tra kết quả:** Sau khi duyệt hết biểu thức tiền tố, nếu biểu thức hợp lệ thì stack 'operands' phải chứa đúng 1 phần tử, là biểu thức hậu tố cuối cùng.
    if (operands.size() == 1) {
        return operands.top(); // Trả về biểu thức hậu tố cuối cùng (lấy từ đỉnh stack)
    } else {
        // **Xử lý lỗi:** Nếu stack không chứa đúng 1 phần tử, biểu thức tiền tố không hợp lệ.
        return "Invalid Expression"; // Trả về chuỗi báo lỗi (có thể thay bằng cách xử lý lỗi khác tùy yêu cầu)
    }
}

int main() {
    int t; // Biến 't' để lưu số lượng bộ test (test cases)
    cin >> t; // Đọc số lượng bộ test từ dòng đầu tiên của input
    cin.ignore(); // Đọc và bỏ qua ký tự dòng mới (newline) còn sót lại sau khi đọc số 't', tránh ảnh hưởng đến việc đọc dòng tiếp theo

    while (t--) { // Vòng lặp 'while' chạy 't' lần, xử lý từng bộ test
        string prefixExpression; // Biến 'prefixExpression' để lưu biểu thức tiền tố đầu vào cho mỗi bộ test
        getline(cin, prefixExpression); // Đọc cả dòng chứa biểu thức tiền tố từ input (ví dụ: "*+AB-CD")

        string postfixExpression = prefixToPostfix(prefixExpression); // Gọi hàm 'prefixToPostfix' để chuyển đổi biểu thức tiền tố sang hậu tố
        cout << postfixExpression << endl; // In biểu thức hậu tố kết quả ra output, sau đó xuống dòng cho bộ test tiếp theo
    }

    return 0; // Chương trình kết thúc thành công, trả về giá trị 0 cho hệ điều hành
}