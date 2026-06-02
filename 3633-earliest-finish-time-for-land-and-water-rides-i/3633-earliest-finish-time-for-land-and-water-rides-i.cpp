class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
              int ans = INT_MAX;
      
        for(int i =0 ; i<landStartTime.size();i++){
           
            int landfinish =  landStartTime[i]+ landDuration[i];
               for(int j = 0 ; j<waterStartTime.size(); j++){
             int curr = max(landfinish , waterStartTime[j]) + waterDuration[j];
                ans = min(ans , curr);
               }
        }

int  answater = INT_MAX; 
    for(int i =0 ; i<waterStartTime.size();i++){
    
               int waterfinish   = waterStartTime[i]+ waterDuration[i];
               for(int j = 0 ; j<landStartTime.size(); j++){
             int curr = max(waterfinish ,  landStartTime[j]) + landDuration[j];
                answater = min(answater , curr);
               }
        }
        return min (ans , answater);






    }
};