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
    ListNode* slow = head;
    ListNode* fast = head;
    int ans = INT_MIN;
    while(slow!=NULL && fast!=NULL){
  slow = slow->next;
  if (fast->next!=NULL){
    fast = fast->next->next;
  }
    }
    // now slow  will point to mid 
    ListNode* temp = slow;
    ListNode* prev = NULL;
    ListNode* ahead = NULL;
    while(temp!=NULL){
     ahead = temp->next;
     temp->next = prev;
     prev=temp;
     temp=ahead;
    }
    ListNode* head2 = prev;
    ListNode* i = head;
    ListNode* j = head2;
    while( i !=NULL && j!=NULL ){
        ans = max(ans , i->val+j->val);
        i = i->next;
        j = j->next;
    } 

return ans ;

    }
};