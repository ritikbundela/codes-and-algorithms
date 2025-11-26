// Last updated: 26/11/2025, 22:34:23
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0,  right = matrix[0].size()-1;
        int left = 0, bottom = matrix.size()-1;

        while(top <= bottom && left <= right){
            // traverse top row
            for(int j=left; j<=right; j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            // traverse right column
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            // bottom row
            if(top <= bottom){
            for(int j=right; j>=left; j--){
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
            }

            // left column
            if(left <= right){
            for(int i=bottom; i>=top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        }
        return res;
        
    }
};