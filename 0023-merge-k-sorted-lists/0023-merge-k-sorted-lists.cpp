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
class compare{
  public:
  bool operator()(ListNode* a,ListNode* b){
      return (a->val>b->val);
  }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head =new ListNode(-10);
        ListNode* tail =head;

        priority_queue<ListNode*,vector<ListNode*>,compare> p;

        for(ListNode* i:lists){
            
              // Ensure the array is not empty
                if(i!=NULL){
p.push(i);
                }
                
        
        }

        while(p.size()>0){
            ListNode* temp=p.top();
            p.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next!=NULL){
                p.push(temp->next);
            }

        }

        return head->next;
    }
};