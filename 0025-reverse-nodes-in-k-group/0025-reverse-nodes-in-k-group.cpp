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
    private:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* temp =head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
  ListNode* findkth(ListNode* temp,int k){
        while(temp!=NULL && k>1)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1)
        return head;
        ListNode* temp=head;
        ListNode* prevNode=NULL;
       while(temp!=NULL){
        ListNode* kth=findkth(temp,k);
        if(kth==NULL){
           if(prevNode) prevNode->next=temp;
           break;
        }
       ListNode* nextNode=kth->next;
        kth->next=NULL;
      reverseLL(temp);
        if(temp==head)
        head=kth;
       else{
        prevNode->next=kth;;
       }
       prevNode=temp;
       temp=nextNode;
       }
return head;
    }
};