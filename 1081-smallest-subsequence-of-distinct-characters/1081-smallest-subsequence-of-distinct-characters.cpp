class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>visited(26 , false);
        vector<int>lastidx(26);
        for(int i = 0 ; i<s.size(); i++){
            lastidx[s[i] - 'a'] = i; // eg lastidx[e-a] ie lastidx[4] = 2 ; // 4 th idx pr e ka indx store hoga  
        }
stack<char>st;

for(int i =0; i<s.size(); i++){
    if(visited[s[i]-'a'] == true){
        continue;
    }

    while(!st.empty() && st.top() >s[i]  &&  lastidx[st.top() -'a'] >i ){   // e > a ,, and e also comes later in string 
       visited[st.top()-'a'] = false ;
        st.pop();
       
    }
          st.push(s[i]);
        visited[s[i]-'a'] = true;  
}

// now stack 
string ans = ""; 
while(!st.empty()){
    char c = st.top();
    ans = ans+c;
    st.pop();
}
reverse(ans.begin() , ans.end());
return ans ;

    }
};