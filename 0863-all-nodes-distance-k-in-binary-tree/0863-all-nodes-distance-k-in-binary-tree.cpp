/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void di_from_node(TreeNode* target,int k,vector<int> &ans){
        if(target==NULL){
            return;
        }
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        if(target->left){
            di_from_node(target->left,k-1,ans);
        }if(target->right){
            di_from_node(target->right,k-1,ans);
        }
    }
    int dis_root_node(TreeNode* root, TreeNode* target,int dist){
        if(root==target){
            return dist;
        }
        if(root==NULL){
            return -1;
        }
        int x1=0;int x2=0;
        if(root->left){
            x1=dis_root_node(root->left,target,dist+1);
        }
        if(root->left){
            x2=dis_root_node(root->left,target,dist+1);
        }
        return max(x1,x2);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        di_from_node(target,k,ans);
        int distanc=dis_root_node(root,target,0);
        int sub=k-distanc;
        if(sub<0){
            return ans;
        }else if(sub==0){
            ans.push_back(root->val);
            return ans;
        }else{
           di_from_node(root->right,sub-1,ans);
           return ans; 
        }

    }
};