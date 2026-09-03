class Solution {
public:
    int isPalindrome(string s, int left, int right){
        int cnt = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            cnt++;
        } 
        return cnt;
    }

    int countSubstrings(string s) {
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            int lenOdd = isPalindrome(s, i, i);
            int lenEven = isPalindrome(s, i, i+1);

            maxLen += lenOdd;
            maxLen += lenEven;
        }
        return maxLen;
    }
};

