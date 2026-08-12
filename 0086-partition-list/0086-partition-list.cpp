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
        ListNode* temp = head;
       int count = 0;
       int less = 0;
       int more = 0;
        while(temp!=NULL){
     count++;
     if(temp->val <x){
        less++;
     }
     else{
        more++;
     }
     temp = temp->next;
        }
     vector<int>v(count);
     ListNode* pt = head;
     int i = 0 ; // eg less = 3 , i = 0 , 1 , 2  ... more = 4 ... 
     int j = less  ;
     while(pt!=NULL){
        if(pt->val <x){
            v[i] = pt->val;
            i++;
        }
        else{
       v[j] = pt->val;
       j++;
        }
        pt = pt->next;
     }

int k = 0;
ListNode* itr = head;
while(itr!=NULL){
    itr->val = v[k];
    k++;
    itr =itr->next;
} 
return head;

    }
};