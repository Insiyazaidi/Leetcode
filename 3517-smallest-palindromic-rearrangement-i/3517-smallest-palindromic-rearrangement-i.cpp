class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
        map<char , int>mp;
            int n = s.size();
       string alpha(n , ' ');

    int middle = n/2;

// loop chlega n = 0 to n/2 -1 tk 
for(int i = 0 ; i<middle ; i++){
mp[s[i]]++;  // storing in map  
}

if(n%2!=0){  // odd length h 
alpha[middle] = s[middle];
}
 

    // map m store hogai value 
int k  =0 ;
   for(auto &it:mp){   // stored the char in ans 
    while(it.second!=0){
       alpha[k] = it.first;
       k++;
        it.second--;
    }
   }
   int j = s.size()-1  ; // eg j = 5-1 = 4
   int i = 0;
  
   while(i<j ){  // ans.size() = 3 , j - 4 , 3 
      alpha[j] = alpha[i];
      i++;
      j--; 
   }

return alpha ;
    }
};