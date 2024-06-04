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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int le=maxDepth(root->left);
        int re=maxDepth(root->right);

        return max(le,re)+1;
    }
    // void balance(TreeNode* root,bool val){

    //     int h1=balance()
    // }
    bool isBalanced(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        int h1=maxDepth(root->left);
        int h2=maxDepth(root->right);
        
        if(h1==1 && h2==1){
            return true;
        }if(abs(h1-h2)<=1){
            return isBalanced(root->left) && isBalanced(root->right);
        }else{
            return false;
        }
    }
};