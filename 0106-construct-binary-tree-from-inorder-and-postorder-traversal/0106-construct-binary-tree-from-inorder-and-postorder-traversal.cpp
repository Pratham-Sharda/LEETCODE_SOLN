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
    TreeNode* building(map<int,int>& mpp,int is,int ie,vector<int> & inorder,int ps,int pe,vector<int> & postorder){
        if(is>ie ||ps>pe){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mpp[postorder[pe]];
        int leftno=inroot-is;
        root->left=building(mpp,is,inroot-1,inorder,ps,ps+leftno-1,postorder);
        root->right=building(mpp,inroot+1,ie,inorder,ps+leftno,pe-1,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        return building(mpp,0,inorder.size()-1,inorder,0,postorder.size()-1,postorder);
    }
};