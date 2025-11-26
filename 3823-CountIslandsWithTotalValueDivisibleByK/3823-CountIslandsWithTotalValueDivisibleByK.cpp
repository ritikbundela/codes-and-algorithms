// Last updated: 26/11/2025, 22:29:32
class Solution {
public:

long long bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int rows = grid.size();
    int cols = grid[0].size();

     vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    long long sum = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        sum += grid[cx][cy];

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                !visited[nx][ny] && grid[nx][ny] != 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return sum;
}

int countIslands(vector<vector<int>>& grid, int K) {
    if (grid.empty() || grid[0].empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j] && grid[i][j] != 0) {
                int islandSum = bfs(i, j, grid, visited);
                if ((islandSum % K + K)% K == 0)
                    count++;
            }
        }
    }

    return count;
}
    
};