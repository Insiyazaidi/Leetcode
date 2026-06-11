class Solution {
public:

 static const int MOD = 1e9 + 7;
   vector<vector<int>> adj;
int maxdepth = 0;

long long modPow(long long base, long long exp) {
    long long ans = 1;

    while (exp > 0) {
        if (exp & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

void dfs (int node , int parent , int depth){
    maxdepth = max(maxdepth , depth);
    for(int connecting: adj[node]){   // for(int connecting : {2,3})  , first iteration mai 2 use hoga , second mai 3 use hoga 
if(connecting == parent) continue;
dfs(connecting , node , depth+1);
    }

}

    int assignEdgeWeights(vector<vector<int>>& edges) {
       int n = edges.size()+1;  // nodes = edges+1 so here n -  no of nodes 
       adj.resize(n+1); // n - nodes , here size is n+1 because adj[0] is not used bcz node numbering start from 1
       for(auto &e : edges){  // iterating edges to make adj list (containing neighbour of each node )
       int u = e[0];  
       int v = e[1];
       adj[u].push_back(v);
  adj[v].push_back(u);
       }

       dfs(1, 0 ,0 ) ; // node , parent , depth 
       if(maxdepth ==0) return 0;
  return (int)modPow(2, maxdepth - 1);

    }
};