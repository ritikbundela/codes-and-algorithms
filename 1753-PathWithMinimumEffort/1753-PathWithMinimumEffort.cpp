// Last updated: 26/11/2025, 22:30:39
class Solution {
public:

    typedef pair<int, pair<int, int>> P;
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();    // Rows
    int m = heights[0].size(); // Columns

    vector<vector<int>> result(n, vector<int>(m, INT_MAX));
    priority_queue<P, vector<P>, greater<P>> pq;

    result[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto [diff, pos] = pq.top();
        int x = pos.first, y = pos.second;
        pq.pop();

        if (x == n - 1 && y == m - 1) 
            return diff; // Found the minimum effort path

        for (auto dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int absDiff = abs(heights[x][y] - heights[nx][ny]);
                int maxDiff = max(diff, absDiff);

                if (result[nx][ny] > maxDiff) {
                    result[nx][ny] = maxDiff;
                    pq.push({maxDiff, {nx, ny}});
                }
            }
        }
    }
    
    return -1;
}
};