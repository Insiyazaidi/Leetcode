class Solution {
public:
    int minimumPushes(string word) {
        // ismai alphabets distinct nhi h .. main difference 
        int n = word.size();
        vector<int>freq(26 ,0);
      for(int i =0; i<word.size();i++){
            freq[word[i]-'a']++;
      }
        // i -6 , h -2 , a -2 , b -1
        sort(freq.begin() , freq.end() , greater<int>());
     // freq = {6, 4, 3, 2, 1, 0, 0, 0, 0, ..., 0}
   
int ans = 0;
int pushes  =1;
   for(int i = 0 ; i<26 ; i++){

if(freq[i] ==0){
    break;
}
//  ( i/8 +1 ) is calculating pushes 
ans = ans + pushes*freq[i];
if( (i+1) %8 ==0 ){
    pushes ++;
}
 
   }
  return ans ;
    }
};