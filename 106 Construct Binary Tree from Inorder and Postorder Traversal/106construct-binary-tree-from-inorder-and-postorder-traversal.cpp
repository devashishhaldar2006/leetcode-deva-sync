
class Solution {
public:
    TreeNode* build(vector<int>& postorder,int postlo,int posthi, vector<int>& inorder,int inlo,int inhi) {
        if(postlo>posthi) return NULL;
        TreeNode* root=new TreeNode(postorder[posthi]);
        if(postlo==posthi) return root;
        int i=inlo;
        while(i<=inhi){
            if(inorder[i]==postorder[posthi]) break;
            i++;
        }
        int leftCount=i-inlo;
        int rightCount=inhi-i;
        root->left=build(postorder,postlo,postlo+leftCount-1,inorder,inlo,i-1);
        root->right=build(postorder,postlo+leftCount,posthi-1,inorder,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return build(postorder,0,n-1,inorder,0,n-1);
    }
};