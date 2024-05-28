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
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mpp;

        Node* temp=head->next;
        Node* Clone_head=new Node(head->val);
        Node* temp2=Clone_head;
        mpp[head]=Clone_head;
        while(temp!=NULL){
            Node* newN=new Node(temp->val);
            temp2->next=newN;
            temp2=newN;
            mpp[temp]=temp2;
            temp=temp->next;
        }

        temp=head;
        temp2=Clone_head;
       
        while(temp!=NULL){
            temp2->random=mpp[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }

        return Clone_head;
    }
};