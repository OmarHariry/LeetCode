class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree (numCourses);
        
        for(auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        queue<int>q;
        for(int i=0; i< numCourses;++i) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        int visited = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ++visited;
            
            for (auto neigh : adjList[node]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        
        
        return visited == numCourses;
    }
};