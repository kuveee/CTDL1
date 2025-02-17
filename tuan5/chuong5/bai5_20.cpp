#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <cctype>       // Thư viện chứa các hàm kiểm tra kiểu ký tự, ở đây dùng `isdigit` (kiểm tra chữ số)

using namespace std;

// Hàm giải mã xâu ký tự mã hóa theo định dạng đặc biệt
// Input: string s - xâu ký tự đã mã hóa
// Output: string - xâu ký tự đã được giải mã
string decodeString(string s) {
    stack<int> counts;       // Stack 'counts' để lưu trữ các số lần lặp lại (ví dụ số '3' trong '3[...')
    stack<string> strs;      // Stack 'strs' để lưu trữ các chuỗi đã được giải mã trước đó, phục vụ cho việc xử lý ngoặc lồng nhau
    string res = "";         // Chuỗi 'res' là chuỗi kết quả giải mã đang được xây dựng, ban đầu là chuỗi rỗng

    // Duyệt qua từng ký tự trong xâu mã hóa 's'
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) { // **Xử lý chữ số (số lần lặp):** Nếu ký tự hiện tại là một chữ số (0-9)
            int count = 0;      // Biến 'count' để tích lũy giá trị số lần lặp, khởi tạo là 0
            // Đọc toàn bộ số có thể gồm nhiều chữ số (ví dụ số '123' có 3 chữ số)
            while (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0'); // Ví dụ: nếu gặp chữ số '2', count = count * 10 + 2;
                i++;                             // Tăng index 'i' để tiếp tục đọc các chữ số tiếp theo của số lặp
            }
            i--; // **Quan trọng:** Vì vòng lặp 'for' sẽ tự tăng 'i' thêm 1 sau mỗi lần lặp,
                 // nên cần giảm 'i' đi 1 để khi vòng lặp 'for' tiếp theo bắt đầu, 'i' sẽ trỏ đến ký tự **ngay sau** số vừa đọc.
            counts.push(count); // Sau khi đọc xong số lặp, đẩy giá trị 'count' vào stack 'counts'
        } else if (s[i] == '[') { // **Xử lý ngoặc mở '[':** Nếu ký tự hiện tại là ngoặc mở '['
            strs.push(res);     // Đẩy chuỗi kết quả hiện tại 'res' vào stack 'strs'.
                                 // Mục đích: Lưu lại trạng thái chuỗi trước khi bắt đầu giải mã chuỗi con bên trong cặp ngoặc.
            res = "";           // Reset chuỗi kết quả 'res' về chuỗi rỗng.
                                 // Chuẩn bị để xây dựng chuỗi con được giải mã bên trong cặp ngoặc '[' và ']'.
        } else if (s[i] == ']') { // **Xử lý ngoặc đóng ']':** Nếu ký tự hiện tại là ngoặc đóng ']'
            string prev_str = strs.top(); // Lấy chuỗi đã được giải mã trước đó (trước khi gặp ngoặc mở '[') từ đỉnh stack 'strs'.
            strs.pop();                   // Loại bỏ chuỗi đã lưu khỏi stack 'strs'.
            int repeat_count = counts.top(); // Lấy số lần lặp lại tương ứng với cặp ngoặc hiện tại từ đỉnh stack 'counts'.
            counts.pop();                     // Loại bỏ số lần lặp khỏi stack 'counts'.
            string temp_str = "";           // Khởi tạo chuỗi tạm 'temp_str' để chứa chuỗi con được lặp lại.
            // Lặp lại chuỗi 'res' (chuỗi vừa được giải mã bên trong cặp ngoặc) 'repeat_count' lần.
            for (int j = 0; j < repeat_count; j++) {
                temp_str += res;          // Nối chuỗi 'res' vào 'temp_str' 'repeat_count' lần.
            }
            res = prev_str + temp_str; // Nối chuỗi đã giải mã trước đó 'prev_str' với chuỗi đã lặp lại 'temp_str'.
                                     // Kết quả này trở thành chuỗi 'res' hiện tại, tiếp tục được xây dựng.
        } else { // **Xử lý ký tự chữ cái:** Nếu ký tự hiện tại là một chữ cái (a-z, A-Z)
            res += s[i];             // Đơn giản là thêm ký tự đó vào chuỗi kết quả 'res' hiện tại.
        }
    }
    return res; // Sau khi duyệt hết xâu mã hóa 's', trả về chuỗi kết quả giải mã cuối cùng 'res'.
}

int main() {
    int t;          // Biến 't' để lưu số lượng bộ test
    cin >> t;       // Đọc số lượng bộ test từ input
    while (t--) {  // Vòng lặp 'while' chạy 't' lần, mỗi lần xử lý một bộ test
        string encoded_str; // Biến 'encoded_str' để lưu xâu mã hóa đầu vào cho mỗi test case
        cin >> encoded_str; // Đọc xâu mã hóa từ input
        // Gọi hàm 'decodeString' để giải mã xâu 'encoded_str' và in kết quả ra output.
        cout << decodeString(encoded_str) << endl; // 'endl' để xuống dòng sau khi in kết quả mỗi test case
    }
    return 0; // Chương trình kết thúc thành công, trả về 0 cho hệ điều hành
}