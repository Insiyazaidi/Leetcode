class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i =0 ; i<words.size(); i++){
            int wordsum = 0;
            string singleword = words[i];
            for(int j =0 ; j<singleword.size(); j++){
            int idx = singleword[j] - 'a' ;   // for eg - 'd' - 'a' = 3
             wordsum = wordsum + weights[idx] ; 
            }

// we will get eg 34 
int modulono  = wordsum %26 ;   // 34%26 = 8 , 26-8 = 18 
char ch = 'z' - modulono;

        ans = ans+ch;
        }
        return ans ;
    }
};