class Solution {
    private:
        bool bfs(int start, vector<vector<int>>&graph, int color[]){
            color[start]=0;
            queue<int> q;
            q.push(start);
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                
                for(auto it: graph[node]){
                    //if the adjacent node is not yet coloured, we colour it with the opposite color to that of the (node).
                    if(color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    // the neighbour is already coloured, then check is the adjacent guy have the same colour, if yes, then someone must have coloured it on some other path. 
                    else if(color[it] == color[node]){
                        return false;
                    }
                }
            }
            return true;
        }
    
    
    bool dfs(int start, int colorVal, vector<vector<int>>&graph, int color[]){
            color[start]=colorVal;
                
            for(auto it: graph[start]){
                //if the adjacent node is not yet coloured, we colour it with the opposite color to that of the (node).
                if(color[it] == -1){

                    if(dfs(it, !color[start], graph, color) == false){
                        return false;
                    }

                }
                // the neighbour is already coloured, then check is the adjacent guy have the same colour, if yes, then someone must have coloured it on some other path. 
                else if(color[it] == color[start]){
                    return false;
                }
            }
            
            return true;
        }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //Using BFS Traversal.
        //TC=O(N*M){BFS Traversal} + O(V){for connected components}.
        //SC=O(N*M).{queue space} + O(V){color array space}.
//         int V=graph.size();
//         int color[V];
//         for(int i=0; i<V; i++){
//             color[i]=-1;
//         }
        
//         //for connected components.
//         for(int i=0; i<V; i++){
//             if(color[i] == -1){
//                 if(bfs(i, graph, color) == false){
//                     return false;
//                 }
//             }
//         }
//         return true;
        
        
        
        
        //Using DFS Traversal.
        //TC=O(N*M){BFS Traversal} + O(V){for connected components}.
        //SC=O(N*M).{Recursive Stack Space} + O(V){color array space}.
        int V=graph.size();
        int color[V];
        for(int i=0; i<V; i++){
            color[i]=-1;
        }
        
        //for connected components.
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};