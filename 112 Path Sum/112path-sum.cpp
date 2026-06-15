class Solution {
public:
    bool helper(TreeNode* root, int target){
        if(!root) return false;
        if(!root->left && !root->right){
            return root->val==target;
        }
        return helper(root->left,target-root->val) || helper(root->right,target-root->val);
        
    }
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
       return helper(root,target);
    }
};