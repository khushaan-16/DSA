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
    void preorder(TreeNode* root, vector<int>& ans){
        TreeNode* node = root;
        if(root == NULL) return;

        ans.push_back(root->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        vector<int> ans;
        preorder(node, ans);
        return ans;
    }
};