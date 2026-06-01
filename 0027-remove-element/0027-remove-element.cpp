class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int i =0;
      
        while(i<nums.size()){
            if(nums[i]!=val){
                
                swap(nums[i], nums[k]);
                k++;
               
            }
         i++;
        }
        return k ; 
    }
};