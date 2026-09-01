class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& vis,
             int r, int c,
             int n, int m) {

        vis[r][c] = true;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // n = rows, m = columns
            if (nr < 0 || nr >= n ||
                nc < 0 || nc >= m)
                continue;

            if (vis[nr][nc])
                continue;

            // Reverse water flow
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, vis, nr, nc, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        int n = heights.size();        // rows
        int m = heights[0].size();     // columns

        vector<vector<bool>> pacific(
            n, vector<bool>(m, false)
        );

        vector<vector<bool>> atlantic(
            n, vector<bool>(m, false)
        );

        // ----------------
        // PACIFIC
        // ----------------

        // Left column
        for(int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0, n, m);
        }

        // Top row
        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i, n, m);
        }


        // ----------------
        // ATLANTIC
        // ----------------

        // Right column
        for(int i = 0; i < n; i++) {
            dfs(heights, atlantic, i, m - 1, n, m);
        }

        // Bottom row
        for(int i = 0; i < m; i++) {
            dfs(heights, atlantic, n - 1, i, n, m);
        }


        // ----------------
        // INTERSECTION
        // ----------------

        vector<vector<int>> result;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] &&
                   atlantic[i][j]) {

                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};