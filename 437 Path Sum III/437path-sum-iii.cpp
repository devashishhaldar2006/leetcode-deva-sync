class Solution {
public:
    void helper(TreeNode* root,long long target,int& count){
        if(!root) return ;
        if((long long)root->val==target){
            count++;
        }
        helper(root->left,target-(long long)(root->val),count);
        helper(root->right,target-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int count=0;
        helper(root,(long long)targetSum,count);
        count+=pathSum(root->left,targetSum);
        count+=pathSum(root->right,targetSum);
        return count;
    }
};