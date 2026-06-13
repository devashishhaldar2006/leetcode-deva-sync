class Solution {
public:
    void helper(TreeNode* root,vector<vector<int>>& ans){
        if(!root) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> v;
            int level=q.size();
            for(int i=1;i<=level;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root,ans);
        return ans;
    }
};