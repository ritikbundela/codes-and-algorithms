// Last updated: 26/11/2025, 22:31:06
class Solution {
public:

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1; // Start or end blocked

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1)); // Stores distance

    // 8 possible directions
    vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, 
                                   {0, -1},        {0, 1}, 
                                   {1, -1}, {1, 0}, {1, 1}};

    // Start from (0,0) with distance 1
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];  // Current distance
        q.pop();

        // If we reach the bottom-right corner, return the distance
        if (x == n - 1 && y == n - 1) return d;

        // Explore all 8 directions
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // Check if the new cell is within bounds and is walkable (0)
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = d + 1; // Update distance
                q.push({nx, ny});
            }
        }
    }

    return -1; 
}
};