#include <iostream> // Thư viện nhập/xuất chuẩn
#include <string>   // Thư viện làm việc với chuỗi
#include <vector>   // Thư viện vector (mảng động)

using namespace std;

// Hàm giải biểu thức bằng cách loại bỏ dấu ngoặc (giống như bài trước)
// Tham số:
// - expression: Biểu thức đầu vào (string)
// - sign_multiplier: Hệ số nhân dấu, để xử lý dấu '-' phía trước ngoặc (int, 1 hoặc -1)
string solve_expression(const string& expression, int sign_multiplier);

string solve_expression(const string& expression, int sign_multiplier) {
    string output_expression = ""; // Chuỗi kết quả sau khi loại bỏ dấu ngoặc
    for (int i = 0; i < expression.length(); ++i) {
        char char_at_i = expression[i];
        if (isalpha(char_at_i)) {
            // Nếu là toán hạng (ký tự chữ cái), thêm trực tiếp vào kết quả
            output_expression += char_at_i;
        } else if (char_at_i == '+') {
            // Nếu là dấu '+', thêm '+' hoặc '-' tùy thuộc vào sign_multiplier
            output_expression += (sign_multiplier == 1 ? '+' : '-');
        } else if (char_at_i == '-') {
            // Nếu là dấu '-', thêm '-' hoặc '+' tùy thuộc vào sign_multiplier
            output_expression += (sign_multiplier == 1 ? '-' : '+');
        } else if (char_at_i == '(') {
            // Nếu là dấu '(', xử lý biểu thức con bên trong ngoặc đệ quy
            int start_index = i; // Vị trí bắt đầu dấu '('
            int balance = 1;     // Biến đếm cặp ngoặc, bắt đầu là 1 vì đã gặp dấu '(' đầu tiên
            i++;                 // Duyệt từ ký tự sau dấu '('
            while (balance > 0) {
                if (expression[i] == '(') balance++; // Nếu gặp '(' nữa, tăng biến đếm
                else if (expression[i] == ')') balance--; // Nếu gặp ')', giảm biến đếm
                i++;                                    // Tiếp tục duyệt cho đến khi tìm được ')' đóng cặp với '(' ban đầu
            }
            int end_index = i - 1; // Vị trí dấu ')' đóng ngoặc
            string substring_inside = expression.substr(start_index + 1, end_index - start_index - 1); // Lấy phần biểu thức bên trong ngoặc
            string inner_result = solve_expression(substring_inside, -sign_multiplier); // Gọi đệ quy để giải biểu thức con, đảo dấu (nhân -sign_multiplier)
            output_expression += inner_result; // Thêm kết quả của biểu thức con vào chuỗi kết quả
            i--; // Điều chỉnh lại i để vòng lặp for tiếp tục từ vị trí đúng (sau dấu ')')
        } else if (char_at_i == ')') {
            // Dấu ')' không cần xử lý trực tiếp ở mức này, đã được xử lý trong phần '('
        }
    }
    return output_expression;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Đọc bỏ dòng thừa sau khi đọc số test (số lượng test case)

    while (t--) {
        string p1, p2;
        getline(cin, p1); // Đọc dòng biểu thức P1 từ input
        getline(cin, p2); // Đọc dòng biểu thức P2 từ input

        string solved_p1 = solve_expression(p1, 1); // Giải biểu thức P1 bằng hàm solve_expression, hệ số dấu ban đầu là 1
        string solved_p2 = solve_expression(p2, 1); // Giải biểu thức P2, hệ số dấu ban đầu là 1

        if (solved_p1 == solved_p2) {
            cout << "YES" << endl; // So sánh 2 biểu thức đã được giải, nếu giống nhau in "YES"
        } else {
            cout << "NO" << endl;  // Nếu khác nhau, in "NO"
        }
    }

    return 0; // Kết thúc chương trình
}