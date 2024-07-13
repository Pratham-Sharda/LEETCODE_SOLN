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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;

        }
        bool lr=true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int len=q.size();
            vector<int> cur;

            for(int i=0;i<len;i++){
                TreeNode* current=q.front();
                cur.push_back(current->val);
                q.pop();
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            if(lr){
                ans.push_back(cur);
            }else{
                reverse(cur.begin(),cur.end());
                ans.push_back(cur);
            }
            lr=!lr;
            
        }

        return ans;
    }
};