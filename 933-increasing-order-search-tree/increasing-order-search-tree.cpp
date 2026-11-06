class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        inorder(root);
        TreeNode* temp=new TreeNode(v[0]);
        TreeNode* d=temp;
        for(int i=1;i<v.size();i++){
            d->right=new TreeNode(v[i]);
            d=d->right;
        }
        return temp;
        
    }
};