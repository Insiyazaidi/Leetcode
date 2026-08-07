class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string token = "";
        while(getline(ss , token , '/' )){
            if(token == "" || token == "."){
                continue;
            }
                else if(token == ".."){
          
              if(!st.empty()){
        st.pop();
    }
            }

            else{  // ya phir kuch bhi ho 
             st.push(token);
            }
       
        }
        string result ="";
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){  // home , insiya , faiz 
        // result will be  ->   /faiz/insiya/home which is correct 
            result = "/"+st.top()+result;
            st.pop();
                    }
                    return result;




    }
};