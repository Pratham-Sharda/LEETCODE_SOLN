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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        TreeNode* prev=NULL;
        if(root==NULL){
            return new TreeNode(val);
        }
        while(temp){
            if(temp->val>val){
                prev=temp;
                temp=temp->left;
            }else{
                prev=temp;
                temp=temp->right;
            }
        }

        if(val>prev->val){
            prev->right= new TreeNode(val);
        }else{
            prev->left= new TreeNode(val);
        }

        return root;
    }
};