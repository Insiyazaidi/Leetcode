class Solution {
public:

void dfs( vector<vector<int>>&adj  , vector<bool>&visited , int u){
    if(visited[u]==true){
        return;
    }
    visited[u] = true;
    for(auto &v:adj[u]){
        if(!visited[v]){
            dfs(adj , visited , v);
        }
    }
} 

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i =0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected.size() ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                
                }
            }
        }
int count=0;
vector<bool>visited(adj.size(),false);
for(int i =0; i<adj.size(); i++){
    if(!visited[i]){
        dfs(adj , visited , i);
        count++;
    }
}


return count;



    }
};