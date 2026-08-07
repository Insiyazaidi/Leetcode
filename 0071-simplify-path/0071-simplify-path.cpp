class Solution {
public:
    string simplifyPath(string path) {
        // int i = 0;
        stack<string>st;
        for(int i = 0 ; i<path.size(); i++){
            string temp = "";
            if(path[i] == '/') continue;
            while(i<path.size() && path[i] != '/'){
                temp+= path[i];    // making temp 
                 i++;
            }

            // now processing 
            if(temp == "" || temp == "."){
                continue;
            }
               else if(temp == ".."){
            if(!st.empty()){
              st.pop();
            }    
            }
            else{
                st.push(temp);
            }
        }
        string ans = "/";
        vector<string>hold;
        while(!st.empty()){
          hold.push_back(st.top());
           st.pop();
        }

        reverse(hold.begin() , hold.end());
      for(int i = 0 ; i<hold.size() ;i++){
        ans = ans+hold[i];
        if(i!=hold.size()-1){
            ans+='/';
        }
      }
        return ans ;
    }
};