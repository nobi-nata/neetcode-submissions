class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0;
        int hash[26] = {0};
        int mf = 0;
        int ans = 0;
        while(r < n){
            hash[s[r] - 'A']++;

            mf = max(mf, hash[s[r] - 'A']);

            if(((r-l+1) - mf )> k){
                hash[s[l]-'A']--;
                l++;
            }

            if(((r-l+1) - mf ) <= k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;

    }
};