class Solution {
    private:
        void dfs(int startNode, vector<int> adj[], int vis[]){
            vis[startNode]=1;
            for(auto it: adj[startNode]){
                if(!vis[it]){
                    dfs(it, adj, vis);
                }
            }
        }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adj[V+1];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        int vis[V+1];
        memset( vis, 0, (V+1)*sizeof(int) );
        int cnt=0;
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};