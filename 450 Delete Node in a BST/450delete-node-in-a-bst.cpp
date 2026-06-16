class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left || !root->right){
                if(root->left) return root->left;
                else return root->right;
            }
            else{
                TreeNode* pred=iop(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
            }
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else root->left=deleteNode(root->left,key);
        return root;
    }
};