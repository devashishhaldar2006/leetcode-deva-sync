class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int target) {
        if(!root) return NULL;
        if(target==root->val) return root;
        else if(target<root->val) return searchBST(root->left,target);
        else if(target>root->val) return searchBST(root->right,target);
        return NULL;
    }
};