class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;
        
        vector<vector<int>>adjList(n);
        vector<int>visited(n, 0);

        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int>q;
        q.push(source);
        visited[source] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adjList[node].size(); ++i) {
                if (adjList[node][i] == destination)
                    return true;
                if (!visited[adjList[node][i]]) {
                    visited[adjList[node][i]] = 1;
                    q.push(adjList[node][i]);
                }
            }
        }

        return false;
    }
};