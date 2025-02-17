#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <vector>       // Thư viện cung cấp cấu trúc dữ liệu vector (mảng động), mặc dù không dùng trực tiếp trong code này nhưng vẫn thường được include trong C++
#include <cctype>       // Thư viện chứa các hàm kiểm tra kiểu ký tự, ở đây dùng `isdigit` (kiểm tra chữ số) và `isspace` (kiểm tra khoảng trắng)

using namespace std;

// Hàm xác định độ ưu tiên của toán tử (thứ tự thực hiện phép tính)
int precedence(char op) {
    if (op == '*' || op == '/') return 2; // Toán tử nhân '*' và chia '/' có độ ưu tiên cao hơn (nhóm 2)
    if (op == '+' || op == '-') return 1; // Toán tử cộng '+' và trừ '-' có độ ưu tiên thấp hơn (nhóm 1)
    return 0; // Trường hợp khác (ví dụ: dấu ngoặc '(' ), độ ưu tiên thấp nhất (nhóm 0, để dễ dàng push vào stack)
}

// Hàm chính để tính giá trị của biểu thức trung tố (infix)
int evaluateInfix(string expression) {
    stack<int> values;       // Stack 'values' để chứa các giá trị số (toán hạng) trong quá trình tính toán
    stack<char> operators;   // Stack 'operators' để chứa các toán tử (+, -, *, /) và dấu ngoặc '('

    // Duyệt qua từng ký tự của biểu thức trung tố đầu vào
    for (int i = 0; i < expression.length(); ++i) {
        if (isspace(expression[i])) { // Nếu ký tự hiện tại là khoảng trắng (space, tab, newline...), thì bỏ qua, không làm gì
            continue; // Chuyển đến ký tự tiếp theo của biểu thức
        } else if (isdigit(expression[i])) { // Nếu ký tự hiện tại là một chữ số (0-9), thì bắt đầu đọc số (có thể có nhiều chữ số)
            int value = 0; // Biến tích lũy giá trị số
            // Đọc liên tiếp các chữ số để tạo thành một số nguyên (ví dụ số "123" có 3 chữ số '1', '2', '3')
            while (i < expression.length() && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0'); // Ví dụ: '2' - '0' = 2 (chuyển ký tự '2' sang số 2)
                i++; // Tăng index 'i' để đọc ký tự tiếp theo
            }
            values.push(value); // Sau khi đọc xong số, đẩy giá trị số nguyên vào stack 'values'
            i--; // **Quan trọng**: Vì vòng lặp 'for' sẽ tự tăng 'i' thêm 1 ở cuối mỗi vòng lặp, nên cần giảm 'i' đi 1 ở đây để khi vòng lặp tiếp theo bắt đầu, 'i' sẽ ở đúng vị trí ký tự tiếp theo cần xét (ngay sau số vừa đọc)
        } else if (expression[i] == '(') {
            operators.push('('); // Nếu gặp dấu ngoặc mở '(', đẩy nó vào stack 'operators'
        } else if (expression[i] == ')') {
            // Nếu gặp dấu ngoặc đóng ')', thực hiện các phép toán cho đến khi gặp dấu ngoặc mở '(' trên stack
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top(); // Lấy toán tử từ đỉnh stack 'operators'
                operators.pop();         // Loại bỏ toán tử vừa lấy ra khỏi stack
                int val2 = values.top();  // Lấy toán hạng thứ hai (bên phải) từ stack 'values' (pop ra sau)
                values.pop();           // Loại bỏ toán hạng thứ hai vừa lấy ra khỏi stack
                int val1 = values.top();  // Lấy toán hạng thứ nhất (bên trái) từ stack 'values' (pop ra trước)
                values.pop();           // Loại bỏ toán hạng thứ nhất vừa lấy ra khỏi stack

                switch (op) { // Thực hiện phép toán dựa trên toán tử 'op'
                    case '+': values.push(val1 + val2); break; // Cộng: val1 + val2
                    case '-': values.push(val1 - val2); break; // Trừ: val1 - val2
                    case '*': values.push(val1 * val2); break; // Nhân: val1 * val2
                    case '/': values.push(val1 / val2); break; // Chia nguyên: val1 / val2
                }
            }
            operators.pop(); // Loại bỏ dấu ngoặc mở '(' khỏi stack 'operators' (dấu '(' này là cặp với dấu ')' hiện tại đang xét)
        } else { // Nếu ký tự hiện tại là một toán tử (+, -, *, /)
            // Thực hiện các phép toán trong khi stack toán tử không rỗng,
            // và toán tử trên đỉnh stack không phải dấu ngoặc mở '(',
            // và độ ưu tiên của toán tử trên đỉnh stack lớn hơn hoặc bằng độ ưu tiên của toán tử hiện tại
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(expression[i])) {
                char op = operators.top(); // Lấy toán tử từ đỉnh stack 'operators'
                operators.pop();         // Loại bỏ toán tử vừa lấy ra khỏi stack
                int val2 = values.top();  // Lấy toán hạng thứ hai (bên phải) từ stack 'values' (pop ra sau)
                values.pop();           // Loại bỏ toán hạng thứ hai vừa lấy ra khỏi stack
                int val1 = values.top();  // Lấy toán hạng thứ nhất (bên trái) từ stack 'values' (pop ra trước)
                values.pop();           // Loại bỏ toán hạng thứ nhất vừa lấy ra khỏi stack

                switch (op) { // Thực hiện phép toán dựa trên toán tử 'op'
                    case '+': values.push(val1 + val2); break; // Cộng: val1 + val2
                    case '-': values.push(val1 - val2); break; // Trừ: val1 - val2
                    case '*': values.push(val1 * val2); break; // Nhân: val1 * val2
                    case '/': values.push(val1 / val2); break; // Chia nguyên: val1 / val2
                }
            }
            operators.push(expression[i]); // Đẩy toán tử hiện tại vào stack 'operators' để xử lý sau
        }
    }

    // Sau khi duyệt hết biểu thức, vẫn có thể còn toán tử trong stack 'operators'
    // Thực hiện nốt các phép toán còn lại trong stack
    while (!operators.empty()) {
        char op = operators.top(); // Lấy toán tử từ đỉnh stack 'operators'
        operators.pop();         // Loại bỏ toán tử vừa lấy ra khỏi stack
        int val2 = values.top();  // Lấy toán hạng thứ hai (bên phải) từ stack 'values' (pop ra sau)
        values.pop();           // Loại bỏ toán hạng thứ hai vừa lấy ra khỏi stack
        int val1 = values.top();  // Lấy toán hạng thứ nhất (bên trái) từ stack 'values' (pop ra trước)
        values.pop();           // Loại bỏ toán hạng thứ nhất vừa lấy ra khỏi stack

        switch (op) { // Thực hiện phép toán dựa trên toán tử 'op'
            case '+': values.push(val1 + val2); break; // Cộng: val1 + val2
            case '-': values.push(val1 - val2); break; // Trừ: val1 - val2
            case '*': values.push(val1 * val2); break; // Nhân: val1 * val2
            case '/': values.push(val1 / val2); break; // Chia nguyên: val1 / val2
        }
    }

    return values.top(); // Kết quả cuối cùng của biểu thức trung tố nằm trên đỉnh stack 'values'
}

int main() {
    int t; // Biến 't' để lưu số lượng bộ test (test cases)
    cin >> t; // Đọc số lượng bộ test từ dòng đầu tiên của input
    cin.ignore(); // Đọc bỏ ký tự dòng mới (newline) còn sót lại sau khi đọc số 't', tránh ảnh hưởng đến việc đọc dòng tiếp theo

    while (t--) { // Vòng lặp 'while' chạy 't' lần, cho mỗi test case
        string infixExpression; // Biến 'infixExpression' để lưu biểu thức trung tố đầu vào cho mỗi test case
        getline(cin, infixExpression); // Đọc cả dòng biểu thức trung tố từ input, có thể chứa khoảng trắng và dấu ngoặc

        int result = evaluateInfix(infixExpression); // Gọi hàm 'evaluateInfix' để tính giá trị của biểu thức trung tố
        cout << result << endl; // In giá trị kết quả ra output, sau đó xuống dòng để chuẩn bị cho test case tiếp theo
    }

    return 0; // Chương trình kết thúc thành công, trả về giá trị 0 cho hệ điều hành
}