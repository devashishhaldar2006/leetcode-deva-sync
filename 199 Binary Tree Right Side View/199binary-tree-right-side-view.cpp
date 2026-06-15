class Solution {
public:
    int levels(TreeNode* root){
        if(!root) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void preorder(vector<int>& ans,TreeNode* root,int level){
        if(!root) return;
        ans[level]=root->val;
        preorder(ans,root->left,level+1);
        preorder(ans,root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans(levels(root),0);
        preorder(ans,root,0);
        return ans;
    }
};