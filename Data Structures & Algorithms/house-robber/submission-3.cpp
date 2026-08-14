class Solution {
public:
    int dp(vector<int>& nums, int i, vector<int> &d){
        if(i >= nums.size()) return 0;

        if(d[i] != -1) return d[i];

        return d[i] = max(nums[i] + dp(nums, i+2, d), dp(nums, i+1, d));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[n] = 0;
        if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);
        dp[n - 1] = nums[n - 1];

        for(int i = n-2; i >= 0; i--){
            int take = nums[i] + dp[i+2];
            int notTake = dp[i+1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};
