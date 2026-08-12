class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;

        for(auto point : points){
            double dis = sqrt(point[0]*point[0] + point[1]*point[1]);
            pq.push({dis, point});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            ans.push_back(val.second);
        }
        return ans;
    }
};
