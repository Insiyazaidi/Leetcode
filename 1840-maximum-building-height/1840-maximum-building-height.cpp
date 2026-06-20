class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
       
        restrictions.push_back({1 ,0}); // first building 
         restrictions.push_back({n ,n-1}); // dummy building for right to left pass comparison
         sort( restrictions.begin() ,  restrictions.end());  // sort krdiya 
 int N=  restrictions.size();

 // left to right pass ....
         for(int i = 1 ; i< N ; i++){
         int distance = restrictions[i][0] - restrictions[i-1][0]; // distance btw the two building in restriction vector 
        restrictions[i][1] = min( restrictions[i][1] ,    distance+restrictions[i-1][1]   );
       // height can be - min(already given res ,  disbtw buil+heightofprev build  )

         }

// right to left pass 

for(int i = N-2 ; i>=0; i--){
   int distance = restrictions[i+1][0] - restrictions[i][0];
 restrictions[i][1] = min( restrictions[i][1] ,    distance+restrictions[i+1][1] );
}

int result = 0;
for(int i=1;i<N;i++){

int leftpos =  restrictions[i-1][0];  // id1
int leftheight =  restrictions[i-1][1]; // h1 
int currpos =  restrictions[i][0];  // id2 
int currheight =  restrictions[i][1];  // h2

int disbtw = currpos-leftpos;
int htdiff = abs(currheight-leftheight);
int peak = max(leftheight , currheight) + (disbtw-htdiff)/2;
result = max(result , peak);


}

return result;
    } 
};