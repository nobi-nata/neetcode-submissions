class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        int cnt = 1;
        int res = 0;
        for(int j = 1; j < nums.size(); j++){
            while(j < nums.size() && nums[j] == nums[j-1]) j++;
            if(j < nums.size() && nums[j] > nums[j-1]+1){
                res = max(res, cnt);
                cnt = 1;
            }
            if(j < nums.size() && nums[j] == nums[j-1]+1) cnt++;
            cout << cnt << res<< " ";
        }
        res = max(res, cnt);
        return res;
    }
};
