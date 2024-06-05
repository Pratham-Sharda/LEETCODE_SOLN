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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp =q.front();
            q.pop();
            TreeNode* curr_node=temp.first;
            int hl=temp.second.first;
            int depth=temp.second.second;

            nodes[hl][depth].insert(curr_node->val);
            if(curr_node->left){
                q.push({curr_node->left,{hl-1,depth+1}});
            }
            if(curr_node->right){
                q.push({curr_node->right,{hl+1,depth+1}});
            }

        }
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                // cout<<j;
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            // sort(col.begin(),col.end());
            res.push_back(col);

        }
        return res;
    }
};