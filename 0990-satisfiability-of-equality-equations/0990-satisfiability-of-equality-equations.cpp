class Solution {
public:
vector<int>parent; // total char can be 26 
vector<int>rank;

 int find( int i ){
 
 if(i == parent[i]){  // 5 ka parent 3 , 3 k parent 1 , 1 ka parent 4 , 4 ka parent 4 hai toh final ans 4 hai 
return i ;
 }

return parent[i] = find(parent[i] );

}

void performunion(int x , int y ){
    int xp = find(x);
    int yp = find(y);
    if(xp == yp){  // dono ke parent equal no need to union already in same set 
        return ;
    }
// do union ie make  one as parent  based on ranking 

if(rank[xp]>rank[yp]){
    parent[yp] = xp;
}

 else if(rank[yp]>rank[xp]){
    parent[xp] = yp;
}
else {
    parent[yp] = xp; // x ko parent bna diya 
    rank[xp]++;  // aur x ki rank ++ krdi 
} 

}


    bool equationsPossible(vector<string>& equations) {
      parent.resize(26);
rank.resize(26, 0);

for(int i = 0 ; i<26 ; i++){
    parent[i] = i;  // khud ko khud ka hi parent bna diya h 
}
for(auto &s : equations){
    // s will represent  one string for each loop 

if(s[1] == '='){  // agr equal to vli string h toh process kro 
 performunion(s[0]-'a' , s[3]-'a'); // doing union using compression and rank 
}
}
for(auto &s : equations){
if(s[1] == '!'){  //  ab not equal vla case h 
  
  int xp = find(s[0]-'a');
  int yp = find(s[3] -'a');

  if(xp == yp){  // dono ke parents same aarhe h but given not equal h toh false return hoga 
    return false ;
  }


}
}


  return true ;      
    }
};