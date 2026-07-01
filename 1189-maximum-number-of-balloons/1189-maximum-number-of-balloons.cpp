class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count=0;
       vector<int>available(26,0); 
        for(int i=0; i<text.size();i++){
          available[text[i]-'a']++; 
        }
        return min(
           { available['b'-'a']/1 ,   // (availabe/req) ... min isliye liya h kyu ki agr baaki sb 2 letter 2 ballon 
            // bna skte h but n hmare pass ek hi h toh 1 hi balloon bn skta h isliye sb ka min liya hh 
             available['a'-'a']/1 ,
              available['l'-'a']/2,
               available['o'-'a']/2,
                available['n'-'a']/1  
           }
        
        );
    }
};