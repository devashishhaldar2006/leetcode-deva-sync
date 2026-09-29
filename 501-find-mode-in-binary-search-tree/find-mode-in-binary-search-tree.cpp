class Solution {
public:
    int mx;
    int cnt;
    void dfs(TreeNode* root, vector<int>& ans, TreeNode*& prev) {
        if(!root) return;
        dfs(root->left, ans, prev);
        if(prev && prev->val==root->val) cnt++;
        else cnt=1;
        if(cnt>mx) {
            mx=cnt;
            ans.clear();
            ans.push_back(root->val);
        } 
        else if(cnt==mx) ans.push_back(root->val);
        prev=root;
        dfs(root->right,ans,prev);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        mx=0;
        cnt=0;
        vector<int> ans;
        TreeNode* prev=NULL;
        dfs(root,ans,prev);
        return ans;
    }
};