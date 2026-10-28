class Solution {
public:
    int sum;
    void helper(TreeNode* root,int flag){
        if(!root) return;
        if(!root->left and !root->right and !flag) {
            sum+=root->val;
            return;
        }
        helper(root->left,0);
        helper(root->right,1);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        sum=0;
        helper(root,-1);
        return sum;
    }
};