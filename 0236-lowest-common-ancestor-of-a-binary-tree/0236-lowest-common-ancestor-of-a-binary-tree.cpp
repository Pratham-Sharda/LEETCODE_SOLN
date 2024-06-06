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

void finder(TreeNode* root, int B, vector<TreeNode*>& ans, vector<TreeNode*>& sol) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root);
        if (root->val == B) {
            sol = ans;
            return;
        }
        
        if (root->left) {
            finder(root->left, B, ans, sol);
            if (!sol.empty()) return; // if solution found, no need to proceed further
        }
        
        if (root->right) {
            finder(root->right, B, ans, sol);
            if (!sol.empty()) return; // if solution found, no need to proceed further
        }
        
        ans.pop_back(); // backtrack
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
            vector<TreeNode*> sol1;
            vector<TreeNode*> sol2; 
            vector<TreeNode*> ans;
            // ans.push_back(root);
            finder(root,p->val,ans,sol1);
            ans.clear();
            finder(root,q->val,ans,sol2);

            int n=sol1.size();
            int m=sol2.size();

            int looper=min(n,m);
            TreeNode* answ=NULL;
            for(int i=0;i<looper;i++){
                if(sol1[i]->val!=sol2[i]->val){
                    break;
                }
                answ=sol1[i];
            }

            // cout<<answ<<endl;
            return answ;

    }
};