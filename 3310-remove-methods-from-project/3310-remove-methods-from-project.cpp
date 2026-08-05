class Solution {
public:
vector<int>ans; 
 vector<int> bfstraverse(int mainnode  ,vector<bool>&suspicious  , unordered_map<int , vector<int>>&adj , vector<bool>&visited ,  vector<vector<int>>& invocations , int n  ){
queue<int>q;
q.push(mainnode);
visited[mainnode] = true;
suspicious[mainnode] = true;
while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto &v : adj[curr]){
        if(!visited[v]){
            suspicious[v] = true;
            visited[v] = true;
          q.push(v); 
        }
    } 
}

// nw check if non suspicious node is pointing out to suspicious or not ... 
for(int i = 0 ; i<suspicious.size(); i++){
    if(suspicious[i] == false){  // a non susp 
        for(auto &v : adj[i]){
            if(suspicious[v] == true){  // pointing to sus
                
for(int i=0;i<n;i++) ans.push_back(i);  // return all method 
return ans; 
            } 
        
        }

    }
}

// agr aisa nhi h toh ... non suspi vlo ko apne ans vec m daal do 

for(int i = 0 ; i<suspicious.size() ; i++){
    if(suspicious[i] == false){
        ans.push_back(i);
    }
}

return ans ;
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
// traversal dfs  or bfs .. 
// find the node that can be reached using k and mark them suspicious 
// now if non suspicious node invoke suspicious removal is not posssible 
// if removal is possible -> then put non suspicious nodes in vector and return 

vector<bool>suspicious(n , false);
vector<bool>visited(n , false);
unordered_map<int , vector<int>>adj;
for(auto &e: invocations){
    int u = e[0];
    int v = e[1];
adj[u].push_back(v);
}

 return  bfstraverse( k , suspicious, adj  , visited , invocations , n);





    }
};