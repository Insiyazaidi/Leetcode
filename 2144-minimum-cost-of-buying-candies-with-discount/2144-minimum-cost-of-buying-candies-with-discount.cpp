class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end());
       reverse(cost.begin() , cost.end());
       int ans = 0;  
       for(int i =0 ; i<cost.size();i++){
           if((i+1)%3!=0){  // means not divisible by 3 h toh mtlb hme include krna h 
            ans = ans+cost[i];
           }
       }
       return ans ;
    }
};