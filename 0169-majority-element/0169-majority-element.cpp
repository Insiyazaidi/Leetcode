class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ans = nums[0];
      int freq = 1;
      for(int i =1;i<nums.size();i++){
        if(nums[i]==ans){
            freq++;
        }
        else if(nums[i]!=ans){
            freq--;
        }
        if(freq==0){  // agr freq 0 h toh mtlb cancel out hoga hmara candidate 
        // ab current number ko candidate bnate h 
        // aur uski freq =1 starting se 1 krte h .. kyu ki ek baar toh aaaya jh vo
            ans = nums[i];
            freq=1; 
        }
      }

      return ans ;   
    }
};