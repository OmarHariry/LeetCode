class Solution {
public:
    void bfs (int node, vector<vector<int>>isConnected, vector<int> &visited) {
        queue<int>q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()) {
            node = q.front();
            q.pop();
            
            for(int i=0;i<isConnected.size();++i) {
                if(isConnected[node][i] && !visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        int n = isConnected.size();
        vector<int>visited(n,0);
        
        for(int i=0; i<n ;++i) {
            if(!visited[i]) {
                ++province;
                bfs(i, isConnected, visited);
            }
        }
        
        return province;
    }
};