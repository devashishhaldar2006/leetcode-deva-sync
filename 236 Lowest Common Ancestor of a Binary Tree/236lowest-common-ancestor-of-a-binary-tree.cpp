class Solution {
public:
    bool exists(TreeNode* root,TreeNode* target){
        if(!root) return false;
        if(root==target) return true;
        return exists(root->left,target) ||  exists(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;
        if(exists(root->left,p) && exists(root->right,q)) return root;
        else if(exists(root->left,q) && exists(root->right,p)) return root;
        else if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};