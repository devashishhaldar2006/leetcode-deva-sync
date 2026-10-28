class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left and !root->right){
            return 1;
        }
        if(!root->left) return 1+helper(root->right);
        if(!root->right) return 1+helper(root->left);
        return 1+min(helper(root->left),helper(root->right));
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
    }
};