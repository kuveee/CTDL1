#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản (cin, cout)
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <set>          // Thư viện cung cấp cấu trúc dữ liệu set (tập hợp), dùng để kiểm tra tính duy nhất của các chữ số

using namespace std;     // Sử dụng không gian tên std để không cần viết std:: phía trước các thành phần của thư viện chuẩn

// Hàm kiểm tra xem một số nguyên 'n' có thỏa mãn cả hai điều kiện của bài toán hay không
// Input: int n - Số nguyên cần kiểm tra
// Output: bool - true nếu số 'n' thỏa mãn cả hai điều kiện, false nếu không
bool is_valid(int n) {
    string s = to_string(n); // **Bước 1: Chuyển số thành chuỗi:** Chuyển đổi số nguyên 'n' thành một chuỗi các ký tự (string) 's'.
                                 // Mục đích là để dễ dàng duyệt qua từng chữ số của số đó.
    set<char> digits;      // **Bước 2: Khởi tạo set theo dõi chữ số:** Tạo một set (tập hợp) tên là 'digits' để lưu trữ các chữ số đã xuất hiện trong số 'n'.
                                 // Set được sử dụng vì nó chỉ lưu trữ các phần tử duy nhất, giúp ta dễ dàng kiểm tra xem một chữ số đã xuất hiện trước đó hay chưa.

    for (char c : s) {     // **Bước 3: Duyệt từng chữ số:** Vòng lặp for duyệt qua từng ký tự 'c' trong chuỗi 's' (tức là từng chữ số của số 'n').
        if (c > '5') {     // **Kiểm tra Điều kiện 2:**  "Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5."
            return false;    // Nếu phát hiện bất kỳ chữ số 'c' nào lớn hơn ký tự '5', tức là điều kiện 2 không thỏa mãn, hàm trả về 'false' (số không hợp lệ).
        }
        if (digits.count(c)) { // **Kiểm tra Điều kiện 1:** "Tất cả các chữ số của K đều khác nhau."
            return false;    // Sử dụng 'digits.count(c)' để kiểm tra xem chữ số 'c' đã tồn tại trong set 'digits' hay chưa.
                                 // Nếu 'digits.count(c)' trả về giá trị lớn hơn 0 (tức là chữ số 'c' đã có trong set),
                                 // điều đó có nghĩa là chữ số 'c' đã xuất hiện trước đó, và điều kiện 1 không thỏa mãn, hàm trả về 'false' (số không hợp lệ).
        }
        digits.insert(c);    // **Thêm chữ số vào set:** Nếu chữ số 'c' thỏa mãn cả hai điều kiện (nhỏ hơn hoặc bằng 5 và chưa xuất hiện trước đó),
                                 // thì thêm chữ số 'c' vào set 'digits' để đánh dấu là đã xuất hiện.
    }
    return true;             // **Bước 4: Trả về true nếu hợp lệ:** Nếu vòng lặp for hoàn thành mà không trả về 'false' ở bất kỳ bước nào,
                                 // điều đó có nghĩa là tất cả các chữ số của số 'n' đều thỏa mãn cả hai điều kiện của bài toán.
                                 // Hàm trả về 'true' (số hợp lệ).
}

int main() {
    int t;              // Biến 't' để lưu số lượng test cases.
    cin >> t;           // Đọc số lượng test cases từ input và lưu vào biến 't'.

    while (t--) {      // **Vòng lặp test cases:** Vòng lặp 'while' này sẽ thực hiện 't' lần, mỗi lần xử lý một test case.
        int l, r;       // Biến 'l' và 'r' để lưu giới hạn dưới L và giới hạn trên R của khoảng cần xét cho mỗi test case.
        cin >> l >> r;   // Đọc giá trị L và R từ input cho test case hiện tại và lưu vào biến 'l' và 'r'.

        int count = 0;  // **Khởi tạo biến đếm:** Biến 'count' được khởi tạo bằng 0 để đếm số lượng số K thỏa mãn điều kiện trong khoảng [L, R].
        // **Vòng lặp duyệt khoảng [L, R]:** Vòng lặp 'for' duyệt qua tất cả các số nguyên 'i' từ 'l' đến 'r' (bao gồm cả 'l' và 'r').
        for (int i = l; i <= r; ++i) {
            if (is_valid(i)) {      // **Kiểm tra số hợp lệ:** Gọi hàm 'is_valid(i)' để kiểm tra xem số 'i' có thỏa mãn cả hai điều kiện của bài toán hay không.
                count++;            // **Tăng biến đếm:** Nếu hàm 'is_valid(i)' trả về 'true' (số 'i' hợp lệ), thì tăng biến đếm 'count' lên 1.
            }
        }
        cout << count << endl; // **In kết quả:** Sau khi duyệt xong toàn bộ khoảng [L, R], in giá trị của biến 'count' ra console.
                                 // 'cout << endl' để in kết quả và xuống dòng, chuẩn bị cho output của test case tiếp theo (nếu có).
    }

    return 0;             // Hàm main trả về 0, báo hiệu chương trình kết thúc thành công.
}