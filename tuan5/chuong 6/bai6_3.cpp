#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm đếm số lượng số BDN nhỏ hơn hoặc bằng giới hạn cho trước (dạng chuỗi)
int countBDN(string current_bdn, string limit_str) {
    if (current_bdn.length() > limit_str.length() || (current_bdn.length() == limit_str.length() && current_bdn >= limit_str)) {
        return 0; // Nếu số BDN hiện tại lớn hơn hoặc bằng giới hạn, không tính và dừng đệ quy
    }

    int count = 0;
    if (!current_bdn.empty()) {
        count = 1; // Nếu chuỗi BDN không rỗng, tính là một số BDN hợp lệ
    }

    string next_bdn_0 = current_bdn + "0";
    string next_bdn_1 = current_bdn + "1";

    count += countBDN(next_bdn_0, limit_str); // Đệ quy cho trường hợp thêm '0'
    count += countBDN(next_bdn_1, limit_str); // Đệ quy cho trường hợp thêm '1'

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string n_str = to_string(n);
        cout << countBDN("1", n_str) << endl; // Gọi hàm bắt đầu từ số '1' và giới hạn là N (dạng chuỗi)
    }
    return 0;
}