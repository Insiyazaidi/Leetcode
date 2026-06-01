class Solution {
public:
    vector<int> twoSum(vector<int>&arr, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
int first = arr[i];
            int sec = target-arr[i];
if(m.find(sec)!=m.end()){ // yaani mil gya
ans.push_back(i);
ans.push_back(m[sec]);
}
else{
m[first]=i;
}
        }
        return ans;
    }
};