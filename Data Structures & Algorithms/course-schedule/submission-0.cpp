class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites){
            int second = p[0];
            int first = p[1];
            adj[first].push_back(second);
            indegree[second]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int completed = 0;

        while(!q.empty()){
            int course = q.front();
            q.pop();

            completed++;
            for(int next : adj[course]){
                indegree[next]--;

                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};