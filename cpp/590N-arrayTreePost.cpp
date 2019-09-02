//recursion 220ms
class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        f(root);
        return ans;
    
        
    }
    void f(Node* root){
        if(!root) return;
        for(auto node : root->children)
            f(node);
        ans.push_back(root->val);
    }
};

//iteration  208ms
class Solution {
public:
    vector<int> postorder(Node* root) {
        
        stack<Node*> s;
        vector<int> res; 
        if(root==NULL) return res;
        s.push(root);
        while(!s.empty())
        {
            Node* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            for(int i=0;i<temp->children.size();i++) s.push(temp->children[i]);
        }
        reverse(begin(res),end(res)); 
        return res;
    }
};