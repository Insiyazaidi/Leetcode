class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() && k > 0 && st.top() > num[i]) {  // prev dig > curr dig 
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // Agar k abhi bhi bacha hai
        while(k > 0) {  // last ke k elements remove krdo 
            st.pop(); 
            k--;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // leading zeroes
        int i = 0;

        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans == "")
            return "0";

        return ans;
    }
};