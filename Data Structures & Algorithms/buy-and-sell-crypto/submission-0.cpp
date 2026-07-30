class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int maxi = 0, mini = -1;
        int n = prices.size();
        for(int i = n-1; i >= 0; i--){
            if(prices[i] > maxi){
                maxi = prices[i];
                mini = -1;
            }
            else mini = prices[i];
            if(mini != -1 && maxi > mini){
                ans = max(ans, maxi - mini);
            }
        }
        return ans;
    }
};
