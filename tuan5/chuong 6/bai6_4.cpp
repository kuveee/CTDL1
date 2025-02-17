#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản
#include <string>       // Thư viện để làm việc với kiểu dữ liệu chuỗi (string)
#include <queue>        // Thư viện cung cấp cấu trúc dữ liệu queue (hàng đợi), dùng cho thuật toán BFS
#include <set>          // Thư viện cung cấp cấu trúc dữ liệu set (tập hợp), dùng để lưu các số dư đã посещённые

using namespace std;

// Hàm tìm số BDN nhỏ nhất của N (số BDN nhỏ nhất chia hết cho số tự nhiên N)
// Input: int n - số tự nhiên N, là số mà số BDN cần chia hết
// Output: string - chuỗi biểu diễn số BDN nhỏ nhất chia hết cho N
string findSmallestBDNofN(int n) {
    queue<pair<string, int>> q; // Khai báo một queue tên là 'q'. Mỗi phần tử trong queue là một cặp (pair):
                                  // - Phần tử thứ nhất (first): string, biểu diễn số BDN đang xét dưới dạng chuỗi.
                                  // - Phần tử thứ hai (second): int, biểu diễn số dư của số BDN đó khi chia cho N.
                                  // Queue này được sử dụng để thực hiện thuật toán tìm kiếm theo chiều rộng (BFS).

    set<int> visited_remainders; // Khai báo một set tên là 'visited_remainders' để lưu trữ các số dư mà chúng ta đã gặp.
                                   // Set này giúp theo dõi các trạng thái đã посещённые trong quá trình tìm kiếm,
                                   // từ đó tránh việc lặp lại các trạng thái không cần thiết và ngăn ngừa thuật toán rơi vào vòng lặp vô hạn.

    q.push({"1", 1 % n});      // **Khởi tạo thuật toán BFS:** Bắt đầu bằng cách thêm vào queue một trạng thái ban đầu.
                                  // Trạng thái ban đầu là số BDN "1" (chuỗi "1") và số dư của nó khi chia cho N (1 % n).
                                  // Chúng ta bắt đầu từ số "1" vì đề bài yêu cầu tìm số BDN *nguyên dương* nhỏ nhất.
    visited_remainders.insert(1 % n); // Thêm số dư ban đầu (1 % n) vào set 'visited_remainders' để đánh dấu rằng số dư này đã được посещённые.

    while (!q.empty()) {         // **Vòng lặp chính của thuật toán BFS:** Vòng lặp này tiếp tục cho đến khi queue 'q' trở nên rỗng.
                                  // Queue rỗng có nghĩa là chúng ta đã xét hết tất cả các trạng thái có thể đạt được từ trạng thái ban đầu
                                  // mà không tìm thấy số BDN nào chia hết cho N. (Tuy nhiên, trong bài toán này, chắc chắn sẽ tìm được).

        pair<string, int> current = q.front(); // Lấy ra phần tử ở đầu queue (phần tử được thêm vào queue đầu tiên và chưa được xử lý).
                                                 // Phần tử này đại diện cho trạng thái hiện tại mà chúng ta đang xét trong quá trình tìm kiếm.
        q.pop();                              // Loại bỏ phần tử vừa lấy ra khỏi đầu queue. Sau khi lấy ra, phần tử này đã được xử lý xong,
                                                 // chúng ta sẽ xét các trạng thái kế tiếp của nó.

        string current_bdn_str = current.first;  // Lấy chuỗi số BDN hiện tại từ phần tử 'current' (đây là phần tử đầu tiên của cặp pair) và gán cho biến 'current_bdn_str'.
        int current_remainder = current.second; // Lấy số dư hiện tại từ phần tử 'current' (phần tử thứ hai của cặp pair) và gán cho biến 'current_remainder'.
                                                 // 'current_remainder' là số dư của 'current_bdn_str' khi chia cho N.

        if (current_remainder == 0) {       // **Kiểm tra điều kiện thành công (tìm thấy số BDN chia hết cho N):**
            return current_bdn_str;        // Nếu số dư hiện tại 'current_remainder' bằng 0, điều đó có nghĩa là số BDN hiện tại ('current_bdn_str') chia hết cho N.
                                             // Vì thuật toán BFS đảm bảo tìm kiếm theo chiều rộng (tức là xét các số BDN theo thứ tự độ lớn tăng dần),
                                             // nên số BDN đầu tiên mà chúng ta tìm thấy chia hết cho N chắc chắn là số BDN nhỏ nhất.
                                             // Hàm trả về chuỗi 'current_bdn_str' - đây chính là kết quả của bài toán.
        }

        // **Tạo ra các trạng thái kế tiếp (mở rộng tìm kiếm):**
        // Nếu số BDN hiện tại ('current_bdn_str') chưa chia hết cho N, chúng ta sẽ tạo ra hai số BDN mới từ số hiện tại,
        // bằng cách thêm chữ số '0' và chữ số '1' vào cuối số hiện tại.
        // Việc thêm '0' và '1' vào cuối sẽ tạo ra các số BDN lớn hơn nhưng vẫn đảm bảo chúng chỉ chứa chữ số '0' và '1',
        // và chúng ta sẽ tiếp tục tìm kiếm trong số các số BDN mới này.

        // **Tạo trạng thái mới bằng cách thêm chữ số '0' vào cuối:**
        string next_bdn_str_0 = current_bdn_str + "0"; // Tạo chuỗi BDN mới 'next_bdn_str_0' bằng cách nối thêm chữ số '0' vào cuối chuỗi 'current_bdn_str'.
        int next_remainder_0 = (current_remainder * 10) % n; // Tính số dư mới 'next_remainder_0' khi chia cho N.
                                                               // Công thức tính số dư này dựa trên tính chất của phép chia:
                                                               // Nếu số hiện tại có số dư là 'r' khi chia cho 'n', thì số mới tạo thành bằng cách thêm '0' vào cuối
                                                               // sẽ có số dư là (r * 10) % n.

        // **Kiểm tra trạng thái mới (với số dư 'next_remainder_0'):**
        if (visited_remainders.find(next_remainder_0) == visited_remainders.end()) {
            visited_remainders.insert(next_remainder_0); // Nếu số dư 'next_remainder_0' chưa từng xuất hiện (chưa được посещённые),
                                                           // thì đánh dấu nó là đã посещённые để tránh lặp lại việc xét các trạng thái tương tự sau này.
            q.push({next_bdn_str_0, next_remainder_0}); // Thêm trạng thái mới (gồm chuỗi số 'next_bdn_str_0' và số dư 'next_remainder_0') vào queue 'q'.
                                                           // Trạng thái này sẽ được xử lý trong các lần lặp BFS tiếp theo.
        }

        // **Tạo trạng thái mới bằng cách thêm chữ số '1' vào cuối:** (Tương tự như khi thêm '0', nhưng thay bằng chữ số '1')
        string next_bdn_str_1 = current_bdn_str + "1"; // Tạo chuỗi BDN mới 'next_bdn_str_1' bằng cách nối thêm chữ số '1' vào cuối chuỗi 'current_bdn_str'.
        int next_remainder_1 = (current_remainder * 10 + 1) % n; // Tính số dư mới 'next_remainder_1' khi chia cho N.
                                                                   // Tương tự như trên, nhưng công thức tính số dư có cộng thêm 1, do thêm chữ số '1' vào cuối.

        // **Kiểm tra trạng thái mới (với số dư 'next_remainder_1'):**
        if (visited_remainders.find(next_remainder_1) == visited_remainders.end()) {
            visited_remainders.insert(next_remainder_1); // Nếu số dư 'next_remainder_1' chưa từng xuất hiện (chưa được посещённые),
                                                           // thì đánh dấu nó là đã посещённые.
            q.push({next_bdn_str_1, next_remainder_1}); // Thêm trạng thái mới (gồm chuỗi số 'next_bdn_str_1' và số dư 'next_remainder_1') vào queue 'q'.
                                                           // Trạng thái này sẽ được xử lý trong các lần lặp BFS tiếp theo.
        }
    }

    return ""; // **Trường hợp không tìm thấy:** (Về mặt lý thuyết, với giới hạn N<1000 và cách xây dựng số BDN, thuật toán BFS này luôn đảm bảo tìm được một số BDN chia hết cho N).
                 // Dòng lệnh này có thể coi là một trường hợp xử lý lỗi, hoặc khi không tìm thấy kết quả trong quá trình tìm kiếm (nhưng trong bài toán này, trường hợp này không nên xảy ra).
}

int main() {
    int t;          // Biến 't' kiểu int để lưu số lượng test case.
    cin >> t;       // Đọc giá trị số lượng test case từ input và lưu vào biến 't'.

    while (t--) {  // Vòng lặp while này sẽ thực hiện 't' lần, mỗi lần xử lý một test case.
        int n;      // Biến 'n' kiểu int để lưu số tự nhiên N đầu vào cho mỗi test case.
        cin >> n;   // Đọc số tự nhiên 'n' từ input cho test case hiện tại và lưu vào biến 'n'.

        cout << findSmallestBDNofN(n) << endl; // Gọi hàm 'findSmallestBDNofN' để tìm số BDN nhỏ nhất chia hết cho 'n'.
                                                    // In kết quả trả về từ hàm (chuỗi BDN nhỏ nhất) ra console.
                                                    // 'endl' để xuống dòng sau khi in kết quả của mỗi test case, giúp output rõ ràng và dễ đọc.
    }
    return 0;         // Hàm main trả về 0, báo hiệu chương trình kết thúc thành công.
}