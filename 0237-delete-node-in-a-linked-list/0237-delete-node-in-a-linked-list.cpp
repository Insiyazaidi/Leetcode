/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp =  node;
        ListNode* tempnext = temp->next;
        temp->val =  tempnext->val ;
        // now delete tempnext .. 
       // ListNode* rightm = tempnext->next;
      //  tempnext->next = NULL;
        temp->next = tempnext->next;
        delete tempnext;


    }
};