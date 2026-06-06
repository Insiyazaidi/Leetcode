class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>rightsum(n ,0);
        vector<int>leftsum(n ,0);
        vector<int>ans(n ,0);
         int i = 1;  // for leftsum 
         int j = nums.size()-2; // for rightsum 
        while ( i<nums.size() && j>=0 ){
           leftsum[i ] = leftsum[i-1]+nums[i-1];
           rightsum[j] = rightsum[j+1] + nums[j+1];
           i++;
           j--;
        }
        for(int i =0 ; i<n;i++){
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;

    }
};