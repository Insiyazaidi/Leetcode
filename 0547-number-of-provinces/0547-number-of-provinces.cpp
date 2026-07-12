class Solution {
public:

void dfs( vector<vector<int>>&isConnected , vector<bool>&visited , int u){
    if(visited[u]==true){
        return;
    }
    visited[u] = true;
for(int v = 0 ; v<isConnected.size(); v++){
    if(isConnected[u][v]==1 && !visited[v]){ // direct vhi traverse krliya 
        dfs(isConnected , visited , v);
    }
}

  //  for(auto &v:adj[u]){
    //     if(!visited[v]){
    //         dfs(adj , visited , v);
    //     }
    // }
} 

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
      //  vector<vector<int>>adj(n);
        // for(int i =0; i<isConnected.size(); i++){
        //     for(int j = 0; j<isConnected.size() ; j++){
        //         if(i!=j && isConnected[i][j]==1){
        //             adj[i].push_back(j);
                
        //         }
        //     }
        // }

int count=0;
vector<bool>visited(n,false);
for(int i =0; i<n; i++){
    if(!visited[i]){
        dfs(isConnected , visited , i);
        count++;
    }
}


return count;



    }
};