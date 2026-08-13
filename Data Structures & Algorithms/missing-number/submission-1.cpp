class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int add = 0;
        for(int i = 0; i < nums.size(); i++){
            add += nums[i];
        }
        return sum - add;
    }
};
