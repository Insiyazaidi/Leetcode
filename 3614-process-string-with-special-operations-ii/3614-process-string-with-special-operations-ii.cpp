class Solution {
public:
    char processStr(string s, long long k) {
       long long length = 0;
       // forward pass for calculating length of resultant string 
       for(int i =0 ; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z'){
             length++;
        }
        else if(s[i]=='*'){
            if(length>0){
           length--;
            }           
        }
        else if(s[i]=='#'){
            length = length*2;
        }    
       }
       if(k>=length){  // eg - length = 4 , index valid / k valid will be - 0,1,2,3 .. so if k = 4 we wont be able to access it 
        return '.';
       } 

       int n = s.size();
       // backtrack .. 
       for(int i = n-1; i>=0;i--){
        if(s[i] == '*'){  // ek char delete kiya tha
             length++;  
        }
        else if(s[i] == '#'){  // yaani duplicate kiya tha 
                   length = length/2;
                   if(k>=length){  // exceed krrha h toh hi update krege k 
  k = k-length;
                   }
        }
else if(s[i] == '%'){  // reverse kri h string no need to update length 
k = length-1-k;

}
else if(s[i] >='a' && s[i]<='z'){   // char hoga toh length ++ ki thi 

   if(length - 1 == k) {
                return s[i];
            }
            length--;
}

       }

return '.';


    }
};