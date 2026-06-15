class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        else if(val>root->val){
            if(!root->right){
                root->right=new TreeNode(val);
            }
            else insertIntoBST(root->right,val);
        }
        else{
            if(!root->left){
                root->left=new TreeNode(val);
            }
            else insertIntoBST(root->left,val);
        }
        return root;
        
    }
};