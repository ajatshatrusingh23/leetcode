class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          
        int V  = numCourses;
         vector<int> indegree(V, 0);

           vector<vector<int>> adj(V);
 
           for (auto &edge :prerequisites ) {
               int u = edge[1];
               int v = edge[0];

               adj[u].push_back(v);
               indegree[v]++;
           }

           queue<int> q;

         
           for (int i = 0; i < V; i++) {
               if (indegree[i] == 0) {
                   q.push(i);
               }
           }

            vector<int>ans;

           while (!q.empty()) {
               int node = q.front();
               q.pop();

                ans.push_back(node);

               for (auto it : adj[node]) {
                   indegree[it]--;

                   if (indegree[it] == 0) {
                       q.push(it);
                   }
               }
           }

           if (ans.size() != V)
                return {};

        return ans;
    }
};