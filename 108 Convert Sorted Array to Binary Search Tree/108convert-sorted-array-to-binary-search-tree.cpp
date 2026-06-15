class Solution {
public:
    TreeNode* helper(int lo,int hi,vector<int>& nums){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(lo,mid-1,nums);
        root->right=helper(mid+1,hi,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(0,n-1,nums);
    }
};