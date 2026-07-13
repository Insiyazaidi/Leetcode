class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       // SOLVING USING BFSS
       queue<int>q;
       vector<int>ans;
       for(int i = 1 ; i<=8 ; i++){
        q.push(i);
       } 
       while(!q.empty()){
        int curr = q.front();
        if(curr>=low && curr<=high){
            ans.push_back(curr);
        }
        q.pop();
       int ld = curr%10;
       if(ld+1 <=9){
int newnumb = curr*10+(ld+1);
        q.push(newnumb);
       }
        
       }
       return ans ;
    }
};