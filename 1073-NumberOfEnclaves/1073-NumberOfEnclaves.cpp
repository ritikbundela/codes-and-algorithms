// Last updated: 26/11/2025, 22:31:11
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        int count  = 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    // Step 1: Mark boundary 'O's and start BFS from them

    // First and last rows
    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1) { // First row
            vis[0][i] = 1;
            q.push({0, i});
        }
        if (grid[n-1][i] == 1) { // Last row
            vis[n-1][i] = 1;
            q.push({n-1, i});
        }
    }

    // First and last columns
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) { // First column
            vis[i][0] = 1;
            q.push({i, 0});
        }
        if (grid[i][m-1] == 1) { // Last column (note: m-1 for columns)
            vis[i][m-1] = 1;
            q.push({i, m-1});
        }
    }

    // Step 2: Perform BFS to mark all 'O's connected to boundary 'O's

    // Direction vectors to explore up, right, down, left
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + a[i];
            int nc = c + b[i];

            // Check if new position is valid and is an 'O' not yet visited
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    // Step 3: Change all unvisited 'O's to 'X'

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
    }
};