#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int x, y, z, steps;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(vector<vector<vector<char>>> &grid, int A, int B, int C, Node start, Node end) {
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    queue<Node> q;
    
    q.push(start);
    visited[start.x][start.y][start.z] = true;
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        
        if (current.x == end.x && current.y == end.y && current.z == end.z) {
            return current.steps;
        }
        
        for (int i = 0; i < 6; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            int nz = current.z + dz[i];
            
            if (nx >= 0 && nx < A && ny >= 0 && ny < B && nz >= 0 && nz < C &&
                !visited[nx][ny][nz] && grid[nx][ny][nz] != '#') {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, current.steps + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
        Node start, end;
        
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') start = {i, j, k, 0};
                    if (grid[i][j][k] == 'E') end = {i, j, k, 0};
                }
            }
        }
        
        cout << bfs(grid, A, B, C, start, end) << endl;
    }
    
    return 0;
}
