class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int tk = 0;
        if(n == 1) return nums[0];
        int nTK = nums[n - 1];

        for(int i = n-2; i >= 1; i--){
            int take = nums[i] + tk;
            int notTake = nTK;

            tk = nTK;
            nTK = max(take, notTake);
        }

        int first = nTK;

        tk = 0;
        nTK = nums[n - 2];

        for(int i = n-3; i >= 0; i--){
            int take = nums[i] + tk;
            int notTake = nTK;

            tk = nTK;
            nTK = max(take, notTake);
        }


        return max(first, nTK);
    }
};
