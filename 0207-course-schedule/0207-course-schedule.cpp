class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

    vector<vector<int>> adj(V);

    for (int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][1]; // ⚠️ fix edge direction
        int v = prerequisites[i][0];
        adj[u].push_back(v); // edge: u -> v (take u before v)
    }

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses; 
    }
};