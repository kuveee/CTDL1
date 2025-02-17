#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

// Hàm tìm các cặp dấu ngoặc tương ứng trong biểu thức
vector<pair<int, int>> findMatchingParentheses(const string& expression) {
    stack<int> st;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(') {
            st.push(i);
        } else if (expression[i] == ')') {
            if (!st.empty()) {
                int open_index = st.top();
                st.pop();
                pairs.push_back({open_index, i});
            }
        }
    }
    return pairs;
}

// Hàm đệ quy để tạo ra các biểu thức bằng cách xóa các cặp dấu ngoặc
void generateExpressions(string current_expression, set<string>& result_set) {
    result_set.insert(current_expression); // Thêm biểu thức hiện tại vào set kết quả

    vector<pair<int, int>> pairs = findMatchingParentheses(current_expression); // Tính toán lại cặp ngoặc ở mỗi bước

    if (pairs.empty()) {
        return;
    }

    for (int i = 0; i < pairs.size(); ++i) {
        string expression_without_pair = current_expression;
        int open_index = pairs[i].first;
        int close_index = pairs[i].second;

        expression_without_pair.erase(close_index, 1);
        expression_without_pair.erase(open_index, 1);

        generateExpressions(expression_without_pair, result_set);
    }
}

int main() {
    string input_expression;
    cin >> input_expression;

    set<string> result_expressions;
    generateExpressions(input_expression, result_expressions);

    for (const string& expr : result_expressions) {
        cout << expr << endl;
    }

    return 0;
}