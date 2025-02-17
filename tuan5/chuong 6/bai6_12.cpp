#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

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

bool compareIncreasing(const string& a, const string& b) {
    return a < b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Bài 6.12
        vector<string> locphat_numbers_12;
        for (int i = 1; i <= n; ++i) {
            generateLocPhat(i, "", locphat_numbers_12);
        }
        sort(locphat_numbers_12.begin(), locphat_numbers_12.end(), compareDecreasing);

        for (const string& s : locphat_numbers_12) {
            cout << s << " ";
        }
        cout << endl;

        // Bài 6.13
        vector<string> locphat_numbers_13;
        for (int i = 1; i <= n; ++i) {
            generateLocPhat(i, "", locphat_numbers_13);
        }
        sort(locphat_numbers_13.begin(), locphat_numbers_13.end(), compareIncreasing);

        cout << locphat_numbers_13.size() << endl;
        for (const string& s : locphat_numbers_13) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}