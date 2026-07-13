class Solution {
public:
vector<int>ans;
bool dfscycle(  unordered_map<int , vector<int>>&adj ,vector<bool>&visited , vector<bool>&inrecursion , vector<int>&ans , int u  ){
    visited[u] = true ;
    inrecursion[u] = true;
  
    for(auto & v : adj[u]){
        if(visited[v] == true && inrecursion[v]== true){
            return true ;
        }
        if(!visited[v] && dfscycle(adj , visited , inrecursion , ans ,v)){
            return true ;
        }
    }
    inrecursion[u] =false;
      ans.push_back(u);
    return false ;
}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        for(auto & u :  prerequisites){
            int a = u[0];
            int b = u[1];
               adj[b].push_back(a);
        }

vector<bool>visited(numCourses , false);
vector<bool>inrecursion(numCourses , false);
vector<int>ans;
for(int i = 0 ; i<numCourses; i++){
    if(!visited[i] && dfscycle(adj , visited , inrecursion , ans , i )){ // cycle hai we cant cover courses 
         return {};
    }
}

reverse(ans.begin() ,ans.end());
return ans ;


    }
};