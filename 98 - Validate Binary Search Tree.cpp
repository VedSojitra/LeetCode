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
    bool isBST(TreeNode* root, long min, long max){
        bool left = false;
        bool right = false;
        if(root == NULL)
            return true;

        if(root->val > min && root->val < max){
            left = isBST(root->left, min, root->val);
            right = isBST(root->right, root->val, max);
            return left && right;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
       return isBST(root, LONG_MIN, LONG_MAX);  
    }
};
