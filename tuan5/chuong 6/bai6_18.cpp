#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

string rotate_left(string s) {
    string next_s = s;
    char temp = next_s[0];
    next_s[0] = next_s[3];
    next_s[3] = next_s[4];
    next_s[4] = next_s[1];
    next_s[1] = temp;
    return next_s;
}

string rotate_right(string s) {
    string next_s = s;
    char temp = next_s[1];
    next_s[1] = next_s[4];
    next_s[4] = next_s[5];
    next_s[5] = next_s[2];
    next_s[2] = temp;
    return next_s;
}

int solve() {
    string initial_state, target_state;
    cin >> initial_state >> target_state;

    if (initial_state == target_state) {
        return 0;
    }

    queue<pair<string, int>> q;
    set<string> visited;

    q.push({initial_state, 0});
    visited.insert(initial_state);

    while (!q.empty()) {
        string current_state = q.front().first;
        int current_steps = q.front().second;
        q.pop();

        if (current_state == target_state) {
            return current_steps;
        }

        string next_state_left = rotate_left(current_state);
        if (visited.find(next_state_left) == visited.end()) {
            visited.insert(next_state_left);
            q.push({next_state_left, current_steps + 1});
        }

        string next_state_right = rotate_right(current_state);
        if (visited.find(next_state_right) == visited.end()) {
            visited.insert(next_state_right);
            q.push({next_state_right, current_steps + 1});
        }
    }

    return -1; // Should not reach here in theory
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}