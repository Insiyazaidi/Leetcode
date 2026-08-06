class Solution {
public:
 const int MOD = 1e9+7;
vector<int>leftsmallidx(vector<int>&arr){
    stack<int>st;
    vector<int>res(arr.size());
    for(int i = 0 ; i<arr.size() ; i++){
        if(st.empty()){
         res[i] = -1;
        }
        else{
            while(!st.empty() && arr[st.top()] >arr[i] ){
                st.pop();
 // ag pop krke krte stack empty higya mtlb koi element h hi ni chota isse 
 // agr h koi toh vo toh idx ho hoga 
            }
             res[i] = st.empty() ? -1 : st.top();
           
        }
        st.push(i);
    }
    return res;
}



vector<int>rightsmallidx(vector<int>&arr){
    stack<int>st;
    vector<int>res(arr.size());
    for(int  i = arr.size()-1 ; i>=0 ; i--){
        if(st.empty()){
         res[i] = arr.size(); // out of bound idx daaal diya h 
        }
        else{
            while(!st.empty() && arr[st.top()] >=arr[i] ){
                st.pop();
  // ag pop krke krte stack empty higya mtlb koi element h hi ni chota isse 
 // agr h koi toh vo toh idx ho hoga 
            }
            res[i] = st.empty() ? arr.size() : st.top();
           
        }
        st.push(i);
    }
    return res;
}

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>prevsmall = leftsmallidx( arr);
        vector<int>nextsmall =  rightsmallidx( arr );
 long long  finalsum = 0; 
        for(int i = 0 ; i< n ; i++){
            int leftcountele = i-prevsmall[i]   ;
            int rightcountele = nextsmall[i] - i ; 
                 long long contribution = 1LL * leftcountele * rightcountele * arr[i];

            finalsum = (finalsum + contribution) % MOD;
        }
        return finalsum;
    }
};