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
    void parenting(TreeNode* root,map<TreeNode*,TreeNode* >& parent){
        if (root==NULL ){
            return ;
        }
        if(root->left){
            parent[root->left]=root;
            parenting(root->left,parent);
        }if(root->right){
            parent[root->right]=root;
            parenting(root->right,parent);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode* > parent;
        parenting (root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        int curr_level=0;
        visited[target]=true;

        while(!q.empty()){
            int size =q.size();

            if(k==curr_level){
                break;
            }
            curr_level++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();q.pop();
                visited[temp]=true;
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                }if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                }if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                }

            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            ans.push_back(temp->val);
        }


        return ans;



    }
};