// Last updated: 26/11/2025, 22:34:17
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int j,i;
        for(i=1; i<col; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(j=1; j<row; j++){
            grid[j][0] += grid[j-1][0];
        }
        for(i=1; i<row; i++){
            for(j=1; j<col; j++){
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]); 
            }
        }
        return grid[row-1][col-1];
        
    }
};