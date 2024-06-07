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
    int counr(TreeNode* root){
        // if(!root){
        //     return NULL;
        // }
        int cnt=0;
        while(root){
            cnt++;
            root=root->right;
        }

        return cnt;
    }
        int counl(TreeNode* root){
        // if(!root){
        //     return NULL;
        // }
        int cnt=0;
        while(root){
            cnt++;
            root=root->left;
        }

        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int hl=counl(root);
        int hr=counr(root);



        if(hl==hr){
            return pow(2,hl)-1;
        }
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};