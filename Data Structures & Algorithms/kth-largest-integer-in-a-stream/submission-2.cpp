class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int ki = 0;
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums){
            pq.push(i);
            while(pq.size() > k) pq.pop();
        }
        ki = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > ki) pq.pop();
        return pq.top();
    }
};
