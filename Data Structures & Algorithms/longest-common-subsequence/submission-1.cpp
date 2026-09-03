class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j > 0 && i > 0){
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                else if(j > 0){
                    dp[i][j] = dp[i][j-1];
                }
                else if(i > 0){
                    dp[i][j] = dp[i-1][j];
                }
                if(text1[i] == text2[j]){
                    if(j > 0 && i > 0){
                        dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
                    }
                    else dp[i][j] = max(1, dp[i][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
