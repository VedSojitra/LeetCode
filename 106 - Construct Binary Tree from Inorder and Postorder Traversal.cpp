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
    TreeNode* build(int postStart, int postEnd, vector<int>& postorder, 
    int inStart, int inEnd, vector<int>& inorder, unordered_map <int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int ind = mp[postorder[postEnd]];  
        root->right = build(postStart+ind-inStart, postEnd-1, postorder, ind+1, inEnd, inorder, mp);  
        root->left = build(postStart, postStart+ind-inStart-1, postorder, inStart, ind-1, inorder, mp);
        

        return root;   
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0, postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        unordered_map <int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(postStart, postEnd, postorder, inStart, inEnd, inorder, mp);    
    }
};
