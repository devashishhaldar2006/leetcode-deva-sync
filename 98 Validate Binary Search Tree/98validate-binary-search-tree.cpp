class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> ans;
        while (st.size() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                node = temp->right;
            }
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> v=inorderTraversal(root);
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};