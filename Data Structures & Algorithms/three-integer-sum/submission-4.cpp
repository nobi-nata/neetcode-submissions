class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i = 1; i < n-1; i++){
            int j = i-1, k = i+1;
            while(j >= 0 && k < n){
                if(nums[j]+nums[k] == -nums[i]){
                    s.insert({nums[j], nums[i], nums[k]});
                    j--;
                    k++;
                }
                else if(nums[j]+nums[k] > -nums[i]){
                    j--;
                }
                else{
                    k++;
                }
            }
        }
        vector<vector<int>> ans;
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
