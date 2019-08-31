class Solution
{
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int distance = 0;
        dfs(root, distance);
        return distance;
    }
    
    /**
     * distance 记录以root为根的子树的最大直径，返回树的高度
    */
    int dfs(TreeNode *root, int &distance)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left, distance);
        int right = dfs(root->right, distance);
        distance = max(left + right, distance);
        return max(left, right) + 1;
    }
};