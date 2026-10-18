class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adjRev(V);

        vector<int>indgree(V,0);

        for(int i = 0;i<V;i++){
            // i -> it
            // it -> i
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indgree[i]++;
            }
        }

        queue<int>q;

        vector<int>safeNode;

        for(int i = 0;i<V;i++){
            if(indgree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNode.push_back(node);

            for(auto it : adjRev[node]){
                indgree[it]--;
                if(indgree[it] == 0) q.push(it);
            }
        }

        sort(safeNode.begin(), safeNode.end());

        return safeNode;

    }
};