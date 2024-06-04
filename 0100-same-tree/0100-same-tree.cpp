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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==nullptr){
            return true;
        }
        if(p!=nullptr && q==nullptr){
            return false;
        }
        if(q!=nullptr && p==nullptr){
            return false;
        }

        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);

        bool va=(p->val==q->val);

        if(l&& r&&va){
            return true;
        }else{
            return false;
        }

    }
};