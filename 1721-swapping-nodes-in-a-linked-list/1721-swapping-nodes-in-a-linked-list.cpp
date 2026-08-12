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
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* front = head;
           ListNode* back = head;
           for(int i = 1 ;i<k ;i++){
            front = front->next;
           }
// now front will point to k th node from start 
ListNode* savingfr = front;
front = front->next;
while(front!=NULL){
    front = front->next;
    back = back->next;
}
// now back will point to kth node from backward 
swap(savingfr->val , back->val);
return head;
    }
};