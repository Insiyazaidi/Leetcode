class Solution {
public:

bool bfstrav(vector<vector<int>>&adj , int currcolour , vector<int>&colour , int u){
    colour[u] = currcolour; // colouring 
    queue<int>q;
    q.push(u);
    while(!q.empty()){
int curr = q.front();
q.pop();
for(auto &v:adj[curr]){
    if(colour[v] == colour[curr]){
        return false;
    }
    if(colour[v] == -1){
        colour[v] = 1-colour[curr];
        q.push(v);
    }
}
    }

    return true;
}

    bool isBipartite(vector<vector<int>>&adj) {
        int V = adj.size();
        vector<int>colour(V , -1);
        // red = 1 , green - 0 
        for(int i = 0 ; i<V ; i++){
           if(colour[i] == -1 && bfstrav(adj , 0 , colour , i ) == false){
            return false;
           }
        }
        return true;
    }
};