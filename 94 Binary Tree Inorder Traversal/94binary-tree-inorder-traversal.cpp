class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr){
            if(curr->left){
                // find pred
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr){
                    pred=pred->right;
                }
                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                if(pred->right==curr){
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};