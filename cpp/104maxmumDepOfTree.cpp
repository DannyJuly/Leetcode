
//BFS using queue
class Solution {
public:
    int maxDepth(TreeNode* root) {
        deque<TreeNode*> q;
        TreeNode* p;
        if(!root) return 0;
        q.push_back(root);
        int deep = 0;
        while(!q.empty()){
            deep++;
            int amo = q.size();
            for(int i = 0; i< amo ; i++){
                p = q.front();
                q.pop_front();
                if(p->left)
                    q.push_back(p->left);
                if(p->right){
                    q.push_back(p->right);
                }              
            }
        }
        return deep;
    }
};

//recursion  DFS

int maxDepth(TreeNode* root) {
    if(!root)return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return L>R?L+1:R+1;
}

//recursion using stack  DFS
int maxDepth(TreeNode* root) {
    if(!root)return 0;
    stack<pair<TreeNode*,int>>s;
    TreeNode* p = root;
    int MaxDeep = 0;
    int Deep = 0;
    while(!s.empty()||p)  //s is empty when at the top of the tree while p->right might not be empty.
    {
        while(p)
        {
            s.push(pair<TreeNode*,int>(p,Deep+1));
            Deep++;
            p = p->left;
        }
        p = s.top().first;
        Deep = s.top().second;
        if(MaxDeep<Deep)MaxDeep = Deep;
        s.pop();
        p = p->right;
    }
    return MaxDeep;
}

