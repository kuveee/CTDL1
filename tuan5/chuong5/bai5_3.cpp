#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm đệ quy để giải quyết biểu thức, loại bỏ dấu ngoặc
// Tham số:
// - expression: biểu thức cần xử lý (string)
// - sign_multiplier: hệ số nhân dấu, để theo dõi việc đảo dấu do dấu ngoặc '-' phía trước (int, 1 hoặc -1)
string solve_expression(const string& expression, int sign_multiplier);

string solve_expression(const string& expression, int sign_multiplier) {
    string output_expression = ""; // Chuỗi kết quả sau khi loại bỏ ngoặc
    for (int i = 0; i < expression.length(); ++i) {
        char char_at_i = expression[i];
        if (isalpha(char_at_i)) {
            // Nếu là toán hạng (ký tự chữ cái), thêm trực tiếp vào kết quả
            output_expression += char_at_i;
        } else if (char_at_i == '+') {
            // Nếu là dấu '+', thêm '+' hoặc '-' vào kết quả tùy thuộc vào sign_multiplier
            output_expression += (sign_multiplier == 1 ? '+' : '-');
        } else if (char_at_i == '-') {
            // Nếu là dấu '-', thêm '-' hoặc '+' vào kết quả tùy thuộc vào sign_multiplier
            output_expression += (sign_multiplier == 1 ? '-' : '+');
        } else if (char_at_i == '(') {
            // Nếu là dấu '(', bắt đầu xử lý biểu thức con bên trong ngoặc
            int start_index = i; // Vị trí bắt đầu dấu '('
            int balance = 1; // Biến đếm để tìm dấu ')' đóng ngoặc tương ứng
            i++; // Bắt đầu từ vị trí sau dấu '('
            while (balance > 0) {
                if (expression[i] == '(') balance++; // Nếu gặp '(' nữa, tăng balance
                else if (expression[i] == ')') balance--; // Nếu gặp ')', giảm balance
                i++; // Tiếp tục duyệt
            }
            int end_index = i - 1; // Vị trí dấu ')' đóng ngoặc
            string substring_inside = expression.substr(start_index + 1, end_index - start_index - 1); // Lấy chuỗi con bên trong ngoặc
            string inner_result = solve_expression(substring_inside, -sign_multiplier); // Gọi đệ quy để xử lý biểu thức con, đảo ngược sign_multiplier
            output_expression += inner_result; // Thêm kết quả của biểu thức con vào kết quả chung
            i--; // Điều chỉnh i để vòng lặp for tiếp tục đúng vị trí sau dấu ')' đã xử lý
        } else if (char_at_i == ')') {
            // Dấu ')' không được xử lý trực tiếp ở mức này trong đệ quy
        }
    }
    return output_expression;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Đọc bỏ dòng thừa sau khi đọc số test (ví dụ số lượng test case và dòng new line)
    while (t--) {
        string p;
        getline(cin, p); // Đọc cả dòng biểu thức đầu vào cho mỗi test case
        cout << solve_expression(p, 1) << endl; // Gọi hàm giải biểu thức với hệ số dấu ban đầu là 1 và in ra kết quả
    }
    return 0;
}