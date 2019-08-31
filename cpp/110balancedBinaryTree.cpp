class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int d = abs(depth(root->left)-depth(root->right)); //当前节点的左右子树的高度差
        
        return (d<=1) && (isBalanced(root->left)) && (isBalanced(root->right)); //one false , all false
    }
    
    // 求解二叉树深度（104题）
    int depth(TreeNode* node)
    {
        if(node ==NULL) return 0;
        return max( depth(node->left), depth(node->right) )+1;
    }
    
};

class Solution {
public:
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return flag;
    }
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        else{
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            if(abs(left - right) > 1)
                flag = false;
            return max(left,right)+1;
        }
    }
};