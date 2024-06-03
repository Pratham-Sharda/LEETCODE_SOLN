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
void preorder(TreeNode *root,vector<int> & vec){
    if(root==NULL){
        return;
    }
    TreeNode* L =root->left;
    TreeNode* R =root->right;
    vec.push_back(root->val);
    preorder(L,vec);
    
    preorder(R,vec);
    return;
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorder(root,pre);
        return pre;
    }
};