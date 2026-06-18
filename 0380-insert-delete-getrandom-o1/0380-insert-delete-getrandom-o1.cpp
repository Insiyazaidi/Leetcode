class RandomizedSet {
public:

  vector<int>nums;
      unordered_map<int , int>mp;

    RandomizedSet() {
    
    }
    
    bool insert(int val) {

     if(mp.find(val)!=mp.end()){ // present 
    return  false;
     }

nums.push_back(val); // [10 , 20 , 30 ] -- just end m 30 push kiya h nums ke , size = 3 , valid indexes  - 0 , 1 , 2  ,,, last index 
   // jo map m store hoga vo nums.size()-1 hoga 

   mp[val] = nums.size()-1; // 
   return true ;

    }
   
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
   int idx = mp[val]; // index nikal liya kha pr h yeh val 
   int lastelement = nums.back();
   // val ki jgha last elment daaldo  
   nums[idx] = lastelement;
mp[lastelement] = idx;
   nums.pop_back();
   mp.erase(val);
   return true;
    }
    
    int getRandom() {
           int index =  rand()% nums.size();
    return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */