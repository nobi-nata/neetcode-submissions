class Solution {
public:
    int findPath(vector<vector<int>> &dp, int r, int c){
        if(dp[r][c] != -1) return dp[r][c];
        
        int right = 0, down = 0;

        if(r > 0) down = findPath(dp, r-1, c);
        if(c > 0) right = findPath(dp, r, c-1);

        return right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // dp[m-1][n-1] = findPath(dp, m-1, n-1);

        return dp[m-1][n-1];
    }
};
