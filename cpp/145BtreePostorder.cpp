//4ms  1 set and 1 stack 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> path;
        unordered_set<TreeNode *> _set; // 记录已经访问的结点

        if (root) path.push(root);

        while (!path.empty()) {
            auto node = path.top();

            bool leftVisited = true, rightVisited = true;

            // 左右结点判断先后顺序不能互换，因为需要先把右结点放进 stack中
            if (node->right && _set.find(node->right) == _set.end()) {
                rightVisited = false;
                path.push(node->right);
            }

            if (node->left && _set.find(node->left) == _set.end()) {
                leftVisited = false;
                path.push(node->left);
            }

            if (leftVisited && rightVisited) { // 左右结点已经访问过了，才可以访问当前结点
                ret.push_back(node->val);
                _set.insert(node);
                path.pop(); // 访问过了，从path中移除
            }
        }

        return ret;
    }
};

//1 vector and 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ans;
        if(root == nullptr)
            return ans;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            ans.push_back(node->val);
            if(node->left != nullptr)
                stack.push(node->left);
            if(node->right!= nullptr)
                stack.push(node->right);            
        }
        reverse(ans.begin(), ans.end());  
        return ans;
    }
};

