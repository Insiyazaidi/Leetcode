class Solution {
public:
int MOD = 1e9+7;
  int t[201][201][201]; // 200 max value h nums[i] ki 
 int solve (vector<int>& nums , int idx , int firstgcd , int secondgcd){ // eventually we dont need exact seq so only gcd is  //    passed  as parameter 
if(idx==nums.size()){
  bool isnotempty = firstgcd !=0 && secondgcd!=0;
  bool matchgcd  = firstgcd ==secondgcd;
  return (isnotempty && matchgcd) ? 1: 0; // agr notempty+matchgcd toh 1 return krdo ek match milgya
}
if(t[idx][firstgcd][secondgcd] !=-1){
  return t[idx][firstgcd][secondgcd];
}

int skip = solve(nums , idx+1 , firstgcd , secondgcd);
int take1  = solve(nums , idx+1 , __gcd(firstgcd , nums[idx]) , secondgcd);
int take2 = solve(nums , idx+1 , firstgcd , __gcd(secondgcd , nums[idx])  );

           return     t[idx][firstgcd][secondgcd] =  ( 0LL+skip + take1 + take2 )%MOD ;
}
    int subsequencePairCount(vector<int>& nums) {
        memset(t , -1 , sizeof(t));
      return  solve(nums ,  0 , 0 , 0);
    }
};