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
    private:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        int ans = max(left, right) + 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int opt1 = diameterOfBinaryTree(root -> left);
        int opt2 = diameterOfBinaryTree(root -> right);
        int opt3 = maxDepth(root -> left) + maxDepth(root -> right);

        int ans = max(opt1, max(opt2, opt3));
        return ans;

    }
};
