class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candies(ratings.size() ,1); // saari candies 1 se initalize krdi
        // left to right pass 
        int n = ratings.size();
        for(int i = 1 ; i<ratings.size();i++){
      if(ratings[i] > ratings[i-1]){
        candies[i] =   candies[i-1]+1; // toh uske purane vle m jitni candy h usse ek zyada krdo kyu ki iski rating zyda h 
      }
        }

        // right to left pass
        for(int i = n-2 ; i>=0;i-- ){
            if(ratings[i]>ratings[i+1]){
                 candies[i] = max(  candies[i] ,   candies[i+1]+1); // yha pr max isliye liya h 
                 // for eg ratings given h (2 , 3 ,1 ) aur candies (2,3,1) abhi hm 3 pr h toh agr hm direct +1 krege toh 3 pr 
                 // candy 2 hojaigi instead of 3 ,,, now we will move further to rating 2 cond satify ni hogi as 2 is not grea // then 3 ,, so now check candies (2 , 2 ,1) - i will fail kyu ki rating 3 ur 2 m candy diff honi chahiye 
                 // but hmne usko righ to left pass m change krdi toh hme right aur left pass se best ans dhundhna h 
                 // jo cond break n kre
            }
        }
        return accumulate(candies.begin() , candies.end() , 0);
    }
};