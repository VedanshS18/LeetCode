class Solution {
public:

    bool isCycleUndirDFS(int src, int par, vector<bool> &vis , vector<vector<int>>& adj){
        vis[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                if(isCycleUndirDFS(v, src, vis, adj)){
                    return true;
                }
            }else if(v != par){
                return true;
            }
        }
        return false;
    }

    

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n+1, false);

            if(isCycleUndirDFS(u, -1, vis, adj)){
                return edge;
            }
        }
        return{};
    }
};