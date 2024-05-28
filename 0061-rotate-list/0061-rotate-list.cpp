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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        k=k%cnt;
        for(int i=0;i<k;i++){
        
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }

        curr->next=head;
        prev->next=NULL;

        head=curr;

        }
    
    return head;
    }
    
};