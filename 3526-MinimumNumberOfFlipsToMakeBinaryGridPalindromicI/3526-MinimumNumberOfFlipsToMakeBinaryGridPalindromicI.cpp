// Last updated: 26/11/2025, 22:29:54
class Solution {
public:
    
int flipToMakeRowPalindromic(vector<vector<int>>& grid, int row) {
    int n = grid[0].size();
    int flips = 0;
    for (int i = 0; i < row; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (grid[i][left] != grid[i][right]) {
                flips++;
            }
            left++;
            right--;
        }
    }
    return flips;
}

int flipToMakeColumnPalindromic(vector<vector<int>>& grid, int col) {
    int m = grid.size();
    int flips = 0;
    for (int i = 0; i < col; i++) {
        int top = 0, bottom = m - 1;
        while (top < bottom) {
            if (grid[top][i] != grid[bottom][i]) {
                flips++;
            }
            top++;
            bottom--;
        }
    }
    return flips;
}

int minFlips(vector<vector<int>>& grid) {
     int m = grid.size();
    int n = grid[0].size();
    int rowFlips = flipToMakeRowPalindromic(grid, m);
    int colFlips = flipToMakeColumnPalindromic(grid, n);
    return min(rowFlips, colFlips);
}

};