#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <queue>        // Thư viện cung cấp cấu trúc dữ liệu queue (hàng đợi), dùng cho thuật toán BFS
#include <set>          // Thư viện cung cấp cấu trúc dữ liệu set (tập hợp), dùng để lưu các số dư đã посещённые

using namespace std;

// Hàm tìm số nguyên dương X nhỏ nhất được tạo thành từ chữ số 9 và 0, và chia hết cho số tự nhiên N
// Input: int n - số tự nhiên N (divisor)
// Output: string - chuỗi biểu diễn số X nhỏ nhất tìm được, hoặc chuỗi rỗng nếu không tìm thấy (trường hợp không thể xảy ra trong bài này)
string findSmallestDivisibleByN(int n) {
    queue<pair<string, int>> q; // Khai báo một queue tên là 'q'. Mỗi phần tử trong queue là một cặp (pair),
                                  // gồm một chuỗi (string) biểu diễn số được tạo thành từ '0' và '9',
                                  // và một số nguyên (int) là số dư của số đó khi chia cho N.
                                  // Queue này dùng để thực hiện thuật toán tìm kiếm theo chiều rộng (BFS).

    set<int> visited_remainders; // Khai báo một set tên là 'visited_remainders' để lưu trữ các số dư mà chúng ta đã gặp trong quá trình tìm kiếm.
                                   // Set giúp chúng ta kiểm tra nhanh chóng xem một số dư đã được посещённые trước đó hay chưa,
                                   // để tránh lặp lại các trạng thái và ngăn chặn thuật toán rơi vào vòng lặp vô hạn.

    q.push({"9", 9 % n});      // **Khởi tạo BFS:** Bắt đầu bằng cách thêm vào queue một cặp giá trị ban đầu:
                                  // Chuỗi số ban đầu là "9" (số nguyên dương nhỏ nhất tạo bởi 9 và 0).
                                  // Số dư ban đầu là 9 % n (số dư của 9 khi chia cho n).
    visited_remainders.insert(9 % n); // Thêm số dư ban đầu (9 % n) vào set 'visited_remainders' để đánh dấu là đã посещённые.

    while (!q.empty()) {         // **Vòng lặp BFS chính:** Vòng lặp tiếp tục cho đến khi queue 'q' trở nên rỗng,
                                  // có nghĩa là chúng ta đã xét hết tất cả các trạng thái có thể đạt được trong phạm vi tìm kiếm.
        pair<string, int> current = q.front(); // Lấy ra phần tử đầu tiên (ở đầu queue) và lưu vào biến 'current'.
                                                 // Phần tử này là trạng thái hiện tại mà chúng ta đang xét trong quá trình BFS.
        q.pop();                              // Loại bỏ phần tử đầu tiên ra khỏi queue sau khi đã lấy ra, để tiếp tục xử lý các trạng thái tiếp theo.

        string current_num_str = current.first;  // Lấy chuỗi số hiện tại từ cặp 'current' và gán cho biến 'current_num_str'.
        int current_remainder = current.second; // Lấy số dư hiện tại từ cặp 'current' và gán cho biến 'current_remainder'.

        if (current_remainder == 0) {       // **Kiểm tra điều kiện thành công:** Nếu số dư hiện tại 'current_remainder' bằng 0,
            return current_num_str;        // Điều này có nghĩa là số 'current_num_str' chia hết cho N.
                                             // Vì chúng ta đang sử dụng BFS, số đầu tiên tìm thấy thỏa mãn điều kiện chia hết sẽ là số nhỏ nhất.
                                             // Hàm trả về chuỗi 'current_num_str' (kết quả tìm kiếm).
        }

        // **Tạo các trạng thái kế tiếp:** Nếu số hiện tại không phải là số cần tìm, chúng ta tạo ra hai trạng thái mới từ trạng thái hiện tại:
        // 1. Thêm chữ số '0' vào cuối số hiện tại.
        // 2. Thêm chữ số '9' vào cuối số hiện tại.

        // **Tạo trạng thái mới bằng cách thêm '0':**
        string next_num_str_0 = current_num_str + "0"; // Tạo chuỗi số mới 'next_num_str_0' bằng cách nối thêm chữ số '0' vào cuối chuỗi hiện tại 'current_num_str'.
        int next_remainder_0 = (current_remainder * 10) % n; // Tính số dư mới 'next_remainder_0' khi chia cho N.
                                                               // Số dư mới được tính bằng cách lấy số dư hiện tại 'current_remainder' nhân với 10 (do thêm một chữ số vào cuối, tương ứng nhân với 10 trong hệ thập phân),
                                                               // sau đó lấy phần dư của kết quả cho N.

        // Kiểm tra xem số dư mới 'next_remainder_0' đã được посещённые trước đó hay chưa.
        if (visited_remainders.find(next_remainder_0) == visited_remainders.end()) {
            visited_remainders.insert(next_remainder_0); // Nếu số dư 'next_remainder_0' chưa từng được посещённые, đánh dấu nó là đã посещённые.
            q.push({next_num_str_0, next_remainder_0}); // Thêm trạng thái mới (chuỗi số 'next_num_str_0' và số dư 'next_remainder_0') vào queue 'q' để tiếp tục được xét trong các bước BFS tiếp theo.
        }

        // **Tạo trạng thái mới bằng cách thêm '9':** (Tương tự như khi thêm '0', nhưng thay bằng chữ số '9')
        string next_num_str_9 = current_num_str + "9"; // Tạo chuỗi số mới 'next_num_str_9' bằng cách nối thêm chữ số '9' vào cuối chuỗi hiện tại 'current_num_str'.
        int next_remainder_9 = (current_remainder * 10 + 9) % n; // Tính số dư mới 'next_remainder_9' khi chia cho N.
                                                                   // Số dư mới được tính tương tự, nhưng cộng thêm 9 vào kết quả nhân trước khi lấy phần dư cho N.

        // Kiểm tra xem số dư mới 'next_remainder_9' đã được посещённые trước đó hay chưa.
        if (visited_remainders.find(next_remainder_9) == visited_remainders.end()) {
            visited_remainders.insert(next_remainder_9); // Nếu số dư 'next_remainder_9' chưa từng được посещённые, đánh dấu nó là đã посещённые.
            q.push({next_num_str_9, next_remainder_9}); // Thêm trạng thái mới (chuỗi số 'next_num_str_9' và số dư 'next_remainder_9') vào queue 'q' để tiếp tục được xét trong các bước BFS tiếp theo.
        }
    }

    return ""; // **Trường hợp không tìm thấy:** (Về mặt lý thuyết, với bài toán này, thuật toán BFS sẽ luôn tìm được một số chia hết cho N trong phạm vi tìm kiếm).
                 // Dòng này trả về chuỗi rỗng, có thể coi là một trường hợp xử lý lỗi hoặc khi không tìm thấy kết quả (nhưng trong bài này không nên xảy ra).
}

int main() {
    int t;          // Biến 't' để lưu số lượng test case.
    cin >> t;       // Đọc số lượng test case từ input.

    while (t--) {  // Vòng lặp 'while' chạy 't' lần, để xử lý từng test case.
        int n;      // Biến 'n' để lưu số tự nhiên N đầu vào cho mỗi test case.
        cin >> n;   // Đọc số tự nhiên N từ input.

        cout << findSmallestDivisibleByN(n) << endl; // Gọi hàm 'findSmallestDivisibleByN' để tìm số X nhỏ nhất chia hết cho N.
                                                    // In kết quả (số X tìm được) ra console. 'endl' để xuống dòng sau khi in kết quả.
    }
    return 0;         // Chương trình kết thúc thành công.
}