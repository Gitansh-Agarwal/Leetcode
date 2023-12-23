class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> visited;
        
        int cx = 0;
        int cy = 0;
        
        for(auto i : path){
            visited[{cx, cy}] = true;
            
            if(i == 'N')
                --cx;
            else if(i == 'S')
                ++cx;
            else if(i == 'E')
                ++cy;
            else
                --cy;
            
            if(visited.count({cx ,cy}))
                return true;
        }
        return false;
    }
};