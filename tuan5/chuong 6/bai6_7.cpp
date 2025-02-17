#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <sstream> // Để sử dụng stringstream

using namespace std;

// Hàm kiểm tra xem hai xâu ký tự khác nhau đúng 1 ký tự hay không
bool isOneCharDiff(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false; // Nếu độ dài khác nhau, chắc chắn không khác 1 ký tự
    }
    int diffCount = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            diffCount++;
        }
    }
    return diffCount == 1; // Trả về true nếu có đúng 1 ký tự khác nhau
}

// Hàm tìm khoảng cách đường đi ngắn nhất giữa hai xâu ký tự s và t trong tập S
int shortestPath(const vector<string>& wordList, const string& startWord, const string& endWord) {
    queue<pair<string, int>> q; // Queue để thực hiện tìm kiếm theo chiều rộng (BFS)
    set<string> visited;        // Set để theo dõi các xâu đã посещённые

    q.push({startWord, 0});   // Bắt đầu BFS từ xâu s với khoảng cách 0
    visited.insert(startWord);  // Đánh dấu xâu s là đã посещённые

    while (!q.empty()) { // Vòng lặp BFS cho đến khi queue rỗng
        string currentWord = q.front().first; // Lấy xâu ký tự hiện tại từ queue
        int distance = q.front().second;    // Lấy khoảng cách hiện tại
        q.pop();                             // Loại bỏ xâu hiện tại khỏi queue

        if (currentWord == endWord) { // Nếu xâu hiện tại là xâu đích t, trả về khoảng cách
            return distance;
        }

        for (const string& nextWord : wordList) { // Duyệt qua danh sách các xâu trong S
            if (visited.find(nextWord) == visited.end() && isOneCharDiff(currentWord, nextWord)) {
                // Nếu xâu kế tiếp chưa được посещённые và khác xâu hiện tại 1 ký tự
                visited.insert(nextWord);         // Đánh dấu xâu kế tiếp là đã посещённые
                q.push({nextWord, distance + 1}); // Thêm xâu kế tiếp vào queue với khoảng cách tăng lên 1
            }
        }
    }

    return -1; // Nếu không tìm thấy đường đi (trong trường hợp này, theo đề bài thì sẽ luôn tìm thấy)
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<string> wordList(n);
        string line;
        getline(cin, line); // Đọc dòng thừa sau khi đọc n, s, t
        getline(cin, line); // Đọc dòng chứa danh sách các xâu

        stringstream ss(line);
        for (int i = 0; i < n; ++i) {
            ss >> wordList[i]; // Đọc từng xâu từ dòng và lưu vào vector wordList
        }

        cout << shortestPath(wordList, s, t) << endl; // Gọi hàm shortestPath và in ra kết quả
    }
    return 0;
}