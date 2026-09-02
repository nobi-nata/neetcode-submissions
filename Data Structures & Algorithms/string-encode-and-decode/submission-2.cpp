class Solution {
public:
    vector<int> sizes;
    string encode(vector<string>& strs) {
        string s = "";
        for(auto str : strs){
            sizes.push_back(str.size());
            s.append(str);
        }
        return s;
    }

    vector<string> decode(string s) {
        int n = sizes.size();
        int i = 0;
        int idx = 0;
        vector<string> result;
        while(i < n){
            int size = sizes[i]; 
            string str = s.substr(idx, size);
            result.push_back(str);
            idx += size;
            i++;
        }
        return result;
    }
};
