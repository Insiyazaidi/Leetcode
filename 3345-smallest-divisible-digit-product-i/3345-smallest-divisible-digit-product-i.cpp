class Solution {
public:
    int smallestNumber(int n, int t) {
      // smallest no ... greater than or equal to n 
      // prod of dig is div by t 
      bool found = false;
       int ans =1 ;
      while(found == false){
        int numb = n ;
       ans =1;
        while(numb!=0){
            int dig = numb%10;
            ans = ans*dig;
            numb = numb/10;
                    }
                    if(ans % t == 0){ // div h
                           break;
                    }
                    else{
                        n++; // vrnaa next try kregeb
                    }
      }
      return n ;  
    }
};