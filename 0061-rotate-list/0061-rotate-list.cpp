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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;
 ListNode* tail=head;
int count=1;
while(tail->next!=NULL){
  tail=tail->next;
  count++;
}

k=k%count;
if(k==0)
return head;
int last=count-k-1;
tail->next=head;
ListNode* temp=head;
while(last){
    last--;
  temp=temp->next;
  
}
ListNode* newHead=temp->next;
temp->next=NULL;
head=newHead;
return head; 
    }
};