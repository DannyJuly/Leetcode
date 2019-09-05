//recursion
class Solution {
public:
    vector<int> ans;
    
    void inorder(TreeNode* root){
        if(root != NULL)
        {
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

//inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        vector<int> ans;
        TreeNode* t = root;
        while(t || !s.empty()){
            while(t){  //遍历到最左边的叶结点
                s.push(*t);
                t = t->left;
            }
            ans.push_back(s.top().val);
            t = s.top().right;
            s.pop();
            
        }
        return ans;
    }
};

