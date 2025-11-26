// Last updated: 26/11/2025, 22:30:57
class Solution {
public:

int minInsertions(string s) {
        vector<int> memo(s.length(),0);
        int prev,temp;
        for(int i=s.length()-2;i>=0;i--) {
            prev=0;                                          //This stores the value at memo[i+1][j-1];
            for(int j=i;j<s.length();j++) {
                temp=memo[j];                               //Get the value of memo[i+1][j].
                memo[j]=s[i]==s[j]?prev:1+min(memo[j],memo[j-1]);     //memo[j]=memo[i+1][j], memo[j-1]=memo[i][j-1], prev=memo[i+1][j-1].
                prev=temp;                        //Store the value of memo[i+1][j] to use it as memo[i+1][j-1] in the next iteration.
            }
        }
        return memo[s.length()-1];
    }

//    int longestPalindromeSubseq(string s) {
//     int n = s.size();
//     string t = s;
//     reverse(t.begin(), t.end()); // Reverse of the string
    
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
//     // Tabulation for LPS
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (s[i - 1] == t[j - 1]) {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
    
//     return dp[n][n];
// }

// int minInsertions(string s) {
//     int n = s.size();
//     int lps = longestPalindromeSubseq(s);
//     // Minimum insertions = length of string - length of LPS
//     return n - lps;
// }
};