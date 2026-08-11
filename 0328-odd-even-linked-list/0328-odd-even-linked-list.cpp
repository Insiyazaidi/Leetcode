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
    ListNode* oddEvenList(ListNode* head) {
         ListNode* odd = head;
         if(head==NULL) return head;
          ListNode* even  = head->next;
           ListNode* evenhead = head->next;
while(even!=NULL && even->next!=NULL ){    // Because if even is valid, odd will also be valid at this point.
   odd->next = even->next;
   odd = odd->next;
   even->next= odd->next;
   even = even->next;

} 
odd->next = evenhead; // jo ki save kiyya tha 
return head;

    }
};