// Last updated: 26/11/2025, 22:31:43
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int originalColor = image[sr][sc];

    if (originalColor == color) return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == originalColor) {
                image[nx][ny] = color;  
                q.push({nx, ny});       
            }
        }
    }
    return image;
}
};