class Solution {
public:
    int maxSum(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;

        int left = maxSum(root->left, res);
        int right = maxSum(root->right, res);

        if (root->left && root->right)
        {
            int temp = max(left, right) + root->val;
            res = max(res, left + right + root->val);
            return temp;
        }

        return (root->left ? root->val + left : root->val + right);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSum(root, res);
        return res;
    }
};