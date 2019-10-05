//dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;        
    }
    void helper(TreeNode* root,int level,vector<int>& res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
    }
};


//dfs

class Solution {
public:
      
    void dfs(TreeNode* root, int & pre, int cur,vector<int>& ans){
        if(root == nullptr)
            return;
        if(cur > pre){
            ans.push_back(root->val);
            pre++;
        }
        dfs(root->right, pre, cur + 1,ans);
        dfs(root->left, pre, cur + 1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int pre = 0;
        int cur = 1;
        vector<int> ans;
        dfs(root, pre , cur, ans);
        return ans;
    }
};

//bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.back()->val);
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* t=q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }           
        }
        return res;
    }
};

