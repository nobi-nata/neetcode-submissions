class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return tolower(c);
        });
        int n = s.length() - 1;
        int i = 0;
        while(i < n){
            cout << s[i] << ' ' << s[n] << endl;
            int strt = 0, end = 0;
            cout << strt << ' ' << end << endl;
            if(s[i] == ' '){
                i++; continue;
            }
            if(s[n] == ' '){
                n--; continue;
            }
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                strt = 1;
            }
            cout << strt << ' ' << end << endl;
            if((s[n] >= 'a' && s[n] <= 'z') || (s[n] >= '0' && s[n] <= '9')){
                end = 1;
            }
            cout << strt << ' ' << end << endl;
            if(!strt){
                i++;
                continue;
            }
            if(!end){
                n--;
                continue;
            }
            if(s[i] != s[n]) return false;
            i++;
            n--;
        }
        return true;
    }
};
