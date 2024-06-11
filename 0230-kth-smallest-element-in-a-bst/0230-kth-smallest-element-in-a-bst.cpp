/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solver(TreeNode* root, int k,int & ctr){
        if(ctr>k || root==NULL){
            return -1;
        }

        int lefty=solver(root->left,k,ctr);
        if(lefty!=-1){
            return lefty;
        }
        ctr++;
        if(ctr==k){
            return root->val;
        }

        return solver(root->right,k,ctr);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ctr=0;
        return solver(root,  k,ctr);
    }
};