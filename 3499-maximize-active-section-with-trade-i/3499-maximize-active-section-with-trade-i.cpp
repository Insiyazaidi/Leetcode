class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activecount = count(begin(s) , end(s) , '1');
        vector<int>zeroblocksize;
        int n = s.size();
       // int zerosize = 0;
//         for(int i = 0 ; i<s.size() ; i++){
//            if(s[i] == '0'){
//             zerosize++;
//            }
//            else{  // agr 1 aagya 
//    if(zerosize!=0){
//     zeroblocksize.push_back(zerosize);
//        zerosize = 0;
//    }

//            }
//         }
int i = 0;
while(i<n){
if(s[i]=='0'){
    int start = i;
    while(i<n && s[i]=='0'){
     i++;
    }
    zeroblocksize.push_back(i-start);
}
else{
    i++;
}
}

        int maxpairsum = 0;
        for(int i =1 ; i<zeroblocksize.size() ; i++){
            maxpairsum = max(maxpairsum , zeroblocksize[i]+zeroblocksize[i-1]);
        }


return maxpairsum +activecount;

    }
};