class Solution {
public:
    int dp(vector<int>& nums, int i, vector<int> &d){
        if(i >= nums.size()) return 0;

        if(d[i] != -1) return d[i];

        return d[i] = max(nums[i] + dp(nums, i+2, d), dp(nums, i+1, d));
    }

    int rob(vector<int>& nums) {
        vector<int> d(nums.size(), -1);
        return dp(nums, 0, d);
    }
};
