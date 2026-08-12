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
    ListNode* removeZeroSumSublists(ListNode* head) {       
ListNode* temp = head;
if(head==NULL) return NULL;
unordered_map<int , ListNode*>mp;
int prefixsum = 0 ;
ListNode* newhead = new ListNode(0);
mp[0] = newhead;
newhead->next= temp;
while(temp!=NULL){
prefixsum+=temp->val;
if(mp.find(prefixsum)==mp.end()){  // yaani ni mila 
mp[prefixsum] = temp;  // add in mp 
}
else{
    // yaani same prefix exist krta hh 
  ListNode* prev = mp[prefixsum];
 
// now changing map values 
// prev node aur temp node tk map m jitni values h vo remove krni h 
ListNode* rem = prev->next;
prev->next = temp->next; // remove the middle nodes
int sum = prefixsum;
while(rem!=temp){
    sum+=rem->val;
    mp.erase(sum); // 
    rem=rem->next;
}
    
}
temp = temp->next;
}
return newhead->next;

    }
};