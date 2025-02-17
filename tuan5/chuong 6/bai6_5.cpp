#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản (cin, cout).
#include <queue>        // Thư viện cung cấp cấu trúc dữ liệu queue (hàng đợi), sử dụng cho thuật toán BFS.
#include <set>          // Thư viện cung cấp cấu trúc dữ liệu set (tập hợp), dùng để theo dõi các số đã посещённые.
#include <vector>       // Thư viện cho container vector (mảng động), dù không dùng trực tiếp ở bài này nhưng thường được include trong C++.
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây có thể dùng `min` (nhưng thực tế không dùng trong code này).

using namespace std;     // Sử dụng không gian tên std để không cần viết std:: phía trước các thành phần của thư viện chuẩn.

// Hàm biến đổi số nguyên S thành số nguyên T với số bước ít nhất bằng các thao tác nhân 2 và trừ 1.
// Input:
//   - int s: số nguyên dương ban đầu (S).
//   - int t: số nguyên dương mục tiêu (T).
// Output:
//   - int: số bước tối thiểu để biến đổi S thành T, hoặc -1 nếu không thể (trong bài này luôn tìm được đường đi).
int bienDoiST(int s, int t) {
    if (s == t) {
        return 0; // **Trường hợp cơ bản:** Nếu số ban đầu S đã bằng số mục tiêu T, thì không cần thao tác nào, trả về 0 bước.
    }

    queue<pair<int, int>> q; // Khai báo một queue tên là 'q'. Mỗi phần tử trong queue là một cặp (pair):
                                  // - Phần tử thứ nhất (first): int, biểu diễn giá trị số hiện tại trong quá trình biến đổi.
                                  // - Phần tử thứ hai (second): int, biểu diễn số bước đã thực hiện để đạt đến giá trị số hiện tại.
                                  // Queue này được sử dụng để thực hiện thuật toán tìm kiếm theo chiều rộng (BFS - Breadth-First Search).

    set<int> visited;          // Khai báo một set tên là 'visited'. Set này dùng để lưu trữ các giá trị số mà thuật toán đã посещённые (đã xét qua).
                                   // Mục đích của việc này là để tránh lặp lại việc xét cùng một giá trị số nhiều lần,
                                   // từ đó giúp thuật toán chạy nhanh hơn và tránh rơi vào vòng lặp vô hạn trong một số trường hợp.

    q.push({s, 0});           // **Khởi tạo BFS:** Đưa trạng thái ban đầu vào queue. Trạng thái ban đầu là một cặp (s, 0),
                                  // trong đó 's' là số ban đầu và '0' là số bước đã thực hiện (ban đầu chưa thực hiện bước nào).
    visited.insert(s);         // Đánh dấu số ban đầu 's' là đã посещённые bằng cách thêm nó vào set 'visited'.

    while (!q.empty()) {         // **Vòng lặp chính của thuật toán BFS:** Vòng lặp này tiếp tục cho đến khi queue 'q' trở nên rỗng.
                                  // Khi queue rỗng, có nghĩa là chúng ta đã xét hết tất cả các trạng thái có thể đạt được từ trạng thái ban đầu
                                  // mà không tìm thấy số mục tiêu 't'. (Tuy nhiên, trong bài toán này, ta giả định luôn tìm được đường đi).

        pair<int, int> current = q.front(); // Lấy ra phần tử đầu tiên (ở đầu queue) và lưu vào biến 'current'.
                                                 // Phần tử này là trạng thái hiện tại mà chúng ta đang xét trong quá trình BFS.
        q.pop();                              // Loại bỏ phần tử đầu tiên ra khỏi queue sau khi đã lấy ra.

        int current_s = current.first;    // Lấy giá trị số hiện tại từ cặp 'current' (phần tử đầu tiên của cặp pair) và gán cho biến 'current_s'.
        int steps = current.second;       // Lấy số bước đã thực hiện từ cặp 'current' (phần tử thứ hai của cặp pair) và gán cho biến 'steps'.

        // **Thực hiện Thao tác (a): Nhân S với 2 (S = S * 2)**
        int multiply_s = current_s * 2; // Tính giá trị mới sau khi nhân đôi số hiện tại.
        // **Kiểm tra tính hợp lệ và trạng thái đã посещённые của số mới:**
        if (multiply_s <= 20000 && visited.find(multiply_s) == visited.end()) {
            // **Điều kiện hợp lệ:**
            // 1. `multiply_s <= 20000`:  Giới hạn giá trị số để tránh việc số trở nên quá lớn và tìm kiếm không hiệu quả.
            //    (20000 là một giá trị giới hạn ước lượng, có thể điều chỉnh tùy thuộc vào yêu cầu bài toán, ở đây chọn lớn hơn T<10000 một chút).
            // 2. `visited.find(multiply_s) == visited.end()`: Kiểm tra xem số 'multiply_s' đã được посещённые trước đó hay chưa.
            //    Nếu chưa посещённые, chúng ta mới tiếp tục xét trạng thái này.

            if (multiply_s == t) {
                return steps + 1; // **Kiểm tra xem đã đạt được số mục tiêu T chưa:** Nếu 'multiply_s' bằng 't',
                                 // thì chúng ta đã tìm thấy đường đi ngắn nhất để biến đổi S thành T.
                                 // Trả về 'steps + 1' (vì chúng ta vừa thực hiện thêm một bước thao tác nhân 2).
            }
            q.push({multiply_s, steps + 1}); // **Thêm trạng thái mới vào queue:** Nếu 'multiply_s' chưa phải là 't' nhưng hợp lệ,
                                             // thì thêm trạng thái mới (gồm số 'multiply_s' và số bước 'steps + 1') vào queue 'q' để tiếp tục tìm kiếm.
            visited.insert(multiply_s);       // Đánh dấu số 'multiply_s' là đã посещённые để tránh xét lại trong tương lai.
        }

        // **Thực hiện Thao tác (b): Trừ S đi 1 (S = S - 1)** (Tương tự như thao tác (a))
        int subtract_s = current_s - 1; // Tính giá trị mới sau khi trừ 1 số hiện tại.
        // **Kiểm tra tính hợp lệ và trạng thái đã посещённые của số mới:**
        if (subtract_s >= 1 && visited.find(subtract_s) == visited.end()) {
             // **Điều kiện hợp lệ:**
            // 1. `subtract_s >= 1`: Giới hạn giá trị số sau khi trừ phải lớn hơn hoặc bằng 1 (theo đề bài là số nguyên dương).
            // 2. `visited.find(subtract_s) == visited.end()`: Kiểm tra xem số 'subtract_s' đã được посещённые trước đó hay chưa.

            if (subtract_s == t) {
                return steps + 1; // **Kiểm tra xem đã đạt được số mục tiêu T chưa:** Nếu 'subtract_s' bằng 't',
                                 // thì trả về 'steps + 1' (vì chúng ta vừa thực hiện thêm một bước thao tác trừ 1).
            }
            q.push({subtract_s, steps + 1}); // **Thêm trạng thái mới vào queue:** Nếu 'subtract_s' chưa phải là 't' nhưng hợp lệ,
                                             // thì thêm trạng thái mới (gồm số 'subtract_s' và số bước 'steps + 1') vào queue 'q'.
            visited.insert(subtract_s);      // Đánh dấu số 'subtract_s' là đã посещённые.
        }
    }

    return -1; // **Trường hợp không tìm thấy đường đi:** (Về mặt lý thuyết, với các thao tác và giới hạn bài toán, thuật toán BFS này sẽ luôn tìm được đường đi nếu T có thể đạt được từ S).
                 // Trả về -1 để báo hiệu không tìm thấy đường đi (nhưng trong bài này không nên xảy ra).
}

int main() {
    int test_cases; // Biến 'test_cases' để lưu số lượng test case.
    cin >> test_cases; // Đọc số lượng test case từ input và lưu vào biến 'test_cases'.

    while (test_cases--) { // Vòng lặp 'while' này sẽ thực hiện 'test_cases' lần, mỗi lần xử lý một test case.
        int s, t;       // Biến 's' và 't' để lưu số ban đầu S và số mục tiêu T cho mỗi test case.
        cin >> s >> t;   // Đọc hai số S và T từ input cho test case hiện tại và lưu vào biến 's' và 't'.
        // Gọi hàm 'bienDoiST' để tìm số bước biến đổi tối thiểu từ S sang T, và in kết quả ra output.
        cout << bienDoiST(s, t) << endl; // 'endl' để xuống dòng sau khi in kết quả cho mỗi test case, giúp output rõ ràng.
    }
    return 0;         // Hàm main trả về 0, báo hiệu chương trình kết thúc thành công.
}