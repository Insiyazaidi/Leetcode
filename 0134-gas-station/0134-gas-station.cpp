class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int totalkamai = accumulate(begin(gas) , end(gas) , 0); // this gives sum of all elements of vector
      int totalkharch =  accumulate(begin(cost) , end(cost) , 0); 

if(totalkamai<totalkharch){
    return -1;
}

int total = 0;
int resultidx = 0;
for(int i =0; i<gas.size();i++){
total = total+gas[i]-cost[i];
    if(total<0){
        total =0;
        resultidx = i+1;
    }
}
return resultidx;

    }
};