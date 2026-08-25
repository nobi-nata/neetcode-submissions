class Solution {
public:
    void check(vector<vector<char>>& grid, int n, int m, vector<vector<int>>& vis, int r, int c){
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]){
                check(grid, n, m, vis, nr, nc);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    check(grid, n, m, vis, i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};