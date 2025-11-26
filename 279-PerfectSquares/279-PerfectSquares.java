// Last updated: 26/11/2025, 22:32:23
class Solution {
    public int numSquares(int n) {
         int dp[] = new int[n+1];   

        dp[1] = 1;
        for(int i=1;i<=(int)Math.sqrt(n);i++){
            dp[i*i] = 1;
        }

        for(int i=2;i<=n;i++){
            if(dp[i] == 1){
                continue;
            }
            dp[i] = dp[i-1]+1;
            for(int j=2;j*j<i;j++){
                dp[i] = Math.min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n];
    }
}