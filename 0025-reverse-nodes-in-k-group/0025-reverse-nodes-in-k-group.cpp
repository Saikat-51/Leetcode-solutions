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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* cur=head;
       for(int i=0;i<k;i++){
        if(!cur)
          return head;
          cur=cur->next;
       } 
       ListNode* prv=reverseKGroup(cur,k);
       cur=head;
       for(int i=0;i<k;i++){
        ListNode* next=cur->next;
        cur->next=prv;
        prv=cur;
        cur=next;
       }
       return prv;
    }
};