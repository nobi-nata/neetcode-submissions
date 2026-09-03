class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int leftprod = 1;
        for(int i = 0; i < nums.size(); i++){
            leftprod *= nums[i];
            res = max(res, leftprod);
            
            if(nums[i] == 0){
                leftprod = 1;
                continue;
            }
        }
        int rightprod = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            rightprod *= nums[i];
            res = max(res, rightprod);
            
            if(nums[i] == 0){
                rightprod = 1;
                continue;
            }
        }
        return res;
    }
};
