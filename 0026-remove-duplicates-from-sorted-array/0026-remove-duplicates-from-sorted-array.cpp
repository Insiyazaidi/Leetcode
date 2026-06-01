class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1;
        int j = 1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                i++;
            }
            else{
                nums[j] = nums[i];
                i++;
                j++;
            }
        }
        return j;
    }
};