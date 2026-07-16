class Solution {
public:
int MOD = 1e9+7;
int solve(vector<int>& nums , int i , int firstgcd , int secondgcd){
int n = nums.size();
        int maxel = *max_element(begin(nums) , end(nums));
        int  t[n+1][maxel+1][maxel+1];

        // base case in loop 
        // t[n][firstgcd][secondgcd] - n is fixed , firstgcd and secondgcd ke saari possibility l rhe h 
        for(int firstgcd = 0 ; firstgcd<=maxel; firstgcd++){
          for(int secondgcd = 0 ;secondgcd<=maxel; secondgcd++ ){
           bool isnotempty = firstgcd!=0 && secondgcd!=0;
           bool match = firstgcd == secondgcd;
           t[n][firstgcd][secondgcd] =   (isnotempty && match)? 1: 0;
          }
        }

        for(int i = n-1 ; i>=0 ; i--){
            for(int firstgcd = maxel ; firstgcd>=0; firstgcd--){
                for(int secondgcd = maxel ; secondgcd>=0; secondgcd--){
                     int skip = t[i+1][firstgcd][secondgcd];
                     int take1 = t[i+1][(__gcd(firstgcd , nums[i]))][secondgcd];
                     int take2 = t[i+1][firstgcd][(__gcd(secondgcd , nums[i]))];
                     t[i][firstgcd][secondgcd] = (0LL + skip+take1+take2)%MOD;
                }
            }
        }
        return t[0][0][0];
}
     
    int subsequencePairCount(vector<int>& nums) {
 return solve(nums , 0 , 0 ,0); // return the DP cell corresponding to the original recursive call.
    
    }
};