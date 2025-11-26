// Last updated: 26/11/2025, 22:34:11
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(); 
        int k = word2.size();

        if(n == 0)
        return k;
        if(k == 0)
        return n;

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }

        for(int i=0; i<=k; i++){
            dp[0][i] = i;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[n][k];
    }
};