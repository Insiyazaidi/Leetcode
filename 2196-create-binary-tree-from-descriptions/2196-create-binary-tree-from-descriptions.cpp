/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
          map<int , TreeNode*>mp;
          set<int>children;   // root will never be in children set ... so we will find which one is not present 
          for(auto &d: descriptions ){
               int parent = d[0];
            int child = d[1];
            int isleft = d[2];

if(mp.find(parent)==mp.end()){   // agr yeh map m nhi h ... new h 
    mp[parent] = new TreeNode(parent);  // build node and store it 
}
if(mp.find(child)==mp.end()){
    mp[child] = new TreeNode(child);
}
if(isleft){
    mp[parent]->left = mp[child];
}
else{
 mp[parent]->right = mp[child];    
}

children.insert(child);  // inserting the value of child in set 
          }
          for(auto &i : descriptions){
            if(children.find(i[0])==children.end()){  // parent val in description is not present as children
                return mp[i[0]];
            }
          }


 return nullptr;
    }
};