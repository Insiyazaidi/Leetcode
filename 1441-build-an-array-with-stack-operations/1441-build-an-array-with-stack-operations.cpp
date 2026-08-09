class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        // for eg n = 5 - possible values  1 , 2 , 3 , 4 , 5
        // let target be - [ 1 , 3 , 5] 
   
        int sv = 1;   // stream value 
        int i =0 ;
        stack<int>st;  // it is mandatory to push element even if not req
         while (sv<=n){
if(i>=target.size()){
    break;
}
         st.push(sv);
         ans.push_back("Push");
         sv++;
         if(!st.empty() && i<target.size() &&  st.top()!=target[i]){  // agr req nhi h 
            st.pop();
             ans.push_back("Pop");
         }
         else{
            i++; // yaani mil gya h 
         }
         }
         return ans;

    }
};