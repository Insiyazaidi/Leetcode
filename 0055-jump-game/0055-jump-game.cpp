class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
      for(int i =0;i<nums.size();i++){
          if(i>reachable){
    return false ;
  }
 int curr = nums[i]+i;
  reachable = max(reachable , curr);

      }
      return true;  
    }
};