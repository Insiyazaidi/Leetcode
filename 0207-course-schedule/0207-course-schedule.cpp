class Solution {
public:
 bool dfscycle(    unordered_map<int , vector<int>>&adj ,vector<bool>&visited , int u ,vector<bool>&inrecursion  ){
visited[u] = true;
inrecursion[u] = true;
for(auto &v: adj[u]){
     if(visited[v] == true && inrecursion[v]==true){
              return true;
          }
           
if(!visited[v] &&dfscycle(adj , visited , v,inrecursion) ){
  
return true;
 

}
}
inrecursion[u]= false;
return false;


}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int , vector<int>>adj;
        for(int u = 0 ; u<prerequisites.size(); u++){
        int a = prerequisites[u][0];
        int b = prerequisites[u][1];
        adj[b].push_back(a);    
        }
vector<bool>visited(n, false);
vector<bool>inrecursion(n, false);
for(int i =0; i<n; i++){
    if(!visited[i] && dfscycle(adj , visited , i , inrecursion )){ // cycle h 
return false;
    }
}
    return true; 
     
    }
};