class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        //TC=O(V+E){as the given graph is a directed graph}.
        vis[node]=1;
        pathVis[node]=1;

        //traversing all the adjacent nodes.
        for(auto it: adj[node]){
            //when the given node is unvisited, do a dfs call on it to visit it.
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true){
                    return true;
                }
            }
            // if the node has been previously visited but it has to be visited on the same path in order for the graph to have a cycle.
            else if(pathVis[it] == 1){//it has been visited in the same path,means cycle exist.
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                // if the dfs calls returns a true means that there exists a cycle in the graph.
                if (dfsCheck(i, adj, vis, pathVis) == true)
                    return false; // it is not possible to finish all courses as cycle exists in the graph.
            }
        }
        return true;// it is possible to finish all the courses as no cycle exists in the graph.
    }
};