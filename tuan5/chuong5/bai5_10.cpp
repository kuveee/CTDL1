#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <cctype>       // Thư viện chứa các hàm kiểm tra kiểu ký tự, ở đây dùng `isalnum` (is alphanumeric - chữ và số)

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử (+, -, *, /, ^) hay không
bool isOperator(char c) {
    // Trả về 'true' nếu 'c' là một trong các toán tử, 'false' nếu không phải.
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); // Bạn có thể thêm các toán tử khác nếu cần
}

// Hàm chuyển đổi biểu thức hậu tố (postfix) sang biểu thức trung tố (infix)
string postfixToInfix(string postfix) {
    stack<string> operands; // Khai báo một stack có tên là 'operands' để lưu trữ các toán hạng.
                             // Stack này sẽ chứa các chuỗi string, vì trong quá trình chuyển đổi, các toán hạng có thể là các biểu thức con.

    // Duyệt qua từng ký tự 'c' trong chuỗi biểu thức hậu tố 'postfix' (từ trái sang phải, theo thứ tự thông thường của hậu tố)
    for (char c : postfix) {
        if (isalnum(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ cái hoặc chữ số (toán hạng) hay không bằng hàm `isalnum`
            string operand(1, c); // Tạo một chuỗi string có độ dài 1 từ ký tự 'c'.
                                 // Cần chuyển thành string vì stack 'operands' là stack of strings.
            operands.push(operand); // Đẩy toán hạng (dạng string) vào stack 'operands'
        } else if (isOperator(c)) { // Nếu ký tự 'c' là một toán tử (kiểm tra bằng hàm `isOperator`)
            // **Lấy toán hạng từ stack:** Để thực hiện phép toán (ví dụ '+', '-', '*', '/'), chúng ta cần ít nhất 2 toán hạng.
            if (operands.size() < 2) {
                // **Xử lý lỗi:** Nếu không đủ toán hạng trong stack khi gặp toán tử, có nghĩa là biểu thức hậu tố không hợp lệ.
                return "Invalid Expression"; // Trả về chuỗi báo lỗi (bạn có thể tùy chỉnh cách xử lý lỗi khác nếu muốn)
            }
            string operand2 = operands.top(); // Lấy phần tử trên đỉnh stack (toán hạng thứ hai được pop ra, tương ứng toán hạng bên phải trong biểu thức hậu tố)
            operands.pop();                   // Loại bỏ toán hạng thứ hai khỏi stack
            string operand1 = operands.top(); // Lấy phần tử tiếp theo trên đỉnh stack (toán hạng thứ nhất được pop ra, tương ứng toán hạng bên trái trong biểu thức hậu tố)
            operands.pop();                   // Loại bỏ toán hạng thứ nhất khỏi stack

            // **Tạo biểu thức trung tố:** Ghép các toán hạng và toán tử theo thứ tự trung tố: (operand1 operator operand2), đặt trong ngoặc đơn.
            string infixExpression = "(" + operand1 + c + operand2 + ")"; // Nối chuỗi để tạo biểu thức trung tố: mở ngoặc, toán hạng 1, toán tử, toán hạng 2, đóng ngoặc.
            operands.push(infixExpression); // Đẩy biểu thức trung tố vừa tạo thành một toán hạng mới lên stack 'operands'
        }
    }

    // **Kiểm tra kết quả:** Sau khi duyệt hết biểu thức hậu tố, nếu biểu thức hợp lệ thì stack 'operands' phải chứa đúng 1 phần tử duy nhất, đó là biểu thức trung tố cuối cùng.
    if (operands.size() == 1) {
        return operands.top(); // Trả về biểu thức trung tố cuối cùng (lấy từ đỉnh stack)
    } else {
        // **Xử lý lỗi:** Nếu stack không chứa đúng 1 phần tử, có nghĩa là biểu thức hậu tố đầu vào không hợp lệ (ví dụ thừa toán hạng hoặc toán tử).
        return "Invalid Expression"; // Trả về chuỗi báo lỗi (bạn có thể tùy chỉnh cách xử lý lỗi khác nếu muốn)
    }
}

int main() {
    int t; // Biến 't' để lưu số lượng bộ test (test cases)
    cin >> t; // Đọc số lượng bộ test từ dòng đầu tiên của input
    cin.ignore(); // Đọc và bỏ qua ký tự dòng mới (newline) còn sót lại sau khi đọc số 't', tránh ảnh hưởng đến việc đọc dòng tiếp theo

    while (t--) { // Vòng lặp 'while' chạy 't' lần, xử lý từng bộ test
        string postfixExpression; // Biến 'postfixExpression' để lưu biểu thức hậu tố đầu vào cho mỗi bộ test
        getline(cin, postfixExpression); // Đọc cả dòng chứa biểu thức hậu tố từ input (ví dụ: "ABC++")

        string infixExpression = postfixToInfix(postfixExpression); // Gọi hàm 'postfixToInfix' để chuyển đổi biểu thức hậu tố sang trung tố
        cout << infixExpression << endl; // In biểu thức trung tố kết quả ra output, sau đó xuống dòng cho bộ test tiếp theo
    }

    return 0; // Chương trình kết thúc thành công, trả về giá trị 0 cho hệ điều hành
}