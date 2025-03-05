/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   void InsertInBetween(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode= new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }
   void randomPointers(Node*  head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random)
            copyNode->random=temp->random->next;
           else
           copyNode->random=nullptr;
            temp=temp->next->next;
        }
    }
    Node* finalList(Node* head){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        Node* temp=head;
        while(temp!=NULL){
            res->next=temp->next;
             temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
           
        }
        return dummy->next;

    }
public:
    Node* copyRandomList(Node* head) {
        InsertInBetween(head);
        randomPointers(head);
        return finalList(head);
    }
};