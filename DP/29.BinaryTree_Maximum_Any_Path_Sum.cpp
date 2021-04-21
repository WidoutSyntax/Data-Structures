class Solution {
public:
    int maxSum(TreeNode *root, int &res)
    {
        if(root == NULL)
            return 0;
        
        int left = maxSum(root->left, res);
        int right = maxSum(root->right, res);
        
        int temp = max(max(left, right) + root->val, root->val);
        int ans = max(temp, left + right + root->val);
        res = max(res, ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSum(root, res);
        return res;
    }
};