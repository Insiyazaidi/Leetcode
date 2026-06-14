/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
   int ans = INT_MIN;
   vector<int>values ; 
   ListNode* temp = head;
   while(temp!=NULL){
    values.push_back(temp->val);
    temp  = temp->next;
   }
// we will get all the values .. 
int i =0;
int j = values.size()-1;
while(i<j){
    ans = max(ans , values[i]+values[j]);
    i++;
    j--;
}
return ans ;
    }
};