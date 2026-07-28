class Solution {
public:
    int maxProduct(int n) {
      vector<int>dig;
     while(n!=0){
        int no = n%10;
        dig.push_back(no);
        n = n/10;
     }
     sort(dig.begin() , dig.end());
     int number = dig.size();
     return dig[number-1]* dig[number-2];
    }
};