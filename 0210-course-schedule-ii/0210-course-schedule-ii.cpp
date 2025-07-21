class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
    vector<vector<int>> adj(V);

    for (int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u);   
    }

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

   
    if (topo.size() != V)
        return {};

    return topo;

    }
};