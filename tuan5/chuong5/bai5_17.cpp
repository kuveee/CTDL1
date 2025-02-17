#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây dùng `max` để tìm giá trị lớn nhất

using namespace std;

// Hàm kiểm tra xem một chuỗi có phải là dãy ngoặc đúng hay không
// Input: string s - chuỗi cần kiểm tra
// Output: bool - true nếu là dãy ngoặc đúng, false nếu không phải
bool isCorrectBracketSequence(string s) {
    stack<char> st; // Khai báo một stack tên là 'st' để kiểm tra cặp ngoặc.
                     // Stack này sẽ chứa các ngoặc mở '('.

    // Duyệt qua từng ký tự 'c' trong chuỗi 's'
    for (char c : s) {
        if (c == '(') {
            st.push(c); // Nếu ký tự 'c' là ngoặc mở '(', đẩy nó vào stack 'st'.
                         // Ý tưởng: khi gặp ngoặc mở, ta "ghi nhớ" nó trong stack.
        } else if (c == ')') {
            // Nếu ký tự 'c' là ngoặc đóng ')', ta cần kiểm tra xem có ngoặc mở tương ứng trước đó không.
            if (st.empty()) {
                // Nếu stack rỗng khi gặp ngoặc đóng, nghĩa là không có ngoặc mở nào để "khớp cặp" với ngoặc đóng này.
                // Do đó, chuỗi không phải là dãy ngoặc đúng.
                return false; // Trả về false ngay lập tức.
            }
            st.pop(); // Nếu stack không rỗng, lấy ra (pop) một ngoặc mở từ đỉnh stack.
                      // Hành động này tượng trưng cho việc tìm thấy một cặp ngoặc hợp lệ '()'.
        }
        // Nếu ký tự 'c' không phải '(' hoặc ')', chúng ta bỏ qua nó (theo đề bài, xâu chỉ gồm '(' và ')').
    }

    // Sau khi duyệt hết chuỗi 's', một dãy ngoặc là đúng khi và chỉ khi stack rỗng.
    // Stack rỗng có nghĩa là tất cả các ngoặc mở đều đã được "khớp cặp" với ngoặc đóng tương ứng.
    return st.empty(); // Trả về true nếu stack rỗng (dãy ngoặc đúng), false nếu không rỗng (dãy ngoặc không đúng).
}

// Hàm tìm độ dài dãy ngoặc đúng dài nhất xuất hiện trong xâu s
// Input: string s - xâu đầu vào
// Output: int - độ dài của dãy ngoặc đúng dài nhất tìm được
int findLongestCorrectBracketSequence(string s) {
    int n = s.length(); // Lấy độ dài của xâu 's'
    int maxLen = 0;     // Khởi tạo biến 'maxLen' để lưu độ dài lớn nhất của dãy ngoặc đúng tìm được, ban đầu là 0.

    // Duyệt qua tất cả các chuỗi con (substring) của xâu 's'.
    // Vòng lặp ngoài với 'i' chạy từ 0 đến n-1, xác định vị trí bắt đầu của chuỗi con.
    for (int i = 0; i < n; ++i) {
        // Vòng lặp trong với 'j' chạy từ 'i' đến n-1, xác định vị trí kết thúc của chuỗi con.
        for (int j = i; j < n; ++j) {
            string sub = s.substr(i, j - i + 1); // Trích xuất chuỗi con 'sub' từ xâu 's', bắt đầu từ index 'i', có độ dài 'j - i + 1'.
                                                   // Ví dụ: nếu s = "(()))", i = 1, j = 4, thì sub = "())".
            if (isCorrectBracketSequence(sub)) { // Gọi hàm 'isCorrectBracketSequence' để kiểm tra xem chuỗi con 'sub' có phải là dãy ngoặc đúng hay không.
                maxLen = max(maxLen, (int)sub.length()); // Nếu 'sub' là dãy ngoặc đúng, so sánh độ dài của nó với độ dài lớn nhất 'maxLen' đã tìm được.
                                                         // Hàm 'max' trả về giá trị lớn hơn trong hai giá trị.
                                                         // Cập nhật 'maxLen' nếu 'sub' dài hơn 'maxLen' hiện tại.
            }
        }
    }
    return maxLen; // Sau khi duyệt qua tất cả các chuỗi con, trả về giá trị 'maxLen' - độ dài lớn nhất của dãy ngoặc đúng tìm được.
}

int main() {
    int t; // Biến 't' để lưu số lượng test case
    cin >> t; // Đọc số lượng test case từ input
    while (t--) { // Vòng lặp 'while' chạy 't' lần, mỗi lần xử lý một test case
        string s; // Biến 's' để lưu xâu đầu vào cho mỗi test case
        cin >> s; // Đọc xâu 's' từ input
        // Gọi hàm 'findLongestCorrectBracketSequence' để tìm độ dài dãy ngoặc đúng dài nhất trong xâu 's'
        // và in kết quả ra output.
        cout << findLongestCorrectBracketSequence(s) << endl; // 'endl' để xuống dòng sau khi in kết quả mỗi test case
    }
    return 0; // Chương trình kết thúc thành công, trả về 0 cho hệ điều hành
}