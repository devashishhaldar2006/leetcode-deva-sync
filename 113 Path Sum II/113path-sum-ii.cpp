class Solution {
public:
    void helper(vector<vector<int>>& ans,TreeNode* root,vector<int> v,int target){
        if(!root) return;
        if(!root->left && !root->right){
            if(root->val==target){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        helper(ans,root->left,v,target-(root->val));
        helper(ans,root->right,v,target-(root->val));
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,root,v,targetSum);
        return ans;
    }
};