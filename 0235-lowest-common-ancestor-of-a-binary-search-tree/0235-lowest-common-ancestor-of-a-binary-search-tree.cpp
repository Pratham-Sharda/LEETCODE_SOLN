/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval=p->val;
        int qval=q->val;

        TreeNode* temp=root;

        while(temp!=NULL){

            if(temp->val>=pval && temp->val<=qval ){
                break;
            }else if(temp->val>=qval && temp->val<=pval){
                break;
            }
            if(temp->val>pval && temp->val >qval){
                temp=temp->left;
            }else if(temp->val<pval && temp->val <qval){
                temp=temp->right;
            }
        }

        return temp;
    }
};