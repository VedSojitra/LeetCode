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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);

        if(root->left == NULL && root->right == NULL)
            return 1;

        // If the left subtree is empty, return the depth of right subtree after adding 1 to it...
        if(root->left == NULL)
            return 1 + right;
        // If the right subtree is empty, return the depth of left subtree after adding 1 to it...
        if(root->right == NULL)
            return 1 + left;

        int ans = min(left, right) + 1;
        return ans;
    }
};
