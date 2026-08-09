class Solution {
public:
    string minRemoveToMakeValid(string s) {
     int open = 0;
     for(int i = 0 ; i<s.size(); i++){
        if(s[i]!= ')' && s[i]!='('){
            continue;
        }
        if(s[i] == '('){
            open++;
        }
        else if(s[i]==')'){
            if(open >0){
                open --;  // ek close bracket mil  gya h open ko 
            }
            else{
         s[i] = '#'; // agr open bracket hi ni h toh yeh invalid h mtlb 
            }         
        }
     }
     // right to left 
     // marking extra ( as invalid
     for(int i = s.size()-1 ; i>=0 ; i--){  // we know open = 1 yaani ek invalid open bracket h 
        if(s[i] == '(' && open >0){
            s[i] = '#';
            open --;  // for eg ( a ( b ( c )  so here 2 open bracket is invalid 
        }
        // pas ke bad  (a # b # c ) aise hoga 
  
     }

 string ans = "";

        for(char c : s) {
            if(c != '#') {
                ans += c;
            }
        }

        return ans;

    }
};