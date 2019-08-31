/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        queue<TreeNode*> q;
        TreeNode* p;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double tmp = 0;
            
            for(int i = 0; i < size; i++){               
                p = q.front();
                tmp += double(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                q.pop();
            }
            avg.push_back(tmp/size);
        }
        return avg;
    }
};