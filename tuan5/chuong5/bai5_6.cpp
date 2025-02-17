#include <iostream> // Thư viện nhập/xuất chuẩn
#include <string>   // Thư viện làm việc với chuỗi
#include <stack>    // Thư viện stack (ngăn xếp) để quản lý toán tử
#include <cctype>   // Thư viện cctype để sử dụng hàm isalnum (kiểm tra chữ và số)

using namespace std;

// Hàm xác định độ ưu tiên của toán tử
// Độ ưu tiên càng cao, giá trị trả về càng lớn
int precedence(char op) {
    if (op == '^') return 3; // Toán tử lũy thừa '^' có độ ưu tiên cao nhất
    if (op == '*' || op == '/') return 2; // Toán tử nhân '*' và chia '/' có độ ưu tiên trung bình
    if (op == '+' || op == '-') return 1; // Toán tử cộng '+' và trừ '-' có độ ưu tiên thấp nhất
    return 0; // Các trường hợp khác (như dấu ngoặc '(' hoặc toán hạng) có độ ưu tiên thấp nhất
}

// Hàm chuyển đổi biểu thức trung tố (infix) sang biểu thức hậu tố (postfix)
string infixToPostfix(string infix) {
    string postfix = "";      // Chuỗi kết quả biểu thức hậu tố (khởi tạo rỗng)
    stack<char> operators;   // Stack để tạm thời chứa các toán tử trong quá trình chuyển đổi

    // Duyệt qua từng ký tự trong biểu thức trung tố đầu vào
    for (char c : infix) {
        if (isalnum(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ hoặc số (toán hạng) hay không
            postfix += c;   // Nếu là toán hạng, thêm trực tiếp vào chuỗi kết quả hậu tố
        } else if (c == '(') {
            operators.push('('); // Nếu là dấu ngoặc mở '(', đẩy vào stack toán tử
        } else if (c == ')') {
            // Nếu là dấu ngoặc đóng ')', thực hiện các bước sau:
            // Lặp khi stack không rỗng VÀ phần tử trên đỉnh stack không phải dấu ngoặc mở '('
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top(); // Lấy toán tử từ đỉnh stack và thêm vào chuỗi hậu tố
                operators.pop();         // Loại bỏ toán tử vừa lấy ra khỏi stack
            }
            operators.pop(); // Sau khi vòng lặp kết thúc (gặp dấu '(' hoặc stack rỗng), loại bỏ dấu ngoặc mở '(' ra khỏi stack, nhưng KHÔNG thêm vào chuỗi hậu tố
        } else { // Trường hợp còn lại: ký tự 'c' là một toán tử (+, -, *, /, ^)
            // Lặp khi stack không rỗng VÀ toán tử trên đỉnh stack có độ ưu tiên lớn hơn hoặc bằng độ ưu tiên của toán tử hiện tại 'c'
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top(); // Lấy toán tử từ đỉnh stack và thêm vào chuỗi hậu tố
                operators.pop();         // Loại bỏ toán tử vừa lấy ra khỏi stack
            }
            operators.push(c); // Sau khi vòng lặp kết thúc (stack rỗng hoặc gặp toán tử có độ ưu tiên thấp hơn), đẩy toán tử hiện tại 'c' vào stack
        }
    }

    // Sau khi duyệt hết biểu thức trung tố, vẫn có thể còn toán tử trong stack
    // Lấy hết các toán tử còn lại từ stack và thêm vào chuỗi hậu tố
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix; // Trả về chuỗi biểu thức hậu tố đã được tạo thành
}

int main() {
    int t; // Biến lưu số lượng test case
    cin >> t; // Đọc số lượng test case từ input
    cin.ignore(); // Đọc bỏ ký tự dòng mới (newline) còn sót lại sau khi đọc số 't'

    while (t--) { // Vòng lặp chạy 't' lần, cho mỗi test case
        string infixExpression; // Biến lưu biểu thức trung tố đầu vào cho mỗi test case
        getline(cin, infixExpression); // Đọc cả dòng biểu thức trung tố từ input, có thể chứa khoảng trắng (nhưng trong bài này ví dụ không có khoảng trắng)

        string postfixExpression = infixToPostfix(infixExpression); // Gọi hàm infixToPostfix để chuyển đổi biểu thức trung tố sang hậu tố
        cout << postfixExpression << endl; // In biểu thức hậu tố đã chuyển đổi ra output, kèm theo ký tự dòng mới
    }

    return 0; // Kết thúc chương trình thành công
}