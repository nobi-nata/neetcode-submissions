class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n <= 1) return intervals;
        result.push_back(intervals[0]);
        int i = 1;
        while(i < n){
            while(i < n && intervals[i][0] > result.back()[1]){
                result.push_back(intervals[i]);
                i++;
            }
            if(i < n && intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            i++;

        }
        
        return result;
    }
};
