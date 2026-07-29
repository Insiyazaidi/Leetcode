# define ll long long int 
class Solution {
public:

  int  ncr(int n , int r , int k ){
    if(r >n-r){
        r = n-r;
    }
    long long res = 1;
    for(int i = 1 ; i<=r ; i++){
        res = res*(n-i+1)/i;
        if(res>=k){
            return k;
        }
    }
    return res;
  }
    string smallestPalindrome(string s, int k) {
        vector<int>freq(26 , 0);
        int n  = s.size();
        string result="";
        string lefthalf = s.substr(0 , n/2);
        for(int i =0 ;i<lefthalf.size() ; i++){
            freq[lefthalf[i] -'a']++;
        }
        // left + middle + reverse(left)
        // now use these freq to find possible combinations , count permutation
        // a-2 , b -1 , c-3 
        
      for(int i = 0 ; i<n/2 ; i++){
           for(int j = 0 ; j<26;j++){  // saare char 
            if(freq[j] !=0){  // agr vo char aarha h 
              ll ways = 1;
              ll leftpos = n/2-i-1; // n/2 position thi , i pos tk fill krdia , 1 just fill krne vli hu 
              freq[j]--;// using that char so freq -- krdo 


              for(int c = 0 ; c<26 ; c++){  // filling out left position 
              if(freq[c]!=0){
                ways = ways*ncr(leftpos , freq[c] ,k ) ; // leftpos - n , freq[c] - r 
                leftpos = leftpos-freq[c] ; // total 20 pos thi usmai se 5 pos pr hmne likh diya 
              }
              if(ways>=k){  
                break;
              }
              }

if(ways>=k){
    result += ('a'+j);
    break;
}
else{
    k = k-ways;
    freq[j]++; // yani vo char ni aaiga us pos mai 
}
       }
           }
      }

if(result.size()!=n/2){  // agr hm string ni bna pai 
    return "";
}
string ans = result;
if(s.size()%2!=0){
    ans = ans+s[n/2]; // vo middle element add krdo 
}
reverse(result.begin() , result.end());
ans = ans+result;
return ans ;

    }
};