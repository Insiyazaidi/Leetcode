class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int i =0;
       int j = nums.size()-1;
       vector<int>ans(nums.size() , 0);
       int l =0;
       int m = ans.size()-1;
       while(i<nums.size()&& j>=0){
if(nums[i]<pivot){
    ans[l] = nums[i];
  
    l++;
}
 if(nums[j]>pivot){
     ans[m] = nums[j];
  
    m--;
}
i++;
j--;
       } 

       while(l<=m){
       ans[l] = pivot;
       l++;
       }
       return ans ;
    }
};