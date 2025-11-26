// Last updated: 26/11/2025, 22:31:24
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n=matrix.size();
        if (n == 1) return matrix[0][0];
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j+1]);
                }else if(j==n-1){
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j-1]);
                }else{
                    matrix[i][j]+=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1]));
                }
                if(i==n-1){
                    ans=min(ans,matrix[i][j]);
                }
            }
        }
        return ans;
    }
};