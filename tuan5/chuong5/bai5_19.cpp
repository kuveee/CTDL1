#include <iostream> // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <vector>   // Thư viện để sử dụng vector, là mảng động
#include <string>   // Thư viện để sử dụng kiểu dữ liệu chuỗi

using namespace std;

int main() {
    int t;          // Biến t để lưu số lượng bộ test
    cin >> t;       // Đọc số lượng bộ test từ đầu vào

    while (t--) {  // Vòng lặp để xử lý từng bộ test
        int n;      // Biến n để lưu số ngày giao dịch chứng khoán
        cin >> n;   // Đọc số ngày từ đầu vào
        vector<int> a(n); // Vector a để lưu giá chứng khoán của n ngày
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Đọc giá chứng khoán của từng ngày vào vector a
        }

        string result_str = ""; // Chuỗi result_str để lưu kết quả nhịp chứng khoán, ban đầu là chuỗi rỗng

        for (int i = 0; i < n; i++) { // Vòng lặp duyệt qua từng ngày, từ ngày thứ 1 (index 0) đến ngày thứ n (index n-1)
            int pulse_count = 1;    // Khởi tạo biến pulse_count là 1, vì nhịp chứng khoán ít nhất là 1 (tính cho ngày hiện tại)

            // Vòng lặp duyệt ngược về các ngày trước ngày thứ i để tính nhịp chứng khoán
            for (int j = i - 1; j >= 0; j--) {
                // Kiểm tra xem giá chứng khoán của ngày j (ngày trước ngày i) có bé hơn hoặc bằng giá chứng khoán ngày i không
                if (a[j] <= a[i]) {
                    pulse_count++; // Nếu giá ngày j bé hơn hoặc bằng ngày i, thì tăng biến đếm nhịp chứng khoán lên
                } else {
                    break;      // Nếu giá ngày j lớn hơn ngày i, thì dãy ngày liên tiếp bé hơn hoặc bằng bị ngắt, nên dừng vòng lặp duyệt ngược
                }
            }
            result_str += to_string(pulse_count); // Chuyển đổi nhịp chứng khoán (pulse_count) sang chuỗi và thêm vào chuỗi kết quả result_str (ví dụ: 1, 2, 4, 6...)
        }
        cout << result_str << endl; // In ra chuỗi kết quả nhịp chứng khoán cho từng ngày của bộ test hiện tại, sau đó xuống dòng
    }
    return 0; // Chương trình kết thúc thành công
}