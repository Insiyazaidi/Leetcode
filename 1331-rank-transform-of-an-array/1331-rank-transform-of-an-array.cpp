class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        map<int , vector<int>>mp;
        for(int i =0 ;i<n ;i++){
          mp[arr[i]].push_back(i); // 20 - comes at index 3 , 7 
        }
        int rank =1;
     for(auto &it : mp){ // iteration over map 
      for(int idx : it.second){  // agr multiple index h toh same rank rkho 
        ans[idx] = rank;
      }
      rank++; 
     }
     return ans;
    }
};