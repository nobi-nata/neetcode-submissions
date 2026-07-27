class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        set<vector<int>> s(ans.begin(), ans.end());
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
