// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool helper(vector<int> adj[], vector<int> visited, int i, int parent){
        visited[i] = 1;
        bool ans = false;
        for(auto v:adj[i]){
            if(visited[v] == 1 && parent!=v)
                return true;
            if(visited[v] == 0)
                ans |= helper(adj, visited, v, i);
            if(ans)
                return ans;
        }
        
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        if(V == 0)
            return false;
        vector<int> visited(V, 0);
        bool ans;
        for(int i = 0;i<V;i++){
            if(visited[i] == 0){
                ans = helper(adj, visited, i, -1);
            }
            if(ans)
                return ans;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends