#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <vector>       // Thư viện cho container vector (mảng động)
#include <stack>        // Thư viện cho cấu trúc dữ liệu stack (ngăn xếp)

using namespace std;

// Hàm kiểm tra xem một chuỗi có phải là dãy ngoặc đúng hay không
// Input: string s - chuỗi cần kiểm tra
// Output: bool - true nếu là dãy ngoặc đúng, false nếu không
bool isCorrectBracketSequence(string s) {
    stack<char> st;     // Khởi tạo một stack để theo dõi ngoặc mở

    for (char c : s) {  // Duyệt qua từng ký tự trong chuỗi s
        if (c == '(') { // Nếu ký tự là ngoặc mở
            st.push(c); // Đẩy ngoặc mở vào stack
        } else if (c == ')') { // Nếu ký tự là ngoặc đóng
            if (st.empty()) { // Kiểm tra stack có rỗng không
                return false; // Nếu rỗng, nghĩa là không có ngoặc mở tương ứng, trả về false (không đúng)
            }
            st.pop();       // Nếu không rỗng, pop (lấy ra) một ngoặc mở từ stack (tìm thấy cặp ngoặc hợp lệ)
        }
    }
    return st.empty();    // Sau khi duyệt xong chuỗi, nếu stack rỗng, nghĩa là tất cả ngoặc mở đều có ngoặc đóng tương ứng, trả về true (dãy ngoặc đúng)
}

int main() {
    int t;              // Biến t để lưu số lượng bộ test
    cin >> t;           // Đọc số lượng bộ test từ đầu vào

    while (t--) {      // Vòng lặp chạy t lần để xử lý từng bộ test
        string p;       // Biến p để lưu biểu thức ngoặc đầu vào
        cin >> p;       // Đọc biểu thức ngoặc từ đầu vào
        int total_length = 0; // Biến total_length để tính tổng độ dài các biểu thức con đúng, khởi tạo bằng 0
        int n = p.length();   // Lấy độ dài của biểu thức p

        for (int i = 0; i < n; ++i) {     // Vòng lặp ngoài để chọn vị trí bắt đầu của chuỗi con (từ index 0 đến n-1)
            for (int j = i; j < n; ++j) { // Vòng lặp trong để chọn vị trí kết thúc của chuỗi con (từ index i đến n-1)
                string sub = p.substr(i, j - i + 1); // Tạo chuỗi con 'sub' từ biểu thức p, bắt đầu từ index i và kết thúc ở index j
                if (sub.length() >= 2 && isCorrectBracketSequence(sub)) { // Kiểm tra 2 điều kiện:
                    // 1. Độ dài chuỗi con phải ít nhất là 2 (theo yêu cầu đề bài)
                    // 2. Chuỗi con 'sub' phải là một dãy ngoặc đúng (sử dụng hàm isCorrectBracketSequence)
                    total_length += sub.length(); // Nếu cả hai điều kiện đều đúng, cộng độ dài của chuỗi con vào tổng độ dài
                }
            }
        }
        cout << total_length << endl; // In ra tổng độ dài của tất cả các biểu thức con viết đúng cho bộ test hiện tại
    }
    return 0; // Chương trình kết thúc thành công
}