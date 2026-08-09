class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       stack<int>st;
       int n = nums.size();
       int num3 = INT_MIN;  // middle one 
       // last one is handled by stroing in stack 
       // and first one is just comparing if nums[i] is found smaller than nums3 then return true found all 
       for(int i = n-1 ; i>=0 ; i--){
           if(nums[i] < num3){
            return true;
           }
           while(!st.empty() && st.top() <nums[i]){
           num3 =  st.top();
            st.pop();
           }
           st.push(nums[i]);
           
       } 
       return false;
    }
};