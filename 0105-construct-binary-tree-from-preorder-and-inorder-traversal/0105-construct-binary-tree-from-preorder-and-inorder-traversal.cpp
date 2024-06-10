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
    TreeNode* building(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie,map<int,int>& mpp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode * root=new TreeNode(preorder[ps]);
        int find_root=mpp[preorder[ps]];
        int elel=find_root-is;
        root->left=building(preorder,inorder,ps+1,ps+elel,is,find_root-1,mpp);
        root->right=building(preorder,inorder,ps+elel+1,pe,find_root+1,ie,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return building(preorder,inorder,0,n-1,0,n-1,mpp);
        
    }
};