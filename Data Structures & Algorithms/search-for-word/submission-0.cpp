class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                string s = "";
                if(check(board, word, s, i, j, vis)) return true;
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, string& s, int row, int col, vector<vector<int>>& vis){
        vis[row][col] = 1;
        s += board[row][col];
        if(word[s.size()-1] != s[s.size()-1]) {
            vis[row][col] = 0;
            s.pop_back();
            return false;
        }

        if(s.size() == word.size()) return true;
        if(s.size() > word.size()) return false;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for(int i = 0; i < 4; i++){
            int r = dr[i] + row;
            int c = dc[i] + col;
            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && !vis[r][c]){
                if(check(board, word, s, r, c, vis)) return true;
            }
        }
        vis[row][col] = 0;
        s.pop_back();
        return false;
    }
};