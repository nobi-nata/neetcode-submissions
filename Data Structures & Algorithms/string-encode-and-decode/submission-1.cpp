class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            s += strs[i];
            s += "++##";

        }
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int i = 0;
        string str = "";
        vector<string> result;
        while(i < n){
            if(s[i] == '+' && s[i+1] == '+' && s[i+2] == '#' && s[i+3] == '#'){
                result.push_back(str);
                str = "";
                i += 4;
                continue;
            }
            str += s[i];
            i++;
        }
        return result;
    }
};
