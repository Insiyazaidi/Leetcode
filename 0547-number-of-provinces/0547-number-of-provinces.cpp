class Solution {
public:
void bfs(vector<vector<int>>& isConnected , vector<bool>&visited , int u ){
    if(visited[u]==true){
        return;
    }
    visited[u] = true;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int src = q.front();
        q.pop();
        for(int v =0 ; v<isConnected.size();v++){
            if(!visited[v] && isConnected[src][v]==1){
               q.push(v);
               visited[v]= true;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       queue<int>q;
       int n = isConnected.size();
       vector<bool>visited(n , false) ;
       int count =0;
       for(int i =0 ; i<n ; i++){
        if(!visited[i] ){
            bfs(isConnected , visited , i);
            count++;
        }
       }
       return count;
    }
};