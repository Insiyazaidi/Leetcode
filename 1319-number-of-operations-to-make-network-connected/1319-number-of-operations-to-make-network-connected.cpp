class Solution {
public:

 void performunion(int x , int y , vector<int>&parent , vector<int>&rank){

int xp = find(x , parent);
int yp = find(y , parent);
if(xp == yp){
    return;
}
if(rank[xp] > rank[yp]){
    parent[yp] = xp;
}
else if(rank[yp] > rank[xp]){
    parent[xp] = yp;
}
else if(rank[xp] == rank[yp]){
     parent[yp] = xp;
     rank[xp]++;
}

}


int find( int i , vector<int>&parent ){
if(parent[i] == i){
    return  i;
}
return parent[i] = find(parent[i] , parent);
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = n;

        int edges = connections.size();
        if(edges < n-1){  // edges suff nhi h 
            return -1;  // n comp h edges n-1 nhi h toh -1 return krdo 
        }
     vector<int>parent(n );
     // khud ko khud ka parent 
     for(int i = 0 ; i<n;i++){
        parent[i] = i;
     }
      vector<int>rank(n , 0);
        for(auto &e : connections){
            int x = e[0];
            int y = e[1];
            int xp = find(x , parent) ;
            int yp = find(y , parent);
            if(xp !=yp){
                performunion(xp , yp , parent , rank);
                components--;
            }
        }
        // ab for eg comp bache 3 
        return components-1; // yaani 2 edges chahiye 
    }
};