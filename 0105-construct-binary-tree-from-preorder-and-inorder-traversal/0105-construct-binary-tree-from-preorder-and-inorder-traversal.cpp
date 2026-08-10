/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex,
                    int instart, int inend, unordered_map<int, int>& mp) {
        if (instart > inend)
            return NULL;
        int rootvalue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootvalue);

        int inIndex = mp[rootvalue];

        root->left =
            build(preorder, inorder, preIndex, instart, inIndex - 1, mp);

        root->right =
            build(preorder, inorder, preIndex, inIndex + 1, inend, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size() - 1, mp);
    }
};