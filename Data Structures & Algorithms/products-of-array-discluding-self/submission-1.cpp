class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod = 1;
        int cnt = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0) prod *= nums[j];
            else cnt++;
        }
        if(cnt > 1) prod = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0) ans.push_back(prod/nums[i]);
            else if(nums[i] == 0 && cnt == 1) ans.push_back(prod);
            else ans.push_back(0);           
        }
        return ans;
    }
};
