// Last updated: 26/11/2025, 22:31:07
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
            }
        }

        string super = "";
        int i=n1, j=n2;

        while(i>0 and j>0){
            if(str1[i-1] == str2[j-1]){
                super += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                super += str1[i-1];
                i--;
            }else{
                super += str2[j-1];
                j--;
            }

        }

        while(i>0){
            super += str1[i-1];
            i--;
        }

        while(j>0){
            super += str2[j-1];
            j--;
        }
        reverse(super.begin(), super.end());
        return super;

    }
};