class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i = 0; i < n-1; i++){
            int a = nums[i];
            unordered_set<int> st = {nums[i+1]};
            for(int j = i+2; j < n; j++){
                if(st.find(-(a+nums[j])) != st.end()){
                    s.insert({a, nums[j], -a-nums[j]});
                }
                st.insert(nums[j]);
            }
        }
        vector<vector<int>> ans;
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
