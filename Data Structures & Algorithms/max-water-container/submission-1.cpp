class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int i = 0, j = heights.size()-1;
        while(i < j){
            int mini = min(heights[j], heights[i])*(j-i);
            ans = max(ans, mini);
            if(heights[i] > heights[j]){
                j--;
            }
            else i++;
        }
        return ans;
    }
};
