#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm đệ quy sinh số lộc phát
void generateLocPhat(int n, string current_num, vector<string>& locphat_numbers) {
    if (current_num.length() > n) {
        return;
    }
    if (!current_num.empty()) {
        locphat_numbers.push_back(current_num);
    }
    generateLocPhat(n, current_num + "6", locphat_numbers);
    generateLocPhat(n, current_num + "8", locphat_numbers);
}

bool compareDecreasing(const string& a, const string& b) {
    return a > b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> locphat_numbers_14;
        for (int i = 1; i <= n; ++i) {
            generateLocPhat(i, "", locphat_numbers_14);
        }
        sort(locphat_numbers_14.begin(), locphat_numbers_14.end(), compareDecreasing);

        cout << locphat_numbers_14.size() << endl;
        for (const string& s : locphat_numbers_14) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}