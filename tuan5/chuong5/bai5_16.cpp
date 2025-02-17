#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <vector>       // Thư viện để làm việc với vector (mảng động)
#include <stack>        // Thư viện cung cấp cấu trúc dữ liệu stack (ngăn xếp)
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây dùng `max` để tìm giá trị lớn nhất

using namespace std;

// Hàm tính diện tích hình chữ nhật lớn nhất trong histogram
// Input: vector<int>& heights - vector chứa chiều cao của các cột histogram
// Output: long long - diện tích hình chữ nhật lớn nhất tìm được
long long largestRectangleArea(vector<int>& heights) {
    int n = heights.size(); // Lấy số lượng cột trong histogram
    stack<int> st;          // Khởi tạo một stack tên là 'st' để lưu trữ index của các cột.
                            // Stack này giúp chúng ta theo dõi các cột có chiều cao không giảm.
    long long maxArea = 0;   // Khởi tạo biến 'maxArea' để lưu diện tích hình chữ nhật lớn nhất, ban đầu là 0.
                            // Dùng kiểu long long để tránh tràn số khi tính diện tích lớn.

    // Duyệt qua từng cột của histogram, từ cột đầu tiên đến cột cuối cùng.
    // Thêm một cột ảo vào cuối histogram (với i <= n), cột ảo này có chiều cao là 0,
    // mục đích để đảm bảo tất cả các cột còn lại trong stack đều được xử lý sau vòng lặp chính.
    for (int i = 0; i <= n; ++i) {
        // Xác định chiều cao hiện tại của cột đang xét.
        // Nếu i == n (đã đến cột ảo cuối cùng), chiều cao 'h' là 0.
        // Ngược lại, chiều cao 'h' là chiều cao của cột thứ 'i' trong vector 'heights'.
        int h = (i == n) ? 0 : heights[i];

        // **Quan trọng:** Vòng lặp while này xử lý việc tính toán diện tích khi gặp một cột có chiều cao nhỏ hơn
        // cột trên đỉnh stack, hoặc khi duyệt đến cột ảo cuối cùng (chiều cao 0).
        while (!st.empty() && h < heights[st.top()]) {
            // Lấy chiều cao của cột trên đỉnh stack. Cột này sẽ là chiều cao của hình chữ nhật tiềm năng.
            int height = heights[st.top()];
            // Loại bỏ index cột vừa lấy ra khỏi stack.
            st.pop();

            int width; // Biến 'width' để lưu chiều rộng của hình chữ nhật.
            if (st.empty()) {
                // Nếu stack trở nên rỗng sau khi pop, điều này có nghĩa là không có cột nào bên trái cột hiện tại
                // mà có chiều cao nhỏ hơn. Vậy chiều rộng của hình chữ nhật kéo dài từ đầu histogram (index 0)
                // đến cột hiện tại (index 'i').
                width = i;
            } else {
                // Nếu stack không rỗng, chiều rộng của hình chữ nhật được tính bằng khoảng cách
                // giữa index cột hiện tại 'i' và index của cột ngay dưới đỉnh stack (sau khi đã pop cột trên đỉnh).
                // Cần trừ thêm 1 vì index trong stack là index cột bên trái gần nhất có chiều cao nhỏ hơn.
                width = i - st.top() - 1;
            }

            // Tính diện tích hình chữ nhật hiện tại (chiều cao * chiều rộng) và so sánh với diện tích lớn nhất 'maxArea' đã tìm được.
            // Cập nhật 'maxArea' nếu diện tích hiện tại lớn hơn.
            maxArea = max(maxArea, (long long)height * width);
        }
        // Sau khi vòng lặp while kết thúc (hoặc nếu điều kiện while không thỏa mãn ngay từ đầu),
        // đẩy index cột hiện tại 'i' vào stack 'st'.
        // Mục đích: stack 'st' luôn giữ các index của các cột có chiều cao không giảm.
        st.push(i);
    }

    // Sau khi duyệt hết tất cả các cột (bao gồm cả cột ảo cuối cùng),
    // 'maxArea' sẽ chứa diện tích hình chữ nhật lớn nhất có thể tạo được trong histogram.
    return maxArea; // Trả về diện tích hình chữ nhật lớn nhất.
}

int main() {
    int t; // Biến 't' để lưu số lượng test case
    cin >> t; // Đọc số lượng test case từ input
    while (t--) { // Vòng lặp 'while' chạy 't' lần, mỗi lần xử lý một test case
        int n; // Biến 'n' để lưu số lượng cột trong histogram cho mỗi test case
        cin >> n; // Đọc số lượng cột từ input
        vector<int> h(n); // Khai báo một vector 'h' có kích thước 'n' để lưu chiều cao các cột
        // Vòng lặp for để đọc chiều cao của từng cột vào vector 'h'
        for (int i = 0; i < n; ++i) {
            cin >> h[i]; // Đọc chiều cao cột thứ 'i' từ input và lưu vào 'h[i]'
        }
        // Gọi hàm 'largestRectangleArea' để tính diện tích hình chữ nhật lớn nhất trong histogram
        // và in kết quả ra output.
        cout << largestRectangleArea(h) << endl; // 'endl' để xuống dòng sau khi in kết quả mỗi test case
    }
    return 0; // Chương trình kết thúc thành công, trả về 0 cho hệ điều hành
}