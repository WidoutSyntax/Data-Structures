class Solution {
public:
    int diameter(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int left = diameter(root->left, res);
        int right = diameter(root->right, res);

        int temp = 1 + max(left, right);
        res = max(res, left + right);
        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        diameter(root, res);
        return res;
    }
};