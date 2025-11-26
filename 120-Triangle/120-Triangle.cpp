// Last updated: 26/11/2025, 22:33:40
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> memo = triangle[row-1];

        for(int i=row-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                memo[j] = min(memo[j], memo[j+1]) + triangle[i][j];
            }
        }
        return memo[0];
    }
};