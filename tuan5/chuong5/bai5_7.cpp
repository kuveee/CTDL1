#include <iostream>     // Thư viện nhập/xuất chuẩn
#include <string>       // Thư viện làm việc với chuỗi
#include <stack>        // Thư viện stack (ngăn xếp) để quản lý toán hạng
#include <algorithm>    // Thư viện algorithm để sử dụng hàm reverse

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không (+, -, *, /)
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm chuyển đổi biểu thức tiền tố (prefix) sang biểu thức trung tố (infix)
string prefixToInfix(string prefix) {
    stack<string> operands; // Stack để lưu trữ các toán hạng.
                             // Trong quá trình chuyển đổi, toán hạng có thể là các biểu thức con dạng chuỗi.

    // **Quan trọng:** Duyệt biểu thức tiền tố từ phải sang trái
    reverse(prefix.begin(), prefix.end()); // Đảo ngược chuỗi biểu thức tiền tố để xử lý từ phải qua trái

    for (char c : prefix) {
        if (isalnum(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ cái hoặc chữ số (toán hạng) hay không
            string operand(1, c); // Tạo một chuỗi string chứa ký tự toán hạng (vì stack chứa string)
            operands.push(operand); // Đẩy toán hạng vào stack
        } else if (isOperator(c)) { // Nếu ký tự 'c' là một toán tử (+, -, *, /)
            // **Chú ý thứ tự pop:**
            // Trong biểu thức tiền tố, toán tử đứng trước toán hạng. Khi chuyển sang trung tố, thứ tự toán hạng cần được đảo lại.
            // Lấy toán hạng thứ nhất (operand1) ra khỏi stack (thực chất là toán hạng bên phải trong biểu thức tiền tố)
            string operand1 = operands.top();
            operands.pop();

            // Lấy toán hạng thứ hai (operand2) ra khỏi stack (thực chất là toán hạng bên trái trong biểu thức tiền tố)
            string operand2 = operands.top();
            operands.pop();

            // Tạo biểu thức trung tố bằng cách ghép toán hạng 2, toán tử, và toán hạng 1, đặt trong ngoặc đơn
            // Cấu trúc: (operand2 operator operand1)  <--  chú ý thứ tự operand2 và operand1 bị đảo so với thứ tự pop
            string infixExpression = "(" + operand2 + c + operand1 + ")";
            operands.push(infixExpression); // Đẩy biểu thức trung tố vừa tạo vào stack để tiếp tục xử lý
        }
    }

    // Sau khi duyệt hết biểu thức tiền tố, biểu thức trung tố cuối cùng nằm trên đỉnh stack
    return operands.top(); // Lấy và trả về biểu thức trung tố cuối cùng từ stack
}

int main() {
    int t; // Biến lưu số lượng test case
    cin >> t; // Đọc số lượng test case từ input
    cin.ignore(); // Đọc bỏ dòng thừa (ký tự newline) sau khi đọc số test

    while (t--) { // Vòng lặp chạy 't' lần cho mỗi test case
        string prefixExpression; // Biến lưu biểu thức tiền tố đầu vào
        getline(cin, prefixExpression); // Đọc cả dòng biểu thức tiền tố từ input

        string infixExpression = prefixToInfix(prefixExpression); // Gọi hàm chuyển đổi tiền tố sang trung tố
        cout << infixExpression << endl; // In biểu thức trung tố kết quả ra output
    }

    return 0; // Kết thúc chương trình
}