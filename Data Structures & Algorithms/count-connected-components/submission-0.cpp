class Solution {
public:
    void bfs(vector<vector<int>> &adj, vector<int> &vis, int node) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int s = q.size();

            for(int i = 0; i < s; i++){
                int val = q.front();
                q.pop();
                for(auto e : adj[val]){
                    if(vis[e]) continue;
                    else{ 
                        q.push(e);
                        vis[e] = 1;
                    }
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){ 
                bfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};

    

