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
    int mini(vector<int>& preorder, int start, int rootval) {
        int i = start;
        while (i < preorder.size() && preorder[i] < rootval) {
            i++;
        }
        return i;
    }
    TreeNode* helper(vector<int>& preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[start]);
        int sta=mini(preorder,start+1,root->val);
        root->left=helper(preorder,start+1,sta-1);
        root->right=helper(preorder,sta,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return helper(preorder,0,preorder.size()-1);
    }
};