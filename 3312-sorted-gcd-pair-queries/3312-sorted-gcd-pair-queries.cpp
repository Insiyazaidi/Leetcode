class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxel = *max_element(begin(nums) , end(nums));
        vector<long long>freq(maxel+1 , 0);
        for(int &x : nums){   // store freq of each element 
            freq[x]++; 
        }
vector<long long>divcnt(maxel+1 , 0);

//  divcnt[4] -> represent how many elements in the array are div by 4 
for(int g = 1 ; g<=maxel; g++){  // this outer loop represent g -> 1 se maxel tk chlega 
for(int no = g ; no<=maxel; no=no+g){  // for eg - no = 4 ,,,, no will have values (4 , 8 , 12 , 16 , 20 )
divcnt[g] = divcnt[g] + freq[no];    
}
}

vector<long long>exact(maxel+1 , 0);
for(int g = maxel ; g>=1 ; g--){
    exact[g] = divcnt[g]*(divcnt[g]-1)/2; // pairing all no div by g  -- , n*(n-1)/2 total pair 
    // it may be possible that two no are div by x but their gcd is not exaclty x , it can be k*x so we have to remove these pairs 

for(int m = 2*g ; m<=maxel ; m = m+g){
    exact[g] = exact[g]-exact[m];   // to find exact[2] = all possible pair  - exact[4] - exact[8] - exact[12]... 
}


}



// sorted gcd will look like - 1 1 1 1 2 2 2 4 4 
// we need to find prefix array 
vector<long long>prefix(maxel+1 , 0);
for(int g = 1 ; g<=maxel ; g++){
    prefix[g] = prefix[g-1]+exact[g];
}
vector<int>ans;
for(long long val : queries){
    int g = lower_bound(prefix.begin()+1 , prefix.end() , val+1) - prefix.begin();
    ans.push_back(g);
}
return ans ;
    }
};