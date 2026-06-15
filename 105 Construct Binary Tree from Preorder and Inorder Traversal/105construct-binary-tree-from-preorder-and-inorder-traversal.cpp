class Solution {
public:
    TreeNode* build(vector<int>& preorder,int preLo,int preHi, vector<int>& inorder,int inLo,int inHi){
        if(preLo>preHi) return NULL;
        TreeNode* root=new TreeNode(preorder[preLo]);
        if(preLo==preHi) return root;
        int i=inLo;
        while(i<=inHi){
            if(inorder[i]==preorder[preLo]) break;
            i++;
        }
        int leftCount=i-inLo;
        int rightCount=inHi-i;
        root->left=build(preorder,preLo+1,preLo+leftCount,inorder,inLo,i-1);
        root->right=build(preorder,preLo+leftCount+1,preHi,inorder,i+1,inHi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};