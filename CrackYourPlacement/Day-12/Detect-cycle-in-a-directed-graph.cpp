// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int>&vis, vector<int>&dfsrec, int i){
        vis[i] = 1;
        dfsrec[i] = 1;
        
        bool ans = false;
        for(auto v:adj[i]){
            if(dfsrec[v] == 1)
                return true;
            if(vis[v] == 0)
                ans |= dfs(adj, vis, dfsrec, v);
            if(ans)
                return ans;
        }
        dfsrec[i] = 0;
        return ans;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), dfsrec(V, 0);
        bool ans = false;
        for(int i = 0;i<V;i++){
            if(vis[i] == 0)
                ans |= dfs(adj, vis, dfsrec, i);
            if(ans)
                return ans;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends