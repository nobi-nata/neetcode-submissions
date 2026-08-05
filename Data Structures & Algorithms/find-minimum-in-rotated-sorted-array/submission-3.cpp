class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] < nums[i]){
                ans = min(ans, nums[mid]);
                j = mid-1;
            }
            else if(nums[mid] > nums[j]){
                i = mid+1;
            }
            else{
                ans = min(ans, nums[i]);
                break;
            }
        }
        return ans;
    }
};
