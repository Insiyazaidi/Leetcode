class Solution {
public:
int count (vector<int>& citations , int val){
    int number =0;
    for(int i =0;i<citations.size(); i++){
        if(citations[i]>=val){
            number++;
        }
    }
    return number;
}

    int hIndex(vector<int>& citations) {
      int h= 1;
      while(h<=citations.size()){
        if(count(citations , h )  >=h ){
            h++;
        }
        else{
            return h-1 ;
        }
      }
      return h-1;  
    }
};