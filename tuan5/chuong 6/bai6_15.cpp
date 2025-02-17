#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve() {
    int start_prime, end_prime;
    cin >> start_prime >> end_prime;

    if (start_prime == end_prime) return 0;

    set<int> prime_numbers;
    for (int i = 1000; i <= 9999; ++i) {
        if (isPrime(i)) {
            prime_numbers.insert(i);
        }
    }

    if (prime_numbers.find(start_prime) == prime_numbers.end() || prime_numbers.find(end_prime) == prime_numbers.end()) {
        return -1; // Hoặc giá trị khác để báo lỗi nếu cần
    }

    queue<pair<int, int>> q;
    q.push({start_prime, 0}); // {số nguyên tố hiện tại, số bước}
    set<int> visited;
    visited.insert(start_prime);

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int u = current.first;
        int steps = current.second;

        if (u == end_prime) {
            return steps;
        }

        string s = to_string(u);
        for (int i = 0; i < 4; ++i) {
            string temp = s;
            for (char digit = '0'; digit <= '9'; ++digit) {
                temp[i] = digit;
                int v = stoi(temp);

                if (v >= 1000 && v <= 9999 && prime_numbers.count(v) && visited.find(v) == visited.end()) {
                    visited.insert(v);
                    q.push({v, steps + 1});
                }
            }
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}