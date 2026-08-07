class Solution {
public:
stack<int>st;
int result = 0;
    int evalRPN(vector<string>& s) {
      for(int i = 0 ; i<s.size() ; i++){
        if(s[i] != "+" && s[i]!="-" && s[i] != "*" && s[i] != "/"){ 

             st.push(stoi(s[i])); // string to int conversion 
        }

        else {
              int first = st.top();
               st.pop();
               int second = st.top();
               st.pop();

 if(s[i] == "+" ){
             st.push(first+second);
        }
           else if(s[i] ==  "-" ){
             
                st.push(second-first);
              
        }
           else if(s[i] ==  "/" ){
                  st.push(second/first);
             
        }
           else if(s[i] ==  "*" ){
            st.push(second*first);
        }
      }  
        }
        

      return st.top();
    }
};