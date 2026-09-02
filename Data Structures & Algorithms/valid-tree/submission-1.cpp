class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;
        q.push({0, -1});
        vis[0] = 1;

        while(!q.empty()){
            int s = q.size();

            for(int i = 0; i < s; i++){
                auto [node, parent] = q.front();
                q.pop();
                for(auto e : adj[node]){
                    if(e == parent) continue;
                    else if(e != parent && vis[e]){
                        return false;
                    }
                    else{ 
                        q.push({e, node});
                        vis[e] = 1;
                    }
                }
            }
        }
        for(auto v : vis){
            if(v == 0) return false;
        }
        return true;
    }
};
