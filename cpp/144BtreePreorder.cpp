class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        vector<int> ans;
        if(root == NULL) return {};
        st.push(p);
        while(!st.empty()){
            p = st.top();
            ans.push_back(p->val);
            st.pop();
            if(p->right)
                st.push(p->right);
            if(p->left)
                st.push(p->left);
                
        }
        return ans;
    }
};