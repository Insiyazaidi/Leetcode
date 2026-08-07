class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>st;
        int i =0;
        int j = 0;
     while(i<n){
          st.push(pushed[i]); // daal te rho elements 
          i++;

while( !st.empty() && j < n && st.top() == popped[j] ){
st.pop();
j++;
}
     }
     if(st.empty()){
        return true;
     }  
     else{
        return false;
     } 
    }
};