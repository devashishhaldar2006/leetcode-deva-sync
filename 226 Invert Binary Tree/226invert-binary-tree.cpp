class Solution {
public:
    void helper(TreeNode* root){
        if(!root) return;
        swap(root->left,root->right);
        helper(root->left);
        helper(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        helper(root);
        return root;

    }
};