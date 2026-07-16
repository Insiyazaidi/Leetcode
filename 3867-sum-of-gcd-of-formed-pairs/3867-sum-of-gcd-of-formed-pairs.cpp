class Solution {
public:

int gcd(int a , int b){  

   while(b!=0){
    int rem = a%b;
    a = b;
    b=rem;
   }
   return a ;
}

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n);
        maxi[0] = nums[0];
        int currmax = nums[0]; 
        vector<int>prefixgcd(n);
        prefixgcd[0] = nums[0];

        for(int i =1; i<nums.size(); i++){
              maxi[i] = max(currmax , nums[i]);
             prefixgcd[i] = gcd(nums[i] , maxi[i]);
              if(currmax<nums[i]){
                currmax = nums[i];
              }
        }
       sort(prefixgcd.begin() , prefixgcd.end());
       int i = 0;
       int j = prefixgcd.size()-1;
       long long  sum = 0;
       while(i<j){
    sum =sum+ gcd(prefixgcd[i], prefixgcd[j]);
    i++;
    j--;
       }
return sum;

    }
};