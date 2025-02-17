#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <cctype>       // Thư viện chứa các hàm kiểm tra kiểu ký tự, ở đây dùng `isdigit` (is digit - kiểm tra chữ số)

using namespace std;

// Hàm tính giá trị của biểu thức hậu tố (postfix)
int evaluatePostfix(string postfix) {
    stack<int> values; // Khai báo một stack có tên là 'values' để lưu trữ các giá trị số trong quá trình tính toán.
                        // Stack này sẽ chứa các số nguyên (int).

    // Duyệt qua từng ký tự 'c' trong chuỗi biểu thức hậu tố 'postfix' (từ trái sang phải, theo thứ tự thông thường của hậu tố)
    for (char c : postfix) {
        if (isdigit(c)) { // Kiểm tra xem ký tự 'c' có phải là chữ số (0-9) hay không bằng hàm `isdigit`
            values.push(c - '0'); // Nếu là chữ số, chuyển đổi ký tự chữ số sang giá trị số nguyên tương ứng
                                  // bằng cách trừ đi mã ASCII của ký tự '0' ('c' - '0'). Sau đó đẩy giá trị số nguyên này vào stack 'values'.
        } else { // Nếu ký tự 'c' không phải là chữ số, thì nó phải là một toán tử (+, -, *, /) theo đề bài
            // **Lấy toán hạng từ stack:** Để thực hiện phép toán (ví dụ '+', '-', '*', '/'), chúng ta cần 2 toán hạng.
            if (values.size() < 2) {
                // **Xử lý lỗi:** Nếu không đủ 2 giá trị số trong stack khi gặp toán tử, có nghĩa là biểu thức hậu tố không hợp lệ.
                return -99999; // Trả về một giá trị lỗi đặc biệt (ví dụ -99999) để báo hiệu biểu thức không hợp lệ.
                                 // Trong thực tế, có thể throw exception hoặc xử lý lỗi theo cách khác phù hợp hơn.
            }
            int val2 = values.top(); // Lấy giá trị số trên đỉnh stack ra (giá trị thứ hai được pop ra, tương ứng là toán hạng bên phải của toán tử trong biểu thức trung tố)
            values.pop();             // Loại bỏ giá trị số thứ hai khỏi stack
            int val1 = values.top(); // Lấy giá trị số tiếp theo trên đỉnh stack ra (giá trị thứ nhất được pop ra, tương ứng là toán hạng bên trái của toán tử trong biểu thức trung tố)
            values.pop();             // Loại bỏ giá trị số thứ nhất khỏi stack

            switch (c) { // Sử dụng switch-case để xác định toán tử và thực hiện phép toán tương ứng
                case '+': values.push(val1 + val2); break; // Nếu toán tử là '+', thực hiện phép cộng val1 + val2 và đẩy kết quả vào stack 'values'
                case '-': values.push(val1 - val2); break; // Nếu toán tử là '-', thực hiện phép trừ val1 - val2 và đẩy kết quả vào stack 'values'
                case '*': values.push(val1 * val2); break; // Nếu toán tử là '*', thực hiện phép nhân val1 * val2 và đẩy kết quả vào stack 'values'
                case '/': values.push(val1 / val2); break; // Nếu toán tử là '/', thực hiện phép chia nguyên val1 / val2 và đẩy kết quả vào stack 'values'
                // Bạn có thể thêm các case khác nếu biểu thức hậu tố có thêm toán tử (ví dụ '^' cho lũy thừa, '%' cho modulo, ...)
            }
        }
    }

    // **Kiểm tra kết quả:** Sau khi duyệt hết biểu thức hậu tố, nếu biểu thức hợp lệ thì stack 'values' phải chứa đúng 1 giá trị duy nhất, đó là kết quả cuối cùng của biểu thức.
    if (values.size() == 1) {
        return values.top(); // Trả về giá trị kết quả cuối cùng (lấy từ đỉnh stack)
    } else {
        // **Xử lý lỗi:** Nếu stack 'values' không chứa đúng 1 phần tử sau khi duyệt hết biểu thức, có nghĩa là biểu thức hậu tố đầu vào không hợp lệ (ví dụ thừa toán hạng hoặc toán tử).
        return -99999; // Trả về giá trị lỗi đặc biệt (ví dụ -99999) để báo hiệu biểu thức không hợp lệ.
                         // Trong thực tế, có thể throw exception hoặc xử lý lỗi theo cách khác phù hợp hơn.
    }
}

int main() {
    int t; // Biến 't' để lưu số lượng bộ test (test cases)
    cin >> t; // Đọc số lượng bộ test từ dòng đầu tiên của input
    cin.ignore(); // Đọc và bỏ qua ký tự dòng mới (newline) còn sót lại sau khi đọc số 't', tránh ảnh hưởng đến việc đọc dòng tiếp theo

    while (t--) { // Vòng lặp 'while' chạy 't' lần, xử lý từng bộ test
        string postfixExpression; // Biến 'postfixExpression' để lưu biểu thức hậu tố đầu vào cho mỗi bộ test
        getline(cin, postfixExpression); // Đọc cả dòng chứa biểu thức hậu tố từ input (ví dụ: "231*+")

        int result = evaluatePostfix(postfixExpression); // Gọi hàm 'evaluatePostfix' để tính giá trị của biểu thức hậu tố
        cout << result << endl; // In ra giá trị kết quả (phần nguyên) ra output, sau đó xuống dòng cho bộ test tiếp theo
    }

    return 0; // Chương trình kết thúc thành công, trả về giá trị 0 cho hệ điều hành
}