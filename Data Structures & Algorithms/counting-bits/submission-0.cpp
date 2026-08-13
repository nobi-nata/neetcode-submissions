class Solution {
public:
    int count(int n){
        int cnt = 0;
        while(n){
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int num = count(i);
            ans.push_back(num);
        }
        return ans;
    }
};
