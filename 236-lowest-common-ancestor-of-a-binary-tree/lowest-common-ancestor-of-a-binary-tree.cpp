class Solution {
public:
    bool existsInTree(TreeNode* root, TreeNode* target) {
        if (!root)
            return false;
        if (root == target)
            return true;
        return existsInTree(root->left,
                            target) || existsInTree(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (!root)
            return NULL;

        if (root == p || root == q)
            return root;

        bool pLeft = existsInTree(root->left, p);
        bool qLeft = existsInTree(root->left, q);

        if (pLeft && qLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (!pLeft && !qLeft) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};