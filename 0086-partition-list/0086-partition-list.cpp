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
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallhead = new ListNode(0);  // these were used to store the ref for later 
        ListNode * largehead = new ListNode(0);

ListNode* small = smallhead;
ListNode* large = largehead;

        while(head!=NULL){
            if(head->val <x){
                small->next = head;
              small = small->next;
            }
            else{
                large->next = head;
                large = large->next;
            }
              head=head->next;

        }
         // Important: terminate the large list
        large->next = NULL;

        // Connect small list with large list

        // at last combine 
        small->next = largehead->next;
        return smallhead->next;

    }
};