class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
long long number = 0;
long long result = 0;
long long sign = 1;
      for(int i = 0 ; i<s.size() ; i++){
      if(isdigit(s[i])){
         number = number*10+(s[i]-'0');

      }
     else if (s[i] == ' ')
    continue;
      else if(s[i] == '+'){ // + aagya mean koi numb bn gya h usko res mai store krdo
     result += (number*sign);
     number = 0; // scratch se new numb bnao 
     sign = 1;  // + sign h toh sign update krod
      }
         else if(s[i] == '-'){ // - aagya mean koi numb bn gya h usko res mai store krdo
     result += (number*sign);
     number = 0; // scratch se new numb bnao 
     sign = -1;  // - sign h toh sign update krod
      }
      else if(s[i] == '('){  //  sb () vli cheez ko process krne se phle purana sign aur res store krlo stack m 
      st.push(result);
      st.push(sign);
      number = 0 ;
      result = 0;
      sign =1;

      }
      else if(s[i] == ')'){
        result +=(number)*sign;
        int presign = st.top(); st.pop();
        int prevres = st.top(); st.pop();
        result = result*presign;
        result+=prevres;
        number = 0 ;
       // res = 0  not corrrect what is 1-(2+3)+4 ?? then u r throwing away the cal 
      }

      }

// extra case if (1+2) + 1 is there then at i pointing to 1 will not be added to result as i becomes out of bound after this 
result+=number*sign;
return result;

    }
};