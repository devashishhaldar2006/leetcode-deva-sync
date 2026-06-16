class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* r=curr->right;
                curr->right=curr->left;
                TreeNode* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=r;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        TreeNode* temp=root;
        while(temp->right){
            temp->left=NULL;
            temp=temp->right;
        }
    }
};