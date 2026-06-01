class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int count =1;
      int i = 1;
      int j =1;
      while(i<nums.size()){
        if(nums[i]!=nums[i-1]){
            count =1;
        }
        else{
            count++;
        }
        if(count<=2){
        nums[j] = nums[i];
        j++;
        }
        i++;
       
      }
      return j;  
    }
};