class Solution {
public:
vector<int>ans;
void solve (int currnumb , int nextdigit , int &low , int &high){
if(nextdigit>9){
    return ;
}
currnumb = currnumb*10+nextdigit;
if(currnumb>=low && currnumb<=high){
    ans.push_back(currnumb);
}
// int currnextdi = currnumb%10+1;
solve(currnumb , nextdigit+1 , low , high);
}
    vector<int> sequentialDigits(int low, int high) {
        for(int start = 1; start<=8 ; start++){
            solve(start , start+1 , low , high);
        }
        sort(ans.begin() , ans.end());
        return ans ;
    }
};