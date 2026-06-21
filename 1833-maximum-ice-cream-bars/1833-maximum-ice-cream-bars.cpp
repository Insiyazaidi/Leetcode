class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      map<int , int>count;
      int ans =0;
      for(int i=0;i<costs.size(); i++){
        count[costs[i]]++;
      } 
  for(auto &it : count){
  long long price = (long long)it.first * it.second;
    if(price<=coins){ // coins zyada h hmare pass 
        coins = coins-price;
        ans = ans+it.second;
    }
    else if(price>coins){
ans = ans+(coins/it.first) ; // agr price =10 h , ek icecream - 2 ki h , freq - 5 , toh hm actually - 4 ice cream hi khreed skte h 
// 9/2 = 4  vhi neekala h directly 
return ans ;

    }
    

  } 
   return ans;
    }
};