class Solution {
public:

bool dfstrav(vector<vector<int>>&adj , int currcolour , vector<int>&colour , int u){
    colour[u] = currcolour; // colouring 
    for(auto &v:adj[u]){
        if(colour[v] == colour[u]){
            return false;
        }
        if(colour[v] == -1){ // colour ni hua v h colour kro
       int  colv = 1-currcolour; // changing red to green , green to red
         if(dfstrav(adj , colv , colour , v) == false){
            return false;
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
           if(colour[i] == -1 && dfstrav(adj , 0 , colour , i ) == false){
            return false;
           }
        }
        return true;
    }
};