class Solution {
public:

    bool isCycleUndirBFS(int src, vector<bool> &vis , vector<vector<int>>& adj){
        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for(int v: adj[u]){
                if(!vis[v]){
                    q.push({v, u});
                    vis[v] = true;
                }else if(v != parU){
                    return true;
                }
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

            if(isCycleUndirBFS(u, vis, adj)){
                return edge;
            }
        }
        return{};
    }
};