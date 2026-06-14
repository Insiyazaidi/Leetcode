class Solution {
public:
    int hIndex(vector<int>& citations) {
       int h =1;
      sort( citations.begin() , citations.end());  // [0 ,1 , 3 , 5 , 6]
       while(h<=citations.size()){
    int highest = citations.size()-1 ;
    int count =0;
    while(highest>=0){
        if(count>=h)  break;
        if(citations[highest]>=h){
            count++;
        }
        else if( citations[highest] < h && count<h) return h-1;
        highest--;       
    }
h++;
       } 
       return  h-1 ;
    }
};