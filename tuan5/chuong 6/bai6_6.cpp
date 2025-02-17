#include <iostream>     // Thư viện cho các thao tác nhập/xuất dữ liệu cơ bản.
#include <queue>        // Thư viện cho cấu trúc dữ liệu queue (hàng đợi), dùng cho thuật toán BFS.
#include <set>          // Thư viện cho cấu trúc dữ liệu set (tập hợp), dùng để theo dõi các số đã посещённые.
#include <vector>       // Thư viện cho container vector (mảng động), dù không dùng trực tiếp ở đây nhưng thường được include trong C++.
#include <algorithm>    // Thư viện chứa các thuật toán, ở đây có thể dùng `max` và `min`.
#include <cmath>        // Thư viện chứa các hàm toán học, ở đây dùng `sqrt` (căn bậc hai) và `floor` (làm tròn xuống).

using namespace std;     // Sử dụng namespace std để không cần viết std:: phía trước các thành phần chuẩn.

// Hàm biến đổi số tự nhiên N về 1 với số bước ít nhất, sử dụng hai thao tác (a) và (b).
// Input: int n - số tự nhiên đầu vào N.
// Output: int - số bước tối thiểu để biến đổi N thành 1, hoặc -1 nếu không thể (trong bài này luôn tìm được).
int bienDoiSoTuNhien(int n) {
    if (n == 1) {
        return 0; // **Trường hợp cơ bản:** Nếu số N đã là 1, thì không cần thực hiện bất kỳ thao tác nào, trả về 0 bước.
    }

    queue<pair<int, int>> q; // Khai báo một queue tên là 'q'. Mỗi phần tử trong queue là một cặp (pair):
                                  // - Phần tử thứ nhất (first): int, biểu diễn giá trị số hiện tại trong quá trình biến đổi.
                                  // - Phần tử thứ hai (second): int, biểu diễn số bước đã thực hiện để đạt được giá trị số hiện tại.
                                  // Queue này được sử dụng để thực hiện thuật toán tìm kiếm theo chiều rộng (BFS - Breadth-First Search).

    set<int> visited;          // Khai báo một set tên là 'visited'. Set này dùng để lưu trữ các giá trị số mà thuật toán đã посещённые (đã xét qua).
                                   // Mục đích là để tránh lặp lại việc xét cùng một giá trị số nhiều lần, giúp thuật toán hiệu quả hơn
                                   // và tránh rơi vào vòng lặp vô hạn (mặc dù với bài toán này, vòng lặp vô hạn không phải vấn đề lớn).

    q.push({n, 0});           // **Khởi tạo BFS:** Đưa trạng thái ban đầu vào queue. Trạng thái ban đầu là một cặp (n, 0),
                                  // trong đó 'n' là số tự nhiên đầu vào và '0' là số bước đã thực hiện (ban đầu chưa có bước nào).
    visited.insert(n);         // Đánh dấu số ban đầu 'n' là đã посещённые bằng cách thêm nó vào set 'visited'.

    while (!q.empty()) {         // **Vòng lặp chính của thuật toán BFS:** Vòng lặp này tiếp tục cho đến khi queue 'q' trở nên rỗng.
                                  // Khi queue rỗng, có nghĩa là chúng ta đã xét hết tất cả các trạng thái có thể đạt được từ trạng thái ban đầu
                                  // mà không tìm thấy số mục tiêu (số 1). (Tuy nhiên, trong bài toán này, ta giả định luôn tìm được đường đi).

        pair<int, int> current = q.front(); // Lấy ra phần tử đầu tiên (ở đầu queue) và lưu vào biến 'current'.
                                                 // Phần tử này đại diện cho trạng thái hiện tại mà chúng ta đang xét trong quá trình BFS.
        q.pop();                              // Loại bỏ phần tử đầu tiên ra khỏi queue sau khi đã lấy ra, để tiếp tục xử lý các trạng thái tiếp theo.

        int current_n = current.first;    // Lấy giá trị số hiện tại từ cặp 'current' (phần tử đầu tiên của cặp pair) và gán cho biến 'current_n'.
        int steps = current.second;       // Lấy số bước đã thực hiện từ cặp 'current' (phần tử thứ hai của cặp pair) và gán cho biến 'steps'.

        // **Thao tác (a): Trừ N đi 1 (N = N - 1)**
        int subtract_n = current_n - 1; // Tính giá trị mới sau khi thực hiện thao tác trừ 1.
        // **Kiểm tra tính hợp lệ và trạng thái đã посещённые của số mới:**
        if (subtract_n >= 1 && visited.find(subtract_n) == visited.end()) {
            // **Điều kiện hợp lệ:**
            // 1. `subtract_n >= 1`: Số sau khi trừ phải lớn hơn hoặc bằng 1 (vì đề bài yêu cầu biến đổi về 1 và số tự nhiên phải dương).
            // 2. `visited.find(subtract_n) == visited.end()`: Kiểm tra xem số 'subtract_n' đã được посещённые trước đó hay chưa.
            //    Nếu chưa посещённые, chúng ta mới tiếp tục xét trạng thái này.

            if (subtract_n == 1) {
                return steps + 1; // **Kiểm tra xem đã đạt được số mục tiêu 1 chưa:** Nếu 'subtract_n' bằng 1,
                                 // thì chúng ta đã tìm thấy đường đi ngắn nhất để biến đổi N thành 1.
                                 // Trả về 'steps + 1' (vì chúng ta vừa thực hiện thêm một bước thao tác trừ 1).
            }
            q.push({subtract_n, steps + 1}); // **Thêm trạng thái mới vào queue:** Nếu 'subtract_n' chưa phải là 1 nhưng hợp lệ,
                                             // thì thêm trạng thái mới (gồm số 'subtract_n' và số bước 'steps + 1') vào queue 'q' để tiếp tục tìm kiếm.
            visited.insert(subtract_n);       // Đánh dấu số 'subtract_n' là đã посещённые để tránh xét lại trong tương lai.
        }

        // **Thao tác (b): N = max(u, v) nếu u * v = N (u > 1, v > 1)**
        if (current_n > 1) { // **Điều kiện áp dụng thao tác (b):** Chỉ khi số hiện tại 'current_n' lớn hơn 1, ta mới xét thao tác phân tích thừa số và lấy max.
            // Vòng lặp để tìm các cặp ước số (u, v) của 'current_n' sao cho u * v = current_n và u > 1, v > 1.
            // Chúng ta chỉ cần duyệt 'u' từ 2 đến căn bậc hai của 'current_n' là đủ, vì nếu 'u' là ước thì 'v = current_n / u' cũng là ước, và ngược lại.
            for (int u = 2; u * u <= current_n; ++u) {
                if (current_n % u == 0) { // Kiểm tra nếu 'u' là ước của 'current_n' (chia hết).
                    int v = current_n / u; // Tính ước số 'v' tương ứng.
                    int max_uv = max(u, v); // Tính max(u, v) theo yêu cầu của thao tác (b).
                    // **Kiểm tra trạng thái đã посещённые của số mới 'max_uv':**
                    if (visited.find(max_uv) == visited.end()) {
                        // **Điều kiện hợp lệ:**
                        // `visited.find(max_uv) == visited.end()`: Kiểm tra xem số 'max_uv' đã được посещённые trước đó hay chưa.

                        if (max_uv == 1) { // **Trường hợp đặc biệt (thực ra không cần thiết):** Trong trường hợp phép chia lại ra 1 (ví dụ khi N=4, u=2, v=2, max(u,v)=2, không thể ra 1 trực tiếp từ phép chia này)
                            return steps + 1; // Nếu 'max_uv' bằng 1 (trường hợp này thực tế không xảy ra với thao tác (b) theo đề bài vì u,v>1),
                                             // thì trả về 'steps + 1'. (Dòng này thực tế không cần thiết trong code vì phép chia u*v=N với u,v>1 sẽ không bao giờ cho max(u,v)=1).
                        }
                        q.push({max_uv, steps + 1}); // **Thêm trạng thái mới vào queue:** Nếu 'max_uv' chưa phải là 1 và hợp lệ,
                                                 // thì thêm trạng thái mới (gồm số 'max_uv' và số bước 'steps + 1') vào queue 'q' để tiếp tục tìm kiếm.
                        visited.insert(max_uv);       // Đánh dấu số 'max_uv' là đã посещённые để tránh xét lại trong tương lai.
                    }
                }
            }
        }
    }

    return -1; // **Trường hợp không tìm thấy đường đi:** (Về mặt lý thuyết, với các thao tác và giới hạn bài toán, thuật toán BFS này sẽ luôn tìm được đường đi nếu có thể biến đổi N về 1).
                 // Trả về -1 để báo hiệu không tìm thấy đường đi (nhưng trong bài này không nên xảy ra).
}

int main() {
    int t;          // Biến 't' để lưu số lượng test case.
    cin >> t;       // Đọc số lượng test case từ input và lưu vào biến 't'.

    while (t--) {  // Vòng lặp 'while' này sẽ thực hiện 't' lần, mỗi lần xử lý một test case.
        int n;      // Biến 'n' kiểu int để lưu số tự nhiên N đầu vào cho mỗi test case.
        cin >> n;   // Đọc số tự nhiên 'n' từ input cho test case hiện tại và lưu vào biến 'n'.
        // Gọi hàm 'bienDoiSoTuNhien' để tìm số bước biến đổi tối thiểu từ N về 1, và in kết quả ra output.
        cout << bienDoiSoTuNhien(n) << endl; // 'endl' để xuống dòng sau khi in kết quả cho mỗi test case, giúp output rõ ràng.
    }
    return 0;         // Hàm main trả về 0, báo hiệu chương trình kết thúc thành công.
}