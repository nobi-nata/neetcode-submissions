class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        int cnt = 0;
        while(n){
            if(n & 1){
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }
};
