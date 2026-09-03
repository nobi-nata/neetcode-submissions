class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int leftprod = 1;
        int rightprod = 1;
        for(int i = 0; i < nums.size(); i++){
            leftprod *= nums[i];
            rightprod *= nums[nums.size()-i-1];
            res = max(res, max(leftprod, rightprod));
            
            if(leftprod == 0){
                leftprod = 1;
            }
            if(rightprod == 0){
                rightprod = 1;
            }
        }
       
        return res;
    }
};
