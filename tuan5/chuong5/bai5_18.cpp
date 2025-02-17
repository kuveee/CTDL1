#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <vector>       // Thư viện để làm việc với vector (mảng động)
#include <unordered_map> // Thư viện để sử dụng unordered_map, một loại map băm cho tốc độ truy xuất trung bình nhanh

using namespace std;

int main() {
    int t;              // Biến t lưu số lượng bộ test
    cin >> t;           // Đọc số lượng bộ test từ đầu vào
    while (t--) {      // Vòng lặp chạy t lần, mỗi lần xử lý một bộ test
        int n;          // Biến n lưu số lượng phần tử của mảng
        cin >> n;       // Đọc số lượng phần tử của mảng từ đầu vào
        vector<int> a(n); // Khai báo vector 'a' có kích thước n để lưu mảng đầu vào
        unordered_map<int, int> frequencyMap; // Khai báo unordered_map 'frequencyMap' để lưu tần số xuất hiện của mỗi phần tử trong mảng.
                                               // Key của map là giá trị phần tử, Value là số lần xuất hiện.

        // **Đọc mảng và đếm tần số xuất hiện của mỗi phần tử**
        for (int i = 0; i < n; i++) {
            cin >> a[i];                // Đọc phần tử thứ i của mảng từ đầu vào
            frequencyMap[a[i]]++;       // Tăng tần số của phần tử a[i] trong frequencyMap.
                                         // Nếu a[i] chưa có trong map, nó sẽ được thêm vào với tần số 1.
        }

        vector<int> ans(n);         // Khai báo vector 'ans' có kích thước n để lưu kết quả cho mỗi phần tử của mảng đầu vào
        for (int i = 0; i < n; i++) {
            int result = -1;        // Khởi tạo 'result' là -1, đây là giá trị mặc định nếu không tìm thấy phần tử thỏa mãn
            int currentFrequency = frequencyMap[a[i]]; // Lấy tần số xuất hiện của phần tử a[i] từ frequencyMap và lưu vào 'currentFrequency'

            // **Tìm phần tử gần nhất bên phải có tần số xuất hiện lớn hơn**
            for (int j = i + 1; j < n; j++) {
                if (frequencyMap[a[j]] > currentFrequency) { // Kiểm tra nếu tần số của phần tử a[j] lớn hơn tần số của phần tử a[i]
                    result = a[j];      // Nếu thỏa mãn, gán a[j] cho 'result' (đây là phần tử gần nhất bên phải thỏa mãn điều kiện)
                    break;              // **Quan trọng:** Dừng vòng lặp ngay khi tìm thấy phần tử đầu tiên thỏa mãn vì đề bài yêu cầu "phần tử gần nhất"
                }
            }
            ans[i] = result;            // Lưu giá trị 'result' (phần tử thỏa mãn hoặc -1) vào vị trí thứ i của vector kết quả 'ans'
        }

        // **In kết quả**
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";     // In từng phần tử trong vector kết quả 'ans'
        }
        cout << endl;                   // In dấu xuống dòng sau khi in xong kết quả cho một bộ test
    }
    return 0;                           // Chương trình kết thúc thành công
}