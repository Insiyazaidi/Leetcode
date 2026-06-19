class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int ans = 0;
       int curr = 0;
       for(int i =0 ; i<gain.size(); i++){
        int net = gain[i] + curr;
        curr = net;
        ans = max(ans , net);
       } 
       return ans ;
    }
};