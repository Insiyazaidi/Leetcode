class Solution {
public:
stack<char>st;

    bool isValid(string s) {
      for(int i = 0 ; i<s.size() ; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'  ){
            st.push(s[i]);
        }
        else{
            if(st.empty()){  // stack m koi opening bracket ni h seedha closing aagya toh false
                return false; 
            }
            // its a closing bracket ... 
            // check match mila ya pair up hoskata h 
         if ((st.top() == '(' && s[i] == ')') ||
        (st.top() == '[' && s[i] == ']') ||
        (st.top() == '{' && s[i] == '}')) {

        st.pop();
    }
            else{
                // not found 
                return false;
            }
        }
      } 
      if(st.empty()== true){
        return true;
      } 
      else{
 return false;
      }
       
    }
};