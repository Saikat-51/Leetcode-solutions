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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
             temp=temp->next;
        }
       
        int k=count-n;
        temp=head;
        count=0;
      if(k==0){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        while(count<k-1){
            temp=temp->next;
            count++;
        }
        
      ListNode* cur=temp->next;
        temp->next = cur->next;
        cur->next=NULL;
         delete cur;
        return head;
    }
};