class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i = 0; i< n ;i++){
            bool currdes = false;
            while(!st.empty()  && st.top() > 0 && asteroids[i] < 0 ){
                 int top = abs(st.top());
                 int curr = abs(asteroids[i]);
                 if(top<curr){  // stack pe top vli value choti h hta do 
                    st.pop();
                 }
         else if( top == curr){ // dono equal h toh stack vle ko stack se htai aur i vle ko ignore krdo stack m mt daalo 
        st.pop();
        currdes = true;
        break;
                 }
                 else{   // curr vla chota h vo des hoga 
              currdes = true;
              break;
                 }
              
            }
        if(currdes == false){  // agr curr des ni hua toh hi stack m daalo vrnani 
             st.push(asteroids[i]);
        }    

        }
        vector<int>ans;
        if(st.empty()){
            return ans;
        }
        else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;


    }
};