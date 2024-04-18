class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, set<pair<int, int>>& visited){
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0 or grid[i][j]==0){
            return 1;
        }

        if(visited.find(make_pair(i,j)) != visited.end()){
            return 0;
        }

        visited.insert(make_pair(i,j));
        int perimeter = dfs(i-1, j, grid, visited);
        perimeter+=dfs(i, j+1, grid, visited);
        perimeter+=dfs(i+1, j, grid, visited);
        perimeter+=dfs(i, j-1, grid, visited);

        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        
        
        
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return dfs(i, j, grid, visited);
                }
            }
        }
        //The below return statement is temporary, it doesn't execute instead it is used to return a value in all control paths of a non-void function.
        return 0;
    }
};