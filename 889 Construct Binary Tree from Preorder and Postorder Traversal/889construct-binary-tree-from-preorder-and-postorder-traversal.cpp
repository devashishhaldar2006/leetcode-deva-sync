
class Solution {
public:
    TreeNode* build(vector<int>& pre,int preLo,int preHi, vector<int>& post,int postLo,int postHi){
        if(preLo>preHi) return NULL;
        TreeNode* root=new TreeNode(pre[preLo]);
        if(preLo==preHi) return root;
        int leftNode=pre[preLo+1];
        int i=0;
        while(i<=postHi-1){
            if(leftNode==post[i]) break;
            i++;
        }
        int leftCount=i-postLo+1;
        root->left=build(pre,preLo+1,preLo+leftCount,post,postLo,i);
        root->right=build(pre,preLo+leftCount+1,preHi,post,i+1,postHi);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return build(pre,0,n-1,post,0,n-1);
    }
};