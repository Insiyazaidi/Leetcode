class StockSpanner {
public:

stack<pair<int , int>>s; // stack storing curr price and its span value ... 


    StockSpanner() {  // initialize obj
        

    }
    
    int next(int price) {  // return the span for that praticular price
int ans =1 ;
if( !s.empty() ){
    auto topele = s.top();
    if(topele.first > price) {
        s.push({price , 1});
      return 1 ;
    }
    // agr aisa ni h value choti h 

while( !s.empty() && s.top().first<=price){
    auto topelement = s.top();
ans = ans+topelement.second;

s.pop();

}
s.push({price , ans});
return ans ;
}
else {
    s.push({price , 1});
    return 1;
}

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */