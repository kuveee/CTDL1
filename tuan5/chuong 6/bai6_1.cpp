#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản như cin và cout
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <vector>       // Thư viện cho container vector (mảng động), tuy không dùng trực tiếp ở đây nhưng thường được include trong C++
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây dùng `reverse` (tùy chọn, không bắt buộc cho bài này)

using namespace std;    // Sử dụng không gian tên std để không cần viết std:: phía trước các thành phần của thư viện chuẩn

// Hàm chuyển đổi một số thập phân dương sang dạng nhị phân (string)
// Input: int n - số thập phân dương cần chuyển đổi
// Output: string - chuỗi nhị phân tương ứng với số n
string decimalToBinary(int n) {
    string binaryString = ""; // Khai báo một chuỗi rỗng 'binaryString' để lưu kết quả là dạng nhị phân.

    if (n == 0) {
        return "0"; // Trường hợp đặc biệt: nếu số đầu vào là 0, trả về chuỗi "0" (dạng nhị phân của 0)
                     // Thực tế theo đề bài là số tự nhiên từ 1, nhưng thêm trường hợp này cho đầy đủ.
    }

    // Vòng lặp while để thực hiện chuyển đổi từ thập phân sang nhị phân
    while (n > 0) {
        int remainder = n % 2;          // Tính phần dư khi n chia cho 2. Phần dư này (0 hoặc 1) là bit cuối cùng của dạng nhị phân.
        binaryString = to_string(remainder) + binaryString; // Chuyển phần dư thành chuỗi và **thêm vào ĐẦU** của chuỗi 'binaryString'.
                                                           // Vì chúng ta lấy bit từ cuối lên đầu, nên cần thêm vào đầu chuỗi để có thứ tự bit đúng.
        n /= 2;                             // Chia n cho 2 (chia nguyên) để tiếp tục xét các bit tiếp theo (dịch sang phải trong hệ nhị phân).
    }

    return binaryString; // Sau khi vòng lặp kết thúc (n trở thành 0), chuỗi 'binaryString' chứa dạng nhị phân của số đầu vào.
}

int main() {
    int t;              // Khai báo biến 't' kiểu int để lưu số lượng test case.
    cin >> t;           // Đọc giá trị số lượng test case từ input và lưu vào biến 't'.

    while (t--) {      // Vòng lặp while này sẽ thực hiện 't' lần, mỗi lần xử lý một test case. 't--' vừa kiểm tra điều kiện vừa giảm giá trị 't' sau mỗi lần lặp.
        int n;          // Khai báo biến 'n' kiểu int để lưu số tự nhiên đầu vào cho mỗi test case.
        cin >> n;       // Đọc số tự nhiên 'n' từ input cho test case hiện tại và lưu vào biến 'n'.

        // Vòng lặp for để in ra các số nhị phân từ 1 đến n
        for (int i = 1; i <= n; ++i) {
            cout << decimalToBinary(i) << " "; // Gọi hàm 'decimalToBinary' để chuyển đổi số 'i' sang dạng nhị phân.
                                                // Sau đó in chuỗi nhị phân này ra console, theo sau là một dấu cách ( " " ) để phân tách các số nhị phân.
        }
        cout << endl;      // Sau khi in xong tất cả các số nhị phân từ 1 đến n cho test case hiện tại, in một ký tự xuống dòng (newline) để kết thúc dòng output cho test case này
                           // và chuẩn bị cho output của test case tiếp theo (nếu có).
    }

    return 0;             // Hàm main trả về 0, báo hiệu chương trình kết thúc thành công.
}