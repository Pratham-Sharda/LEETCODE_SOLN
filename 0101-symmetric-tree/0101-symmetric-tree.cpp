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
    bool sym(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL){
            return true;
        }else if(left==NULL || right==NULL){
            return false;
        }

        bool curr=left->val==right->val;

        return curr && sym(left->left,right->right) &&sym(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
       if (root==NULL ){
       return true;}

       bool ans=sym(root->left,root->right);
       return ans;
    }

};