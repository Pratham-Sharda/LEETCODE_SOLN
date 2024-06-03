class Solution {
public:
    vector<int> ans; // Vector to store the inorder traversal result.

    vector<int> inorderTraversal(TreeNode* root) {
        // Base Case
        if (root) {
            // Recursive Step 1: Traverse left subtree
            inorderTraversal(root->left);

            // Recursive Step 2: Visit current node
            ans.push_back(root->val);

            // Recursive Step 3: Traverse right subtree
            inorderTraversal(root->right);
        }

        // Return the result vector after the entire tree is traversed.
        return ans;
    }
};