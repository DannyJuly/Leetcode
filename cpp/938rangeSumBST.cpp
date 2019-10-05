class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
	if(!root)
		return 0;
	int left=rangeSumBST(root->left,L,R);
	int right=rangeSumBST(root->right,L,R);
	return (root->val<=R&&root->val>=L)?(left+right+root->val):(left+right);

	}
};

class Solution {
public:
    int ans = 0;
    void traverseTree(TreeNode* root, int L, int R){
        if(root == nullptr) return;
        if(root->val >= L && root->val <= R)
            ans += root->val;
        traverseTree(root->left, L, R);
        traverseTree(root->right, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        traverseTree(root, L, R);
        return ans;
    }
};