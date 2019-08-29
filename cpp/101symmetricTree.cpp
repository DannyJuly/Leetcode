//https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode/

//recursively 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
    bool isMirror(TreeNode *t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        return(t1->val == t2->val) && isMirror(t1->left,t2->right) 
            && isMirror(t1->right,t2->left);
    }
};

//iteration
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};



class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //如果是空的，则一定对称
        if(root == nullptr)
            return true;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        
        while(nodes.size()>0)
        {
            vector<TreeNode*> nodesNextLayer;
            //将存的左边一半节点与对应位置的右边一半节点比较
            for(int i = 0; i<nodes.size()/2;i++)
            {
                //如果对应位置的节点都不为空，比较值是否相等，并存入左右子节点
                if(nodes[i]!=nullptr&&nodes[nodes.size()-i-1]!=nullptr)
                {
                    if(nodes[i]->val == nodes[nodes.size()-i-1]->val)
                    {
                        nodesNextLayer.push_back(nodes[i]->left);
                        nodesNextLayer.push_back(nodes[i]->right);
                    }
                    else
                        return false;
                }
                //如果对应位置的节点都为空
                else if(nodes[i]==nullptr&&nodes[nodes.size()-i-1]==nullptr)
                    continue;
                else
                    return false;
            }
            //存储右半部分节点
            for(int i = nodes.size()/2; i<nodes.size();i++)
            {
                if(nodes[i]!=nullptr&&nodes[nodes.size()-i-1]!=nullptr)
                {
                    nodesNextLayer.push_back(nodes[i]->left);
                    nodesNextLayer.push_back(nodes[i]->right);
                }
                else
                    continue;
            }
            nodes = nodesNextLayer;
        }
        return true;
    }
};
