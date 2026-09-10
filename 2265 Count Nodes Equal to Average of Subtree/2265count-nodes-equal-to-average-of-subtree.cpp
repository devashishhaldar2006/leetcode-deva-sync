class Solution {
public:
    int cnt=0;
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        auto left=helper(root->left);
        auto right=helper(root->right);

        int sum=root->val+left.first + right.first;
        int node=1+left.second+right.second;
        if(root->val==sum/node) cnt++;
        return {sum,node};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        auto ans=helper(root);
        return cnt;
    }
};