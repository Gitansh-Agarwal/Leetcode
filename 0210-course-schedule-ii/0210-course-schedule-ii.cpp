class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, 
    vector<int>& orderOfCourses){
        
        vis[node]=1;
        pathVis[node]=1;
        // orderOfCourses.push_back(node);
        //traversing all the adjacent nodes.
        for(auto it: adj[node]){
            //when the given node is unvisited, do a dfs call on it to visit it.
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis, orderOfCourses) == true){
                    return true;
                }
            }
            // if the node has been previously visited but it has to be visited on the same path in order for the graph to have a cycle.
            else if(pathVis[it] == 1){//it has been visited in the same path,means cycle exist.
                return true;
            }
        }
        pathVis[node]=0;
        orderOfCourses.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //TC=O(V+E){as the given graph is a directed graph and we are doing a normal dfs check}.
        //SC=O(2*V).
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> orderOfCourses;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                // if the dfs calls returns a true means that there exists a cycle in the graph.
                if (dfsCheck(i, adj, vis, pathVis, orderOfCourses) == true)
                    return {}; // it is not possible to finish all courses as cycle exists in the graph.
            }
        }
        return orderOfCourses;// it is possible to finish all the courses as no cycle exists in the graph.
    }
};