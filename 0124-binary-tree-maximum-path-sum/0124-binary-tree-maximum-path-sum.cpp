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
    int solve(TreeNode* root, int & maxi){
        if(root==NULL){
            return 0;

        }
        int l=solve(root->left,maxi);
        // cout<<l<<endl;
        int r=solve(root->right,maxi);
        // cout<<r<<endl;
        int dono =l+r+root->val;
        int ek=max(l,r)+root->val;
        int koinahi=root->val;

        maxi=max({maxi,dono,ek,koinahi});

        return max(ek,koinahi);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        solve(root,maxi);
        return maxi;
    }
};