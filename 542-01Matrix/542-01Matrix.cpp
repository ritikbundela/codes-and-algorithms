// Last updated: 26/11/2025, 22:31:57
class Solution {
public:


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    queue<pair<pair<int, int>, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                vis[i][j] = 1;
                q.push({{i, j}, 0}); 
            }
        }
    }
    
    int dir_row[] = {-1, 0, 1, 0};
    int dir_col[] = {0, 1, 0, -1};
    
    // BFS Loop
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop(); 
        
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];
            
            if (new_row >= 0 && new_row < n && new_col >= 0 
                && new_col < m && vis[new_row][new_col] == 0) {
                vis[new_row][new_col] = 1; // Mark as visited
                q.push({{new_row, new_col}, steps + 1}); // Push with incremented distance
            }
        }
    }
    

    return dist;
}
};